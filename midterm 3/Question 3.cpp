/*
 *  Write a function using the following structure and prototype.

struct Stats
{
    float avg;     //Average value of an integer array
    float median;  //Median value  of an integer array
    int   *mode;   //array containing the modes
    int   nModes;  //number of modes in the array
    int   maxFreq; //max frequency of modes
};

Stats *avgMedMode(int *,int); 

The function takes in an integer array and the size of the array.
Then returns a pointer to a structure containing the average, median
and mode.  You will then write a printStat() function that will print
the results contained in the stats structure.  I will input a small 
integer array to test this out so ask for how many inputs to fill the array, 
then the values to place into the array.  Make sure you delete the 
dynamic array creation for the mode when you exit the problem.

Note:  The array may have no modes, 1 mode or many modes.

 */

/* 
 * File:   Question 3.cpp
 * Author: rcc
 *
 * Created on April 23, 2018, 11:55 AM
 */
