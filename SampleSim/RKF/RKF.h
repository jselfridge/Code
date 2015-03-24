
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  SampleSim Program
//  Justin M Selfridge
//  RKF.h
//  Header file for the RKF ODE solver.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef _RKF_H
#define _RKF_H

// Standand include files
//#include <iostream>
#include <stdio.h>
#include <math.h>
//using namespace std;

// Function prototypes
void RKF(float f(float, float), float* t, float* x, float h, float* epsilon);

#endif



