
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
matrix* derivative ( double t, matrix* x );

#endif



