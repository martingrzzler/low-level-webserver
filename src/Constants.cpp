#include <iostream>
#include <string>
#include <map>

#include "Constants.h"

using namespace std;


const string Constants::GetContentTypeFromExt(string ext) 
{
  return CONTENT_TYPES.at(ext);
}
