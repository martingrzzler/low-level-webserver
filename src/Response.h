#pragma once

#include <iostream>
using namespace std;

class Response
{
private:
  string contentType;
  string body;
  pair<int, string> statusCode;


public:
  Response();
  void SetContentType(string ct);
  void SetBody(string b);
  void SetStatusCode(pair<int, string>);
  string ToString();
};
