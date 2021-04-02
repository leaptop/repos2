#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	int sock;
	
	sockaddr_in addr;
	
	int port = atoi(argv[1]);
	char *IP = argv[2]; 
	
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(IP);
	
	connect(sock, (sockaddr*)&addr, sizeof(addr));
	
	for (int i = 1; i <= 10; ++i)
	{
		sendto(sock, &i, 4, NULL, (sockaddr*)&addr, sizeof(addr));
		sleep(1);
	}
	
	close(sock);
	
	return 0;
}