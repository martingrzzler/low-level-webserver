#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
#include <streambuf>

using namespace std;



int main(int argc, char const *argv[])
{
  string route = "mountain.jpg";

  int startIndex = route.find(".");
  cout << "'" << route.substr(startIndex + 1, route.length() -1 )<< "'" << endl;
 
  return 0;
}
