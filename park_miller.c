#include <stdio.h>
#include <math.h>

#include "my_random.h"

#define a 48271
#define m 2147483647 // 2^31 - 1
#define q (m / a)
#define r (m % a)

static long long int seed = 1;

long long int PMrand() {
	// X_n+1 = (48271 * X_n) mod (2^31 - 1)
	// X = a (hi*q + lo) (mod m)
	//   = hi*a*q + a*lo (mod a*q+r)
	//   = -hi*r + a*lo (mod a*q+r)
	
	long long int hi = seed / q;
	long long int lo = seed % q;
	seed = a * lo - hi * r;
	if (seed < 0) seed += m;
	return seed;
}
