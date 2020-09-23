#include <iostream>

#include "Request.h"

using namespace std;


Request::Request() 
{
  
}

Request::Request(string httpMethod, string route) 
{
  this->httpMethod = httpMethod;
  this->route = route;
}

string Request::GetHttpMethod() 
{
  return this->httpMethod;
}

void Request::SetHttpMethod(string method) 
{
  this->httpMethod = method;
}

string Request::GetRoute() 
{
  return this->route;
}

void Request::SetRoute(string route) 
{
  this->route = route;
}

string Request::GetFileExtension() 
{ 
  string route = this->GetRoute();
  int startIndex = route.find(".");
  return route.substr(startIndex + 1, route.length() -1 );
}
