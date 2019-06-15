//
//https://narusejun.com/archives/5/
//

#include <stdio.h>
#include <math.h>

#define W 32
#define N 624
#define M 397
#define R 31
#define U 11
#define S 7
#define T 15
#define L 18
#define A 0x9908B0DFUL
#define B 0x9D2C5680
#define C 0xEFC60000
#define UPPER_MASK 0x80000000UL
#define LOWER_MASK 0x7FFFFFFFUL

static unsigned long x[N]; // state vector
int mt_flag = 0; // 0 means not initialized

unsigned long long int seed = 0;

static int i = 0;

void MT_initializer() {
	x[0] = seed & 0xFFFFFFFFUL;
	for(int j = 1; j < N; j++) {
		x[j] = (1812433253UL * (x[j-1] ^ (x[j-1] >> 30)) + j);
		x[j] &= 0xFFFFFFFFUL;
	}
}

unsigned long MTrand() {
	unsigned long y;
	unsigned long z;
	if (mt_flag == 0) {
		MT_initializer();
		mt_flag = 1;
	}

	z = x[i] & UPPER_MASK | x[(i+1)%N] & LOWER_MASK;

	x[i] = x[(i+M) % N] ^ (z >> 1) ^ (z & 1 == 0 ? 0 : A);

	y = x[i];
	y = y ^ (y >> U);
	y = y ^ ((y << S) & B);
	y = y ^ ((y << T) & C);
	y = y ^ (y >> L);

	i = (i + 1) % N;
	return y;
}
