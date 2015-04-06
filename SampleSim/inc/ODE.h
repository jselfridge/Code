
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


// Custom includes
#include "../../../Libraries/MatLib/MatLib.h"


// Equation K2 Constants
#define  C20        1.0 /     4.0
#define  C21        1.0 /     4.0

// Equation K3 Constants
#define  C30        3.0 /     8.0
#define  C31        3.0 /    32.0
#define  C32        9.0 /    32.0

// Equation K4 Constants
#define  C40       12.0 /    13.0
#define  C41     1932.0 /  2197.0
#define  C42   - 7200.0 /  2197.0
#define  C43     7296.0 /  2197.0

// Equation K5 Constants
#define  C51      439.0 /   216.0
#define  C52   -    8.0 /     1.0
#define  C53     3680.0 /   513.0
#define  C54   -  845.0 /  4104.0

// Equation K6 Constants
#define  C60        1.0 /     2.0
#define  C61   -    8.0 /    27.0
#define  C62        2.0 /     1.0
#define  C63   - 3544.0 /  2565.0
#define  C64     1859.0 /  4104.0
#define  C65   -   11.0 /    40.0

// Fourth Order Constants
#define   A1       25.0 /   216.0
#define   A3     1408.0 /  2565.0
#define   A4     2197.0 /  4104.0
#define   A5   -    1.0 /     5.0

// Fifth Order Constants
#define   B1       16.0 /   135.0
#define   B3     6656.0 / 12825.0
#define   B4    28561.0 / 56430.0
#define   B5   -    9.0 /    50.0
#define   B6        2.0 /    55.0


// Function prototypes
void ODE( matrix* f( double, matrix* ), double* t, matrix** X, double d, double* e );


#endif



