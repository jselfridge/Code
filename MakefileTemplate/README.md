GPP
===

Starting a new project can be cumbersome to generate a new 
makefile, properly link source and header files, and making 
sure files are not multiply defined.  This directory contains 
a template that can be used to start a new code proejct.

The goal was to establish modularity, so functionality can be 
ported with a minimum number of custom revisions.  The structure 
defies common convention and does not include '/scr' or '/inc' 
directories which house code.  Rather, subdirectories with 
descriptive names contain '.cpp', '.h', and '.o' files that 
are named identically as the subdirectory.  The 'makefile' is 
automated and needs no revision, as long as the code is laid 
out as described.  This structure is desirable, because entire 
directories can be copied into other projects without changing 
and text within the 'makefile' or the copied directory.

There is still room for improvement within the 'makefile'.  Future 
versions may include libraries and/or pass command line options, 
at compile time.



