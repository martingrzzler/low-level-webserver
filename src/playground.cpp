#include <iostream>
#include <string>
#include <filesystem>

// namespace fs = std::filesystem;
using namespace std;


#define PORT 8080

int main(int argc, char const *argv[])
{
  // std::string path = "/home/martingrzzler/CODE/";
  //   for (const auto & entry : fs::directory_iterator(path))
  //       std::cout << entry.path() << std::endl;

  string s("this is a string");

  char const *c = "this is a string";

  cout << sizeof(s) << "and" << strlen(c) << endl;

  return 0;
}
