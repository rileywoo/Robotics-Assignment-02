#include <fstream>
#include <cmath>
#include <iostream>
#define SIZE 1000000
using namespace std;

int main() {
	ofstream primes;
	primes.open ("primes.txt");
	bool primesList[SIZE];
	fill_n(primesList, SIZE, true);
	//memset (primesList, true, sizeof(bool)*SIZE); (not idiomatic)

	int i, j = 2;
	for (i = 2; i < sqrt(SIZE); ++i) 
	{
		if (primesList[i] == true)
		{
			for (j = i*i; j < SIZE; j += i)
			{
				primesList[j] = false;
			}
		}
	}

	for (i = 2; i < SIZE; i++) 
	{
		if (primesList[i] == true) 
		{
			primes << i << std::endl;
		}
	}
	primes.close();
	return 0;
}
