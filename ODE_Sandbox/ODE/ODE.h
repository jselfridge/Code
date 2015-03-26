
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  ODE Demonstration Program
//  Justin M Selfridge
//  ODE.h
//  Header file for the ODE solver.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef _ODE_H
#define _ODE_H

// Standand include files
#include <stdio.h>
#include <math.h>

// Function prototypes
void ODE( float f(float, float), float* t, float* x, float h, float* epsilon );

#endif



