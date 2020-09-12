#pragma once

#include <iostream>
using namespace std;

class Request
{
private:
  string httpMethod;
  string route;

public:
  Request();
  Request(string httpMethod, string route);
  string GetHttpMethod();
  void SetHttpMethod(string method);
  string GetRoute();
  void SetRoute(string route);
};
