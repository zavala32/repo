/*
* Factor an input integer into it's prime numbers.  Create a 
* structure to hold the array of prime numbers.  Any number between
* [2,10000] where n is not a prime > 100 will be a valid number to
* check for prime factors.

struct Prime{
	unsigned char prime;
	unsigned char power;
};
struct Primes{
	Prime *prime;
	unsigned char nPrimes;
};
Output the number and it's primes -> 120 = 2^3*3^1*5^1
So create a function 
Primes *factor(int);-> Input an integer, return all prime factors
void prntPrm(Primes *); -> Output all prime factors
 */

/* 
 * File:   Question 7.cpp
 * Author: rcc
 *
 * Created on April 23, 2018, 12:04 PM
 */

