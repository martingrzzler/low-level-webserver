#pragma once 

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Constants
{
private:
  static const inline map<string, string> CONTENT_TYPES = {
    { "jpg", "image/jpeg" },
    { "html", "text/html" }
  };
public:
  static const string GetContentTypeFromExt(string ext); 
  Constants() = delete;
};
