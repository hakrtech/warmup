#include <stdbool.h>

#include "libnumi.h"

#if 0
int  numi_factorial(int n) // DOIT factor array algo
int  numi_factorial_rec(int n) // DOIT factor array algo
int  numi_gcd1(int a, int b) // DOIT factor array algo
int  numi_gcd2(int a, int b) // DOIT our - algo
int  numi_gcd3(int a, int b) // DOIT euler algo
int  numi_gcd4(int a, int b) // DOIT while loop algo
int  numi_gcd5(int a, int b) // DOIT recursive algo
int  numi_pown(int n, int pow)	// DOIT
int  numi_pown_rec(int n, int pow) // DOIT
bool numi_iscomposite(int n) // DOIT
int  numi_trisum_rec(int n) // DOIT
#endif

bool numi_isprime(int n) // DONE
{
	int d;
	bool isPrime;

	isPrime = true;
	for (d = 2; d < n; ++d) {
		if (n % d == 0) {
			isPrime = false;
			break;
		}
	}

	return isPrime;
}
#if 0
int prime(int x) // LIBIT
{
	int d;
	_Bool isPrime;

	isPrime = 1;

	for (d = 2; d < x; ++d) {
		if (x % d == 0) {
			isPrime = 0;
		}
	}
		return isPrime;
}
#endif

int  numi_trisum(int n) //DONE
{
	int sum;
	int i;

	sum = 0;
	i = 1;
       	while (i <= n) {
		sum += i;
		++i;
	}

	return sum;
}

#if 0
int triangular_num(int n) // LIBIT
{
	int sum;
	int count;

	sum = 0;
	count = 1;
       
	while (count <= n) {
		sum += count;
		++count;
	}

	return sum;
}

#endif
