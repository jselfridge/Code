
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  SampleSim.h
//  Justin M Selfridge
//  Main header file for the sample simulation code
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef _SAMPLESIM_H
#define _SAMPLESIM_H


// Standard include files
#include <stdio.h>


// Custom header declarations
#include "../inc/ODE.h"


//  Library headers
#include "../../../Libraries/MatLib/MatLib.h"
#include "../../../Libraries/RotLib/RotLib.h"


// Function prototypes
matrix* Deriv ( double t, matrix* x );
matrix* Ctrl  ( double t );
//matrix* Ref   ( double t );
matrix* Dist  ( double t );


// Global prototypes
int      step;
matrix*  time;
matrix*  state;
matrix*  ctrl;
//matrix*  ref;
matrix*  dist;
matrix* plot;
matrix* simerr;


// Defines
#define DUR 20.0
#define DT  0.01
#define T0  0.0
#define STEPS (int)(DUR/DT)
#define N 6
#define M 3
#define KX 1.0
#define KY 1.0
#define KZ 1.0
#define CX 2.0
#define CY 1.0
#define CZ 0.5
#define MASS  1.0


#endif



