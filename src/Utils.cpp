#include <iostream>
#include <string>
#include <string.h>

#include "Utils.h"

using namespace std;


string Utils::ConvertToString(char* a, int size) 
{
  int i; 
  string s = ""; 
  for (i = 0; i < size; i++) { 
      s = s + a[i]; 
  } 
  return s; 
}

