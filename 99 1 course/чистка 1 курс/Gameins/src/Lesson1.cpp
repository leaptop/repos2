#include"stdafx.h"
#include<iostream>
#include<sstream>//allows us to have access to ostringstream
#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"

const char* APP_TITLE = "Introduction to modern OpenGL - Hello Triangle";
const int gWindowWidth = 800;
const int gWindowHeight = 600;
GLFWwindow* gWindow = NULL;
bool gFullscreen = false;

// Shaders
const GLchar* vertexShaderSrc = "#version 330 core\n"
"layout (location = 0) in vec3 pos;"
"void main()"
"{"
"   gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);"
"}";
const GLchar* fragmentShaderSrc =
"#version 330 core\n"
"out vec4 frag_color;"
"void main()"
"{"
"   frag_color = vec4(0.35f, 0.96f, 0.3f, 1.0f);"
";";

void glfw_onKey(GLFWwindow* window, int key, int scancode, int action, int mode);
void showFPS(GLFWwindow * window);
bool initOpenGl();

int main() {

	if (!initOpenGl()) {
		std::cerr << "GLFW initialization failed" << std::endl;
		return -1;
	}

	GLfloat vertices[] = {
		0.0f,   0.5f, 0.0f,//top// the third is z
		0.5f,  -0.5f, 0.0f,//right
		-0.5f, -0.5f, 0.0f//left

	};

	GLuint vbo, vao;

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(0);

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertexShaderSrc, NULL);
	glCompileShader(vs);

	GLint result;
	GLchar infoLog[512];
	glGetShaderiv(vs, GL_COMPILE_STATUS, &result);
	if (!result) {
		glGetShaderInfoLog(vs, sizeof(infoLog), NULL, infoLog);
		std::cout << "Error! Vertex shader failed to compile. " << infoLog << std::endl;
	}

	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragmentShaderSrc, NULL);
	glCompileShader(fs);

	glGetShaderiv(fs, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetShaderInfoLog(fs, sizeof(infoLog), NULL, infoLog);
		std::cout << "Error! Fragment shader failed to compile. " << infoLog << std::endl;
	}


	//Main loop
	while (!glfwWindowShouldClose(gWindow)) {
		showFPS(gWindow);
		glfwPollEvents();//querries a window for activities


		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);


		glfwSwapBuffers(gWindow);
	}

	glfwTerminate();
	return 0;
}
bool initOpenGl() {

	if (!glfwInit()) {
		std::cerr << "GLFW initialization failed" << std::endl;
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	if (gFullscreen)
	{
		GLFWmonitor* pMonitor = glfwGetPrimaryMonitor();
		const GLFWvidmode* pVmode = glfwGetVideoMode(pMonitor);
		if (pVmode != NULL)
		{
			gWindow = glfwCreateWindow(pVmode->width, pVmode->height, APP_TITLE, pMonitor, NULL);
		}
	}
	else
	{
		gWindow = glfwCreateWindow(gWindowWidth, gWindowHeight, APP_TITLE, NULL, NULL);
	}

	if (gWindow == NULL) {
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(gWindow);//glew gives me access to opengl functionality(to videocard)

	glfwSetKeyCallback(gWindow, glfw_onKey);

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		std::cerr << "GLEW initialization failed" << std::endl;
		return false;
	}
	glClearColor(0.23f, 0.38f, 0.47f, 1.0f);

	return true;
}

void glfw_onKey(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

void showFPS(GLFWwindow * window) {
	static double previousSeconds = 0.0;
	static int frameCount = 0;
	double elapsedSeconds;
	double currentSeconds = glfwGetTime();//returns number of seconds since GLFW started, as a double

	elapsedSeconds = currentSeconds - previousSeconds;

	//limit text update 4 times per second
	if (elapsedSeconds > 0.25) {
		previousSeconds = currentSeconds;
		double fps = (double)frameCount / elapsedSeconds;
		double msPerFrame = 1000.0 / fps;

		std::ostringstream outs;
		outs.precision(3);//a number of digits after the dot to show
		outs << std::fixed
			<< APP_TITLE << "  "
			<< "FPS: " << fps << "  "
			<< "Frame Time: " << msPerFrame << " (ms)";
		glfwSetWindowTitle(window, outs.str().c_str());

		frameCount = 0;
	}

	frameCount++;
}