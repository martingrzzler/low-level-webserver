#include <iostream>
#include <sstream>

#include "Response.h"

using namespace std;


Response::Response() 
{
  
}

void Response::SetContentType(string contentType) 
{
  this->contentType = contentType;
}

void Response::SetContentLength(size_t contentLength) 
{
  this->contentLength = contentLength;
}

void Response::SetBody(string body) 
{
  this->body = body;
}

void Response::SetStatusCode(pair<int, string> statusCode) 
{
  this->statusCode = statusCode;
}

char const* Response::ToByteArray() 
{
  stringstream ss;
  ss << "HTTP/1.1 " << this->statusCode.first << " " << this->statusCode.second << endl
  << "Content-Type: " << this->contentType << "Content-Length: " << this->contentLength << endl << endl << this->body << endl;

  char const* value = "";
  return value;
}



