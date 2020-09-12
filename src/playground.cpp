#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;


#define PORT 8080

int main(int argc, char const *argv[])
{
  std::string path = "/home/martingrzzler/CODE/";
    for (const auto & entry : fs::directory_iterator(path))
        std::cout << entry.path() << std::endl;
  return 0;
}
