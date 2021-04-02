#include <sys/socket.h>
#include <iostream>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <unistd.h>

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

int startTransmition(const int sockCl)
{
	int buf;
	while(true)
	{
		int bitsGot = recv(sockCl, &buf, 4, NULL);
		if (bitsGot == 0)
			break;
		std::cout << buf << '\n';
	}
	exit(0);
	return 0;
}

int getReadyForConnections(const int sockServ)
{
	int sockCl;
	int child;
	sockaddr_in clientAddr;
	
	socklen_t sockLen = sizeof(clientAddr);
	
	while(true)
	{
		sockCl = accept(sockServ, (sockaddr*)&clientAddr, &sockLen);
		if ((child = fork()) == 0)
		{
			close(sockServ);
			startTransmition(sockCl);
			close(sockCl);
		}
		else
		{
			close(sockCl);
			int status;
			wait4(child, &status, WNOHANG, NULL);
		}
	}
	
	return 0;
}

int main()
{
	int sockServ;
	initServer(sockServ);
	getReadyForConnections(sockServ);
	
	return 0;
}