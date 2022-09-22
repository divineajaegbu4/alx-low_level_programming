#include "main.h"

/**
 *_strlen - counts and reutns string length
 * @s: the input string
 *
 * Return: the length
 */
int _strlen(char *s)
{
	int c = 0;

	for (c = 0; *s; c++)
		s++;

	return (c);
}


/**
 * rev_string - reverses a string
 * @s: the address of the input string
 *
 * Return: nothing to return
 */

void rev_string(char *s)
{
	int i, sl;
	char *a, *z, tp;

	sl = _strlen(s);
	a = s;
	z = s;

	for (i = 0; i < sl - 1; i++)
		z++;

	for (i = 0; i < (sl / 2); i++)
	{
		tp = *z;
		*z = *a;
		*a = tp;
		a++;
		z--;
	}
}


/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: the buffer that the function will use to store the result
 * @size_r: buffer size
 *
 * Return: pointer to the result, or 0.
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{

	char *bfr = r;
	int idx = 0, n1l = _strlen(n1), n2l = _strlen(n2), rdr = 0;
	int p1, p2, sum;

	while (n1l > 0 || n2l > 0)
	{
		p1 = n1l > 0 ? (*(n1 + n1l - 1) - '0') : 0;
		p2 = n2l > 0 ? (*(n2 + n2l - 1) - '0') : 0;
		sum = p1 + p2;
		*(bfr + idx) = ((sum + rdr) % 10) + '0';
		rdr = (sum + rdr) / 10;
		idx++;
		n1l--;
		n2l--;
	}
	if (rdr)
	{
		*(bfr + idx) = rdr + '0';
		idx++;
	}
	*(bfr + idx) = '\0';
	rev_string(bfr);
	return ((size_r > _strlen(bfr)) ? bfr : 0);
}
