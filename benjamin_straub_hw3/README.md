---
 ### Name       : Ben Straub         
 ### Student ID : 830276423                
 ###  Class     :  CSC 2421           
 ###  Due Date  :  Sept, 13, 2018
---
# Vehicle recursion and iteration

---
## Description of the program
---

A peice of code that asks for iterative or recursive and whether to sort by make, model or year, and then returns 
the first Vehicle entry that matches.

---
##  Source files
---

Name:  main.cpp
    Main program.  This is the driver program and user interaction state machine; 
    prompts user for inputs on file location, asks for what field to sort on,
    what method, recursive or iterative, should be used and what value to look 
    for.

Name:  Vehicle.hpp
    Interface for Vehicle class; constant constructor, immutible data storage. Defines friend classes for
    stream <<, sorting, and binary search
    
Name: Vehicle.cpp
    Implements the vehicle class; iterative and recursive quick sort, and iterative and binary search. Also implementation for the stream operator

Name: FileHander.hpp
    Interface for dealing the the file io. 

Name: FileFunction.hpp
    Implementation of the file io. Takes a string and opens the file. Attempts to read in the values line by line, creates the object every three 
    getlines. If one of the lines cannot be read, the line is printed out and the code exits

---
## Test files
---

Name:  VehicleTest.cpp
    Tests the Vehicle functionality. Prints out the results of the basic functionality of the Vehicle
    including construction, sorting, and searching

Name:  FileHandlerTest.cpp
    Test the basic functionality of file io and prints the results
---   
## Status of program
---
   The program runs successfully. Input validation is done in FileHandler.cpp; 
   
   The program was developed on kali linux (debian) using g++ 8.1.0-12 . It was 
   compiled, run, and tested on csegrid.ucdenver.pvt.

---
## Note
---
   This program is up at https://github.com/kamaroyl/data-structures-
   Hopefully this is unique enough that you would be able to tell if it was ripped off.

