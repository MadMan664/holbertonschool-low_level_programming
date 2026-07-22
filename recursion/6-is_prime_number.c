#include "main.h"

/**
 * prime_helper - checks recursively whether n has a divisor up to div
 * @n: number being tested
 * @div: current divisor being tested
 *
 * Return: 1 if no divisor found up to sqrt(n), 0 if div divides n
 */
int prime_helper(int n, int div)
{
	if (div * div > n)
		return (1);

	if (n % div == 0)
		return (0);

	return (prime_helper(n, div + 1));
}

/**
 * is_prime_number - checks recursively if an integer is a prime number
 * @n: number to check
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n < 2)
		return (0);

	return (prime_helper(n, 2));
}
