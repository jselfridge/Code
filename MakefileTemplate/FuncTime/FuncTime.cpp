
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  GNU C++ Project Template
//  Justin M Selfridge
//  FuncTime.cpp
//  Sample source code: manipulates computer time
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "FuncTime.h"

void FuncTime(){
  cout << "Running FuncTime()" << endl;
  GetTime();
}

void GetTime(){

  // Local variables
  time_t timer;
  struct tm y2k;
  double seconds;

  // Year 200 values
  y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
  y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;

  // Current time
  time(&timer);

  // Difference in time
  seconds = difftime(timer,mktime(&y2k));

  // Output the result
  printf ("%.f seconds since January 1, 2000 in the current timezone", seconds);

}



