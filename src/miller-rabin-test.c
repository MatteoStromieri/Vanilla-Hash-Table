#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define K 10

// Function to calculate (a^b) % m
long long int power(long long int a, long long int b, long long int m) {
    long long int result = 1;
    a = a % m;

    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % m;

        b = b / 2;
        a = (a * a) % m;
    }

    return result;
}

// Function to perform the Miller-Rabin primality test
int millerRabinTest(long long int n, int k) {
    if (n <= 1 || n == 4)
        return 0;
    if (n <= 3)
        return 1;

    // Find d such that n-1 = 2^r * d
    long long int d = n - 1;
    long long int r = 0;
    while (d % 2 == 0){
        d /= 2;
    	r += 1;
    }

    // Perform the Miller-Rabin test k times
    for (int i = 0; i < k; i++) {
        // Choose a random number 'a' such that 2 <= a <= n-2
        srand(time(NULL));
	long long int a = 2 + rand() % (n - 3);

        // Compute a^d % n
        long long int x = power(a, d, n);

        if (x == 1 || x == n - 1)
            continue;

        // Repeat the squaring process
        for (int s = 0; s < r - 1; s++) {
            x = (x * x) % n;
            if (x == 1)
                return 0;
            if (x == n - 1)
                break;
        }

        if (x != n - 1)
            return 0;
    }

    return 1; // Probably prime
}
/*
 * Returns 0 if you can't find a prime between a and b
 * */
unsigned int prime(unsigned int a, unsigned int b){
	for(int i = a; i <= b; i++){
		if(millerRabinTest(i,K))
			return i;
	}
	return 0;
}


