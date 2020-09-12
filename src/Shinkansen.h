#pragma once
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>

#include "Request.h"

using namespace std;

class Shinkansen
{
private:
  int port; 
  int serverSocket;
  int clientSocket;
  struct sockaddr_in address;

  sockaddr_in AddressConfig();
  void Initialize();
  void Listen();
  Request ParseRequest();
  
public:
  Shinkansen(int port);
  
};
