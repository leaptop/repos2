#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <stdio.h>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

const unsigned int window_width = 512;
const unsigned int window_height = 512;
const unsigned int clustSize = 128;
const int N = 1 << 20;

GLuint* bufferID;
void initBuffers(GLuint*&);
void transformBuffers(GLuint*);
void outputBuffers(GLuint*);
GLuint genInitProg();
void initGL();

int main() {

	clock_t start = clock();
	for (int i = 0; i < 10; ++i)
	{
		initGL();
		bufferID = (GLuint*)calloc(2, sizeof(GLuint));
		initBuffers(bufferID);
		transformBuffers(bufferID);
		//outputBuffers(bufferID);

		glDeleteBuffers(2, bufferID);
		free(bufferID);
		glfwTerminate();
	}
	printf("\n%d", clock() - start);
	return 0;
}

void initGL() {
	GLFWwindow* window;
	if (!glfwInit()) {
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return;
	}
	glfwWindowHint(GLFW_VISIBLE, 0);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE,
		GLFW_OPENGL_COMPAT_PROFILE);
	window = glfwCreateWindow(window_width, window_height,
		"Template window", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. \n");
		getchar();
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return;
	}
	return;
}

void checkErrors(std::string desc) {
	GLenum e = glGetError();
	if (e != GL_NO_ERROR) {
		//fprintf(stderr, "OpenGL error in \"not matters\": %s (%d)\n", desc.c_str(), e);
		system("PAUSE");
		exit(20);
	}
}

void initBuffers(GLuint*& bufferID) {
	glGenBuffers(2, bufferID);

	glBindBuffer(GL_SHADER_STORAGE_BUFFER, bufferID[0]);
	glBufferData(GL_SHADER_STORAGE_BUFFER, N * sizeof(float), 0,
		GL_DYNAMIC_DRAW);

	glBindBuffer(GL_SHADER_STORAGE_BUFFER, bufferID[1]);
	glBufferData(GL_SHADER_STORAGE_BUFFER, N * sizeof(float), 0,
		GL_DYNAMIC_DRAW);

	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, bufferID[0]);
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, bufferID[1]);
	GLuint csInitID = genInitProg();
	glUseProgram(csInitID);
	glDispatchCompute(N / clustSize, 1, 1);
	glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT |
		GL_BUFFER_UPDATE_BARRIER_BIT);
	glDeleteProgram(csInitID);
}

GLuint genTransformProg();

void outputBuffers(GLuint* bufferID) {
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, bufferID[0]);
	float* data = (float*)glMapBuffer(GL_SHADER_STORAGE_BUFFER,
		GL_READ_ONLY);

	float* hdata = (float*)calloc(N, sizeof(float));
	memcpy(&hdata[0], data, sizeof(float) * N);
	glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);
	for (int i = 0; i < N; ++i)
		fprintf(stdout, "%g\t", hdata[i]);
}


GLuint genInitProg() {
	GLuint progHandle = glCreateProgram();
	GLuint cs = glCreateShader(GL_COMPUTE_SHADER);
	const char* cpSrc[] = {
   "#version 430\n",
   "layout (local_size_x = 128, local_size_y = 1, local_size_z = 1) in; \
layout(std430, binding = 0) buffer BufferA{float A[];};\
layout(std430, binding = 1) buffer BufferB{float B[];};\
void main() {\
 uint index = gl_GlobalInvocationID.x;\
 A[index]=float(index);\
 B[index]=2*float(index) - 1;\
}"
	};
	glShaderSource(cs, 2, cpSrc, NULL);
	glCompileShader(cs);
	glAttachShader(progHandle, cs);
	glLinkProgram(progHandle);

	return progHandle;
}

void transformBuffers(GLuint* bufferID) {
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, bufferID[0]);
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, bufferID[1]);
	GLuint csTransformID = genTransformProg();

	glUseProgram(csTransformID);
	glDispatchCompute(N / clustSize, 1, 1);
	glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT |
		GL_BUFFER_UPDATE_BARRIER_BIT);
	glDeleteProgram(csTransformID);
}

GLuint genTransformProg() {
	GLuint progHandle = glCreateProgram();
	GLuint cs = glCreateShader(GL_COMPUTE_SHADER);
	const char* cpSrc[] = {
   "#version 430\n",
   "layout (local_size_x = 128, local_size_y = 1, local_size_z = 1) in; \
layout(std430, binding = 0) buffer BufferA{float A[];};\
layout(std430, binding = 1) buffer BufferB{float B[];};\
void main() {\
 uint index = gl_GlobalInvocationID.x;\
 float alpha = 2.25;\
 A[index]=A[index] * alpha + B[index];\
}"
	};
	glShaderSource(cs, 2, cpSrc, NULL);
	glCompileShader(cs);
	glAttachShader(progHandle, cs);
	glLinkProgram(progHandle);

	return progHandle;
}
