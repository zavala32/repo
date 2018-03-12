/*
 Write a function that dynamically allocates an array of integers. The function should
accept an integer argument indicating the number of elements to allocate. The function
should return a pointer to the array.
 */

/* 
 * File:   9.1.cpp
 * Author: Nicolas Zavala
 *
 * Created on March 12, 2018, 11:33 AM
 */
#include <iostream>
int* allocateArray(int n);
int main()
{
        int x;
        std::cin >> x ;
        int* a = allocateArray(x);
        // do something with a maybe;
        delete[] a;
}
 
 
int* allocateArray(int n)
{
        int* a = NULL;   
        a = new int[n];  // Allocate n ints and save ptr in a.
 
        for (int i=0; i<n; i++) 
        {
          a[i] = 0; // Initialize all elements to zero.
        }
 
        return a;
}
