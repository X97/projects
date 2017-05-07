/**
 * @file str.c
 * @author Namir Hassan
 * @date 04/05/2017
 * @brief basic string functions converted to pointer based ones.
 */

#include "str.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * length of string
 * @param s
 * @return count of number of iterations
 */
int str_len(char *s)
{
	int a = 0;
	while(*s++) {

		a++;

	}
	/* this is here so code compiles */
        return a;
}

/**
 * pointer version of str_ncmp
 * @param s
 * @param t
 * @param n
 * @return sum of first subtracted by the second sum
 */
int pstr_ncmp(char *s, char *t, int n)
{
	int sum = 0;
	int sum1 = 0;
	while(*s++) {

		sum += *(s);

	}
	while(*t++) {

		sum1 += *(t);

	}

	return sum - sum1;
}

/* array version */
/* concantenate t to the end of s; s must be big enough */

void str_cat(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (s[i] != '\0') 	/* find end of s */
		i++;
	while ((s[i++] = t[j++]) != '\0') /* copy t */
		;
}

/* array version */
void squeeze(char s[], int c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];

	s[j] = '\0';
}

/**
 * pointer version of squeeze
 * @param s
 * @param c
 * @return nothing (void)
 */
void psqueeze(char *s, int c)
{
	int i, j;

	for (i = j = 0; *(s+i) != '\0'; i++)
		if (*(s+i) != c)
			*(s+j) = *(s+i);

	*(s + j) = '\0';

}

/**
 * swaps values c and d using temporary variable
 * @param c
 * @param d
 * @return nothing (void)
 */
void cswap(char *c, char *d)
{
	int tmp;
	tmp = *c;
	*c = *d;
	*d = tmp;

}

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = str_len(s) - 1; i < j; i++, j-- ) {
		/* change this so it calls cswap */
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}

}

/**
 * pointer version of reverse
 * @param s
 * @return nothing (void)
 */
void preverse(char *s)
{

	{
		int i, j;

		for (i = 0, j = str_len(s) - 1; i < j; i++, j-- ) {
			/* change this so it calls cswap */

			cswap((s+i), (s+j));
		}
	}
}

/**
 * pointer version of index
 * @param s
 * @param c
 * @return null value
 */
char *pindex(char *s, int c)
{
	while(*s++)
	{
		if(*s == c) {

		return s;

		}

	}
	return NULL;
}

/* copy n chars of src into dest */

/**
 * pointer version of str_ncpy
 * @param dest
 * @param src
 * @param n
 * @return nothing (void)
 */
void pstr_ncpy(char *dest, char *src, int n)
{
	int i;
	for(i = 0; i < n; i++) {

	*(dest + i) = *(src + i);

	}

}

/* concantenate t to the end of s; s must be big enough! */

/**
 * pointer version of str_cat
 * @param s
 * @param t
 * @return nothing (void)
 */
void pstr_cat(char *s, char *t)
{
	int i;
	int j;
	i = j = 0;

	while(*(s+i) != '\0') {

		i++;
	}
	while ((*(s + i++) = *(t + j++)) != '\0') /* copy t */
		;

}
