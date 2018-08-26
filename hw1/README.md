---
 ### Name       : Ben Straub         
 ### Student ID : 830276423                
 ###  Class     :  CSC 2421           
 ###  Due Date  :  Aug, 25, 2018
---

               #  Read Me

---
## Description of the program
---

This program is a toy guessing game; The user inputs the number of integers they would like to
guess as well as the range of values. They then are prompted to submit a set of numbers to check against
a randomly generated set. They are given three chances.

---
##  Source files
---

Name:  main.cpp
    Main program.  This is the driver program and user interaction state machine; 
    prompts user for inputs and creates the GuessingGame object

Name:  GuessingGame.hpp
    Interface for a guessing game object.
    
Name: GuessingGame.cpp
    Implements the GuessingGame interface, provides test constructor that takes a random number seed.
    Also provides testing methods such as print.

Name: Util.hpp
    Interface for utility functions

Name: Util.cpp
    Implements utility functions for dealing with long arrays, including printing and sorting.

---   
## Status of program
---
   The program runs successfully.  
   
   The program was developed on kali linux (debian) using g++ 8.1.0-12 . It was 
   compiled, run, and tested on csegrid.ucdenver.pvt.

