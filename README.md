# SYSC4805
SYSC4805 Snow Remover 

## File Setup
The executable code that we used for our presentation is based in the *Driver* directory.

The *LineDetector*, *Motors*, and *TOF* directories were all used for preliminary unit tests of the devices to ensure they were accurately working before integration began.

## Driver
The *Driver* directory contains a series of .cpp and .h files which contain our executable classes to handle each component individually.
The *Driver.ino* file is our executable file that integrates the classes to be used in the final state machine of our system.
The *LineDetector* and *TOF* classes did not end up being used in our final testing as they had failing issues that could not be utilized but remain in the *Driver* directory for knowledge 
