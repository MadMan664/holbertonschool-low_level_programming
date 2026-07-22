#include "main.h"

/**
 * sqrt_helper - searches recursively for the natural square root of n
 * @n: number to find the square root of
 * @candidate: current candidate square root being tested
 *
 * Return: candidate if it is the natural square root, -1 if none exists
 */
int sqrt_helper(int n, int candidate)
{
	if (candidate * candidate == n)
		return (candidate);

	if (candidate * candidate > n)
		return (-1);

	return (sqrt_helper(n, candidate + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number, recursively
 * @n: number to find the square root of
 *
 * Return: natural square root of n, or -1 if it has none
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (sqrt_helper(n, 0));
}
