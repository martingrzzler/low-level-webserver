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

  ifstream f;
  string buffer;

  f.open("public/hello.html", ios::in); 
  f.seekg(0, ios::end);
  buffer.reserve(f.tellg());
  f.seekg(0, ios::beg);
  buffer.assign(istream_iterator<char>(f), istream_iterator<char>());
  cout << buffer << endl;

  // int size;
  // ifstream f;

  // f.open("public/hello.html", ios::in);
  // f.seekg(0, ios::end);
  // size = f.tellg();
  // f.seekg(0, ios::beg);
  // char buffer[size];
  // f.read(buffer, size);
  // f.close();

  // for (int i = 0; i < size; i++) {
  //   cout << buffer[i] << endl;
  // }


  // FILE* f;
  // long size;
  // char* buffer;

  // f = fopen("public/hello.html", "rb");
  // if( !f ) perror("blah.txt"),exit(1);

  // fseek( f , 0L , SEEK_END);
  // size = ftell( f );
  // rewind( f );

  // buffer = (char *) calloc( 1, size+1 );
  // if( !buffer ) fclose(f), fputs("memory alloc fails", stderr), exit(1);

  // if( 1 != fread( buffer , size, 1 , f) )
  //   fclose(f),free(buffer),fputs("entire read fails",stderr),exit(1);

  //   // print buffer
  //  for (int i = 0; i < size; i++) {
  //    cout << buffer[i] << endl;
  //  }

  // fclose(f);
  // free(buffer);

  return 0;
}
