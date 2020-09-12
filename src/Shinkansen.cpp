#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>

#include "Shinkansen.h"
#include "Utils.h"


Shinkansen::Shinkansen(int port) 
{
  this->port = port;
  this->Initialize();
}



void Shinkansen::Initialize()
{
  int server_fd, client_socket;
  struct sockaddr_in address;
  int addrlen = sizeof(address);
  
  char const *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
  // Creating socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
  {
      perror("In socket");
      exit(EXIT_FAILURE);
  }
  

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons( this->port );
  
  // memset(address.sin_zero, '\0', sizeof address.sin_zero);
  
  
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
  {
      perror("In bind");
      exit(EXIT_FAILURE);
  }
  if (listen(server_fd, 10) < 0)
  {
      perror("In listen");
      exit(EXIT_FAILURE);
  }

  cout << "Server listening on port " << this->port << "..." << endl;

  while(1)
  {
      
      if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
      {
          perror("In accept");
          exit(EXIT_FAILURE);
      }
      
      char buffer[30000] = {0};
      read( client_socket , buffer, 30000);
      // here comes the parsing
      string request = Utils::ConvertToString(buffer, (sizeof(buffer) / sizeof(char)));
      string httpMethod = request.substr(0, request.find(" "));
      request.erase(0, httpMethod.length() + 1);

      string path = request.substr(0, request.find(" "));

      cout << "Method: " << httpMethod << " PATH: " << path << endl;

      write(client_socket , response , strlen(response));
      close(client_socket);
  }
}
