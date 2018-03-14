/*
 *Write a function that accepts an int array and the array’s size as arguments.
 *The function should create a copy of the array, except that the element 
 *values should be reversed in the copy. The function should return a pointer
 *to the new array. Demonstrate the function in a complete program.
 */

/* 
 * File:   9.10.cpp
 * Author: Nicolas Zavala 
 *
 * Created on March 14, 2018, 12:04 PM
 */

#include <iostream>  //Input/Output Objects

using namespace std; //Name-space used in the System Library

/*
//User Libraries
 
//Global Constants
 
//Function prototypes

//Reverses order of array elements
 * 
 */
int *revArr(int [], const int);
int main(int argc, char** argv) {
const int SIZE = 5;
    int numbers[SIZE] = { 1, 2, 3, 4, 5 };
    int* ptr = nullptr;
    
    //Input values
    ptr = revArr(numbers, SIZE);
   //Process values -> Map inputs to Outputs 
    for (int i = 0; i < SIZE; i++){
        cout << *(ptr + i) << " ";
    }
    
    //Display Output
    
    
    //Exit Program
    return 0;
}
int *revArr(int arr[], const int size){
    int j = size - 1, *copyPtr = new int [size];
    
    for (int i = 0; i < size; i++){
        *(copyPtr + i) = arr[j];
        j--;
    }
    
    return copyPtr;
}
   

