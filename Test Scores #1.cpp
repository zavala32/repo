/* The program should display the sorted list of
 * scores and average with appropriate headings. Use 
 * pointer notation rather than array notation whenever 
 * possible.
 */

/* 
 * File:   Test Scores #1.cpp
 * Author: Nicolas Zavala
 * Created on March 7, 2018, 12:14 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

//Function prototypes
void arrSelectSort(double *, int);
void arrAvgScore(double *, int);


int main()

{

//Define variables
double *TestScores,
total = 0.0,
average;

int numTest,
count;

//Get the number of test scores you wish to average and put in order
cout << "How many test scores do you wish to enter?";
cin >> numTest;

//Dynamically allocate an array large enough to hold that many scores
TestScores = new double[numTest];

//Get the test scores
cout << "Enter the test scores below.\n";
for (count = 0; count < numTest; count++)

{
//Display score
cout << "Test Score " << (count + 1) << ": ";
cin >> TestScores[count];


}

// Input validation. Only numbers between 0-100
while (numTest<0)
{
cout << "You must enter a scores that non-negative" << endl;
cout << "Please enter again: ";
cin >> TestScores[count];

}

//Calculate the total test scores
for (count = 0; count < numTest; count++)

{
total += TestScores[count];

}
average = total / numTest;

//Dsiplay the results
cout << fixed << showpoint << setprecision(2);
cout << "The average of all the test score is " << average << endl;

//Free dynamically allocated memory
delete [] TestScores;
TestScores = 0; //make TestScores point to null

//Display the Test Scores in ascending order
cout << "The test scores, sorted in ascending order, are: \n";
system ("pause");

return 0;

}

//Ascending order selection sort

void arrSelectSort(double *arr, int size)

{
int startScan;
double minIndex;
double minElem;

for(startScan = 0; startScan < (size - 1); startScan++)
{
minIndex = startScan;
minElem = arr[startScan];
}
for(int index = startScan + 1; index < size; index++)
{
if (arr[index] < minElem)
{
minElem = arr[index];
minIndex = index;
}

}


void arrAvgScore (double *arr[], int size)

{
double total = 0;
int numTest;
for (int count = 0; count < numTest; count++)

{
total += numTest[count];
average = total / numTest;
}

}
}