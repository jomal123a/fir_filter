/*
 * fir.c
 *
 *  Created on: 23 may 2020
 *  Author: Micha� Nadolny
 *
 */
#include "fir.h"

int* buffr_ptr;

int fir(int xin, const int w[], int N, int x[]) {

	// If buffer is empty or not loaded return 0
	static int loaded = 0;
	static int n = 0;

	long y = 0;
	int i;
	int j;

	if (!loaded) {
		x[n] = xin;
		buffr_ptr = &x[n];
		++n;
		if (n >= N) loaded = 1;
		j = N - n;
	}
	else {
	// Else return filtered output value
		if (n >= N) {
			buffr_ptr = &x[0];
			n = 0;
		} else {
			++buffr_ptr;
			++n;
		}
		*buffr_ptr = xin;
		j = N - n - 1 ;
	}

	// Initialize counter with start value n
	for (i = 0; i < N; ++i, ++j) {
		y += w[i] * (long) x[(N - 1) - (j % N)];
	}

	return (y >> 15);

}




