/* 
   Reads sparse matrix in octave format
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <armadillo>

using namespace std;
using namespace arma;

int main (int argc, char **argv) 
{
  int Row, Col;
  double Val;
  SpMat<double> spmat_a; 
  spmat_a.set_size(20000, 20000);                                                                                                                              
  //IntSp.load(argv[1], arma_binary); this does not work !
  ifstream input (argv[1]);
  string lineData;

  while(getline(input, lineData))
  {
    stringstream lineStream(lineData);

    lineStream >> Row;
    lineStream >> Col;
    lineStream >> Val;

    spmat_a(Row-1, Col-1) = Val;  
  }
  cout << "spmat.n_cols = " << spmat_a.n_cols << endl;
  cout << "spmat.n_rows = " << spmat_a.n_rows << endl;
  spmat_a.print("spmat_a:");

  vec vec_x(20000);  vec_x.fill(123.0);

  vec vec_b = spmat_a * vec_x; 

  return 0;
}
