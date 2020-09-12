#pragma once

#include <iostream>
using namespace std;

class Response
{
private:
  string contentType;
  size_t contentLength;
  string body;
  pair<int, string> statusCode;


  void SetContentLength(size_t cl);

public:
  Response();
  void SetContentType(string ct);
  
  void SetBody(string b);
  void SetStatusCode(pair<int, string>);
  char const* ToByteArray();
};
