
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  GNU C++ Project Template
//  Justin M Selfridge
//  FuncMath.cpp
//  Sample source code: performs some math operations
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "FuncMath.h"

void FuncMath(){
  cout << "Running FuncMath()" << endl;
  cout << "Sum:  " << Sum(3,5) << endl;
  cout << "Pyt:  " << Pyt(3,4) << endl;
}

int Sum(int x, int y) {
  return (x+y);
}

float Pyt( float x, float y ) {
  float z = pow(x,2) + pow(y,2);
  return sqrt(z);
}



