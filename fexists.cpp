#include <iostream>
#include <fstream>

using namespace std;

bool fexists(const char *filename)
{
  ifstream ifile(filename);
  return (bool)ifile;
}

int main () {
  cout << fexists("filename") << endl;

  return 0;
}
