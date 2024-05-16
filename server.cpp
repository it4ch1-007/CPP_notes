#include <iostream>
#include <Windows.h>
#include <cstring> //This can give us the reequired functions like sizeof() and other core and standard c functions
#include <string>
//#include <arpa/inet.h>
#include <Winsock2.h>
//#include <netdb.h>
#include <windows.h>
//#include <>
//#include <sys/socket.h>
#include <sys/types.h>
//#include <unistd.h>
//#include <bits/stdc++.h>


//port number will be argv

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cerr << "Usage : server.exe <port_number>";
		return -1;
	}

	auto& portNum = argv[1];
	const unsigned int limit_connections = 10;

	addrinfo hints, * res, * p;
	memset(&hints, 0, sizeof(hints));

	//setting the specifics of the socket
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	int gAddRes = getaddrinfo(NULL, portNum, &hints, &res);
	if (gAddREs != 0) {
		std::cerr << gai_strerror(aAddRes) << std::endl;
		return -2;
	}

	std::cout << "Detecting Addresses" << std::endl;
	unsigned int numOfAddr = 0;
	char ipStr[INET6_ADDRSTRLEN];

	//Now ask the user to bind to a program
	for (p = res; p != NULL; p -> ai_next) {
		//The addressinfo can be understood as a linked list that can be used to iterate over the ip addresses of all the clients using the pointer iterator
		void* addr;
		std::string ipVer;
		//address is checked and stored in this variable as the type of the address given

		if (p->ai_family == AF_INET) { //This checks the family of the given socket
			ipVer = "IPv4";
			sockaddr_in* ipv4 = reinterpret_cast<sockaddr_in*>(p->ai_addr); //This gives us the required address of the socket and casting its types and data limit 
			addr = &(ipv4->sin_addr);
			++numOfAddr;//This variable will be checked afterwards to see if the linked list specified has any ip address or not.
		}

		else {
			ipVer = "IPv6";
			sockaddr_in* ipv6 = reinterpret_cast<sockaddr_in6*>(p->ai_addr);
			addr = &(ipv6->sin_addr);
			++numOfAddr;
		}

		//Till now the ip address are in the vinary form due to the type addr and thus these address in the bianry form have to be finverted into the text readable format

		inet_ntop(p->ai_family, addr, ipStr, sizeof(ipStr));
		std::cout << "(" << numOfAddr << ")" << ipVer << " : " << ipStr << std::endl;

	}

	if (!numOfAddr) {
		std::cerr << "There are no clients available" << std::endl;
		return -3;
	}

	//prompting the user to enter the address of the client hen wants to connect to 
	std::cout << "Enter the number of hosts to connect: " << std::endl;
	unsigned int choice = 0; ///unsigned to specify that the choice should be a positive non zero integer
	bool madeChoice = false; //Has the user chosen to connect or not 

	do {
		std::cin >> choice;
		if (choice > (numOfAddr + 1) || choice < 1) {
			madeChoice = false;
			std::cout << "Wrong Choice" << std::endl;
		}
		else
			madeChoice = true;
	} while (madeChoice);

	p = res; //res is the pointer that holds the resource details of the current socket and p is the pointer tht will point to the details of the next socket

	//creating a new socket for every connection
	int sockFD = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
	if (sockFD == -1) {
		std::cerr << "Could not create the socket";
		freeaddrinfo(res); //This is just like the free function that frees the pointer to the previous address
		return -4;
	}


	//binding the address to the socket created
	int bindR = bind(sockFD, p->ai_addr, p->ai_addrlen);
	if (bindR == -1) {
		std::cerr << "Could not bind the socket to the address" << std::endl;
		close(sockFD);
		freeaddrinfo(res);
		return -5;
	}

	//start listening the connections on our socket
	int listenR = listen(sockFD, limit_connections); //the maximum no of connections to listen to 
	if (listenR == -1) {
		std::cerr << "Error while listening to the socket connections";


		//make sure to close and free the socket bind
		close(sockFD);
		freeaddrinfo(res);
		return -6;
	}

	sockaddr_storage client_addr;
	socklen_t client_addr_size = sizeof(client_addr);


	const std::string_response = "Hello World";


	while (1) {
		int newFD = accept(sockFD, (sockaddr*)&client_addr, &client_addr_size);

		if (newFD == -1) {
			std::cerr << "Not able to listen to any functions";
			continue; //here we will not return the main functions as it is possible to have a delay between the connection of the host and the server

		}

		auto bytes_sent = send(newFD, response.data(), response.length(), 0); //using the standard functions of the 
		close(newFD); //This will close the socket and the connection
	}

	close(sockFD);
	freeaddrinfo(res);

	return 0;
}