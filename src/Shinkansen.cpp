#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Shinkansen.h"
#include "Utils.h"
#include "Request.h"
#include "Response.h"
#include "Constants.h"

using namespace std;

Shinkansen::Shinkansen(int port)
{
  this->port = port;
  this->address = this->AddressConfig();
  this->Initialize();
}

void Shinkansen::Initialize()
{
  // Creating socket file descriptor
  if ((this->serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
  {
    perror("In socket");
    exit(EXIT_FAILURE);
  }

  if (bind(this->serverSocket, (struct sockaddr *)&address, sizeof(this->address)) < 0)
  {
    perror("In bind");
    exit(EXIT_FAILURE);
  }
  if (listen(this->serverSocket, 10) < 0)
  {
    perror("In listen");
    exit(EXIT_FAILURE);
  }

  cout << "Server listening on port " << this->port << "..." << endl;
  this->Listen();
}

void Shinkansen::Listen()
{

  while (1)
  {
    int addrlen = sizeof(this->address);

    if ((this->clientSocket = accept(this->serverSocket, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
      perror("In accept");
      exit(EXIT_FAILURE);
    }

    // form request object
    Request request = this->ParseRequest();

    this->SendFile(request);
  }
}

void Shinkansen::SendFile(Request req)
{
  Response *res = new Response();
  ifstream in;
  pair<int, string> statusCode;
  stringstream body;

  // return homepage
  if (req.GetRoute() == "/" || req.GetRoute() == "")
  {
    in.open("public/index.html", ios::binary);
    if (in.is_open())
    {
      statusCode.first = 200;
      statusCode.second = "Ok";
      res->SetStatusCode(statusCode);
      res->SetContentType("text/html");

      // read data and assign to body
      body << in.rdbuf();
      res->SetBody(body.str());

      this->SendRaw(*res);
      delete res;
      return; 
    }
  }
  // try to find file
  in.open("public" + req.GetRoute(), ios::binary);

  if (!in.is_open())
  {

    statusCode.first = 404;
    statusCode.second = "Not Found";
    res->SetStatusCode(statusCode);
    res->SetContentType("text/html");
    res->SetBody("<h1>404 Not Found</h1>\n<p>Please check your request url!</p>");
    this->SendRaw(*res);
    delete res;
    return;
  }
  // response config

  statusCode.first = 200;
  statusCode.second = "Ok";
  res->SetStatusCode(statusCode);
  res->SetContentType(Constants::GetContentTypeFromExt(req.GetFileExtension()));

  // read data and assign to body
  body << in.rdbuf();
  res->SetBody(body.str());

  this->SendRaw(*res);
  delete res;
}

void Shinkansen::SendRaw(Response &res)
{
  string s = res.ToString();
  char rawResponse[s.length()];
  memcpy(rawResponse, s.c_str(), s.length());
  write(this->clientSocket, rawResponse, sizeof(rawResponse));
  close(this->clientSocket);
}

Request Shinkansen::ParseRequest()
{
  char buffer[30000] = {0};
  read(this->clientSocket, buffer, 30000);
  // here comes the parsing
  string request = Utils::ConvertToString(buffer, (sizeof(buffer) / sizeof(char)));
  string httpMethod = request.substr(0, request.find(" "));
  request.erase(0, httpMethod.length() + 1);
  string route = request.substr(0, request.find(" "));

  Request obj(httpMethod, route);
  return obj;
}

sockaddr_in Shinkansen::AddressConfig()
{
  struct sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(this->port);

  // memset(address.sin_zero, '\0', sizeof address.sin_zero);
  return address;
}
