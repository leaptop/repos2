#include <sys/socket.h>
#include <iostream>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

int initServer(int &sockServ_TCP, int &sockServ_UDP)
{
	sockaddr_in servAddr_TCP, servAddr_UDP;
	
	socklen_t sockLen = sizeof(servAddr_TCP);
	
	sockServ_TCP = socket(AF_INET, SOCK_STREAM, 0);
	sockServ_UDP = socket(AF_INET, SOCK_DGRAM, 0);
	
	servAddr_TCP.sin_family = AF_INET;
	servAddr_TCP.sin_port = 0;
	servAddr_TCP.sin_addr.s_addr = htonl(INADDR_ANY);
	
	bind(sockServ_TCP, (sockaddr*)&servAddr_TCP, sockLen);
	
	getsockname(sockServ_TCP, (sockaddr*)&servAddr_TCP, &sockLen);
	std::cout << "Port: " << htons(servAddr_TCP.sin_port) << '\n';
	
	servAddr_UDP.sin_family = AF_INET;
	servAddr_UDP.sin_port = servAddr_TCP.sin_port;
	servAddr_UDP.sin_addr.s_addr = htonl(INADDR_ANY);
	
	bind(sockServ_UDP, (sockaddr*)&servAddr_UDP, sockLen);
	
	listen(sockServ_TCP, 4);
	
	return 0;
}

void startTransmition(int sockCl)
{
	int buf;
	while(true)
	{
		int bitsGot = recv(sockCl, &buf, 4, NULL);
		if (bitsGot <= 0)
			break;
		std::cout << buf << std::endl;
	}
	close(sockCl);
}

int getReadyForConnections(const int sockServ_TCP, const int sockServ_UDP)
{
	fd_set socketsCur, socketsReady;
	
	FD_ZERO(&socketsCur);
	FD_SET(sockServ_TCP, &socketsCur);
	FD_SET(sockServ_UDP, &socketsCur);
	
	while(true)
	{
		socketsReady = socketsCur;
		
		select(FD_SETSIZE, &socketsReady, NULL, NULL, NULL);
		
		for (int i = 0; i < FD_SETSIZE; ++i)
			if (FD_ISSET(i, &socketsReady))
			{
				if (i == sockServ_TCP)
				{
					sockaddr_in clientAddr;
					socklen_t sockLen = sizeof(clientAddr);
					int sockCl = accept(sockServ_TCP, (sockaddr*)&clientAddr, &sockLen);
					
					FD_SET(sockCl, &socketsCur);
				}
				else if (i == sockServ_UDP)
				{
					int buf;
					
					int bitsGot = recvfrom(i, &buf, 4, NULL, NULL, NULL);
					std::cout << buf << std::endl;
				}
				else
				{
					startTransmition(i);
					FD_CLR(i, &socketsCur);
				}
			}
		
		
		
		
	}
	
	return 0;
}

int main()
{
	int sockServ_TCP, sockServ_UDP;
	initServer(sockServ_TCP, sockServ_UDP);
	getReadyForConnections(sockServ_TCP, sockServ_UDP);
	
	return 0;
}