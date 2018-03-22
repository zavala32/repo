/*
 * Write a program that uses a structure named MovieData to store 
 * the following information about a movie: 
 * Title
 * Director
 * Year Released
 * Running Time (in minutes) 
 * The program should create two MovieData variables, 
 * store values in their members,and pass each one, in turn, 
 * to a function that displays the information about the movie
 *  in a clearly formatted manner.
 */

/* 
 * File:   Movie Date.cpp
 * Author: Nicolas Zavala
 *
 * Created on March 22, 2018, 11:56 AM
 */

#include <iostream>
#include <iostream>
#include <string>

using namespace std;

struct MovieData {
string Title;
string Director;
unsigned short YearReleased;
unsigned short RunningTime;
};

void print(MovieData &md) {
cout << "Title: " << md.Title << endl
<< "Director: " << md.Director << endl
<< "Year Released: " << md.YearReleased << endl
<< "Running Time: " << md.RunningTime << " minutes" << endl;
}

int main() {
MovieData movFirst, movSecond;
movFirst.Title = "Starship Troopers";
movFirst.Director = "Paul Verhoeven";
movFirst.YearReleased = 1997;
movFirst.RunningTime = 129;
movSecond.Title = "Alien vs. Predator";
movSecond.Director = "Paul W. S. Anderson";
movSecond.YearReleased = 2004;
movSecond.RunningTime = 108;
cout << endl;
print(movFirst);
cout << endl;
print(movSecond);
cout << endl;
return 0;
}