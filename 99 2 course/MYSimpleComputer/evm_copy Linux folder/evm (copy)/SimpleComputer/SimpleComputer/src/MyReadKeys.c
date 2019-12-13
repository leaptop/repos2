#include "MyReadKeys.h"

int rk_readkey(enum Key *KEY) {
	struct termios orig_options;
	char buf[16];
	int num_read;

	if (tcgetattr(STDIN_FILENO, &orig_options)) {
		return ERROR;
	}

	if (rk_mytermregime(0, 1, 0, 0, 0)) {
		return ERROR;
	}

	num_read = read(STDIN_FILENO, buf, 15);
	
	if (num_read < 0) {
		return ERROR;
	}

	buf[num_read] = '\0';

	if (strcmp(buf, "l") == 0) {
		*KEY = KEY_l;
	}
	else {
		if (strcmp(buf, "s") == 0) {
			*KEY = KEY_s;
		}
		else {
			if (strcmp(buf, "r") == 0) {
				*KEY = KEY_r;
			}
			else {
				if (strcmp(buf, "t") == 0) {
					*KEY = KEY_t;
				}
				else {
					if (strcmp(buf, "i") == 0) {
						*KEY = KEY_i;
					}
					else {
						if (strcmp(buf, "q") == 0) {
							*KEY = KEY_q;
						}
						else {
							if (strcmp(buf, "\n") == 0) {
								*KEY = KEY_enter;
							}
							else {
								if (strcmp(buf, "\033[15~") == 0) {
									*KEY = KEY_f5;
								}
								else {
									if (strcmp(buf, "\033[17~") == 0) {
										*KEY = KEY_f6;
									}
									else {
										if (strcmp(buf, "\033[A") == 0) {
											*KEY = KEY_up;
										}
										else {
											if (strcmp(buf, "\033[B") == 0) {
												*KEY = KEY_down;
											}
											else {
												if (strcmp(buf, "\033[C") == 0) {
													*KEY = KEY_right;
												}
												else {
													if (strcmp(buf, "\033[D") == 0) {
														*KEY = KEY_left;
													}
													else {
														*KEY = KEY_other;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	if (tcsetattr(STDIN_FILENO, TCSANOW, &orig_options)) {
		return ERROR;
	}

	return 0;
}

int rk_mytermsave() {
	struct termios options;
	FILE *file;

	if (tcgetattr(STDIN_FILENO, &options)) {
		return ERROR;
	}

	if ((file = fopen("termsettings", "wb")) == NULL) {
		return ERROR;
	}

	fwrite(&options, sizeof(options), 1, file);
	fclose(file);

	return 0;
}

int rk_mytermrestore() {
	struct termios options;
	FILE *file;

	if ((file = fopen("termsettings", "rb")) == NULL) {
		return ERROR;
	}

	if (fread(&options, sizeof(options), 1, file) == 0) {
		return ERROR;
	}

	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &options)) {
		return ERROR;
	}

	return 0;
}

int rk_mytermregime(int regime, int vtime, int vmin, int echo, int sigint) {
	struct termios options;

	if (tcgetattr(STDIN_FILENO, &options)) {
		return ERROR;
	}

	if (regime == 1) {
		options.c_lflag |= ICANON;
	}
	else {
		if (regime == 0) {
			options.c_lflag &= ~ICANON;

			options.c_cc[vtime] = vtime;
			options.c_cc[vmin] = vmin;

			if (echo == 1) {
				options.c_lflag |= echo;
			}
			else {
				if (echo == 0) {
					options.c_lflag &= ~echo;
				}
				else {
					return ERROR;
				}
			}

			if (sigint == 1) {
				options.c_lflag |= ISIG;
			}
			else {
				if (sigint == 0) {
					options.c_lflag &= ~ISIG;
				}
				else {
					return ERROR;
				}
			}
		}
		else {
			return ERROR;
		}
	}

	if (tcsetattr(STDIN_FILENO, TCSANOW, &options)) {
		return ERROR;
	}

	return 0;
}