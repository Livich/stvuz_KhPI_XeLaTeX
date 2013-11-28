#include "stdafx.h"
#include <winsock2.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include "..\..\..\lab1\sp_lab1\sp_lab1\matrix.cpp";
#pragma comment (lib, "ws2_32.lib") 

#ЛР, системное программирование
#Выполнил ст. гр. ИФ31-Г 
#Лиликович С.А.
#2013 год


void TheError(char* message){
	std::cout<<"ERROR: "<<message<<", GetLastError="<<GetLastError()<<", WSAGetLastError="<<WSAGetLastError()<<". \n";
}

const int COUNT_OF_MATRICES=2;
int _tmain(int argc, _TCHAR* argv[])
{

	matrix*matrices = new matrix[COUNT_OF_MATRICES];

	for(int i=0;i<COUNT_OF_MATRICES;i++){
		int W, H;
		std::cout<<"Enter matrix "<<i+1<<" width and height: \n";
		std::cin>>W>>H;
		matrices[i] = *(new matrix(W,H));
		for(int y=1;y<H+1;y++){
			std::cout<<"Enter row "<<y<<" of matrix "<<i+1<<":\n";
			for(int x=1;x<W+1;x++){
				float I = 0;
				std::cin>>I;
				matrices[i].setval(x,y,I);
			}
		}
		std::cout<<"Got matrix "<<i+1<<" of "<<COUNT_OF_MATRICES<<":\n";
		matrices[i].render();
		std::cout<<"\n";
	}

	std::cout<<"Got all matrices. Start client now.\n";
	system("pause");
	
	matrices[0].render(); std::cout<<"\n"; matrices[1].render(); std::cout<<"\n";
	//отправка данных
	WSADATA hWSAData;
	if(WSAStartup(0x0202,&hWSAData)!=0){
		TheError("WSAStartup failed");
		return 1;
	}
	SOCKET hSocket = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	struct sockaddr_in sockAddr;
	sockAddr.sin_family = AF_INET; sockAddr.sin_port = htons(27015); sockAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	if(sockAddr.sin_addr.S_un.S_addr==INADDR_NONE){
		TheError("Outer address invalid");
	}

	if(connect(hSocket,(struct sockaddr*)&sockAddr,sizeof(sockAddr))==-1){
		TheError("Connection failed");
		return 1;
	}
	std::string data[2]; data[0] = matrices[0].serialize(); data[1] = matrices[1].serialize();
	if(
		send(hSocket,data[0].c_str(),(data[0].length()+1)*sizeof(TCHAR),0)==SOCKET_ERROR||
		send(hSocket,data[1].c_str(),(data[1].length()+1)*sizeof(TCHAR),0)==SOCKET_ERROR){
		TheError("Send failed");
		return 1;
	}else{
		shutdown(hSocket, SD_SEND);
		std::cout<<"Data has been sent successfully: \n"<<data[0]<<"\n"<<data[1]<<"\n";
	}
	closesocket(hSocket);
	
	system("pause");
	WSACleanup();

return 0;
}

