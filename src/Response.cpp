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

void Response::SetBody(string body) 
{
  this->body = body;
}

void Response::SetStatusCode(pair<int, string> statusCode) 
{
  this->statusCode = statusCode;
}

string Response::ToString() 
{
  stringstream ss;
  ss << "HTTP/1.1 " << this->statusCode.first << " " << this->statusCode.second << endl
  << "Content-Type: " << this->contentType << endl << "Content-Length: " << this->body.length() << endl << endl << this->body;

  return ss.str();
}
