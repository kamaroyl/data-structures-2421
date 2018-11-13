---
 ### Name       : Ben Straub         
 ### Student ID : 830276423                
 ###  Class     :  CSC 2421           
 ###  Due Date  :  Nov, 07, 2018
---

               #  Read Me

---
## Description of the program
---
A hashtable implementation that reads from a file of new line delimited words, strips non-alpha words and stores them. A Driver that reads in a file to test, strips non alpha characters and splits by space, then checks the words in the hashtable. If the element is not in the table, then the word is printed. This works with the "check" file as well as the ful text of harry potter.
---
##  Source files
---

Name:  main.cpp
    Driver and UI - asks user for files paths for a dictionary and for a file to test. Returns the number of words in the dictionary, the words that are not in the dictionary and the count of words in the file under test.

Name: MyHashTable.hpp
    Interface for a hashtable and node. Hashtable is implemented using chaining. Has a fixed length of 1373. Hash function is djb2 
   
Name: MyHashTable.cpp
    Implementation details for the hashtable and Node. 

Name: StringUtil.hpp
    Interface for string functions for stripping non alpha characters, and transforming the strings to lowercase. 
    Uses the algorithms standard library.

Name: StringUtil.cpp
    Implementation of string manipulation
---
## Resource files
---

Name:  check.txt
    Minimum test of the functionality.

Name: Potter.txt
    Harry Potter as a text file

Name: dict.txt
    A dictionary file - new line delimited words
---   
## Status of program
---
   The program runs successfully.  
   
   The program was developed on kali linux (debian) using g++ 8.2.0-7 . It was 
   compiled, run, and tested on csegrid.ucdenver.pvt. The program also works with the harry potter text

---
## Note
---
   This program is up at https://github.com/kamaroyl/data-structures-hw1
   Hopefully this is unique enough that you would be able to tell if it was ripped off.

