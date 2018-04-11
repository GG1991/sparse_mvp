/*
   g++ -g parse_mat.cpp
   ./a.out data/A_20000.dat
 */
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{

  map<pair<int,int>, double> A_map;
  int Row, Col;
  double Val;
  ifstream input (argv[1]);
  string lineData;

  while(getline(input, lineData))
  {
    stringstream lineStream(lineData);

    lineStream >> Row;
    lineStream >> Col;
    lineStream >> Val;

    A_map[make_pair(Row, Col)] = Val;
  }

  return 0;
}
