#include <sys/socket.h>
#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t lock;
std::ofstream file;

int initServer(int &sockServ)
{
	sockaddr_in servAddr;
	
	socklen_t sockLen = sizeof(servAddr);
	
	sockServ = socket(AF_INET, SOCK_STREAM, 0);
	
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = 0;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	bind(sockServ, (sockaddr*)&servAddr, sockLen);
	
	getsockname(sockServ, (sockaddr*)&servAddr, &sockLen);
	std::cout << "Port: " << htons(servAddr.sin_port) << '\n';
	listen(sockServ, 3);
	
	return 0;
}

void* startTransmition(void *sockCl)
{
	pthread_mutex_lock(&lock);
	int buf;
	std::cout << *(int*)sockCl;
	while(true)
	{
		int bitsGot = recv(*(int*)sockCl, &buf, 4, NULL);
		if (bitsGot <= 0)
			break;
		file << buf << std::endl;
	}
	close(*(int*)sockCl);
	free(sockCl);
	pthread_mutex_unlock(&lock);
}

int getReadyForConnections(const int sockServ)
{
	int child;
	
	while(true)
	{
		sockaddr_in clientAddr;
		socklen_t sockLen = sizeof(clientAddr);
		int *sockCl = (int*)malloc(sizeof(int));
		*sockCl = accept(sockServ, (sockaddr*)&clientAddr, &sockLen);
		
		pthread_t thread;
		pthread_create(&thread, NULL, startTransmition, (void*) sockCl);
	}
	
	return 0;
}

int main()
{
	int sockServ;
	file.open("res.txt");
	pthread_mutex_init(&lock, NULL);
	initServer(sockServ);
	getReadyForConnections(sockServ);
	pthread_mutex_destroy(&lock);
	
	return 0;
}