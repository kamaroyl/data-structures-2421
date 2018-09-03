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

This code creates two sets of number from a file that contains two lines of space delimited integers
and shows the union and difference of the two.

---
##  Source files
---

Name:  main.cpp
    Main program.  This is the driver program and user interaction state machine; 
    prompts user for inputs and creates the ArrayBag objects

Name:  ArrayBag.h
    Interface for a guessing game object, provided by Pearson. Has additional friend functions
    
Name: ArrayBag.cpp
    Implements adding and removing objects from the Bag as well as finding the frequency of an object 
    in the bag

Name: SetFunction.hpp
    Interface for friend functions +, - and << for ArrayBags. Acts as a 'Set' such that deduplication 
    occurs after operation

Name: SetFunctions.cpp
    Implements the interface. Uses the functions from ArrayBag to implement + and -. All works in polynomial    time. Can be implemented to manipulate faster, but could it would require reimplementing ArrayBag

Name: FileFunction.hpp
    Interface for dealing the the file io. desribes a factory that takes a pointer to a string 
    representation of an integer array

Name: FileFunction.hpp
    Implementation of the file io. Takes a string pointer, creates an object and populates it with
    integers from the string. Corrects for stray characters and lets the user know where the 
    problem character is.

---
## Test files
---

Name:  ArrayBagTest.cpp
    Tests the ArrayBag functionality. Prints out the results of the basic functionality of the Array bag
    including construction, adding objects, removing objects and checking frequency

Name:  FileTest.cpp
    Test the basic functionality of file io and prints the results
---   
## Status of program
---
   The program runs successfully. Input validation is done in FileFunction.cpp; invalid input can be
   found in resource/badInput.txt
   
   The program was developed on kali linux (debian) using g++ 8.1.0-12 . It was 
   compiled, run, and tested on csegrid.ucdenver.pvt.

---
## Note
---
   This program is up at https://github.com/kamaroyl/data-structures-
   Hopefully this is unique enough that you would be able to tell if it was ripped off.

