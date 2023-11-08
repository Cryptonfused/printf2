#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len1, len2;

	len1 = _printf("%\n");
	len2 = printf("%\n");
	printf("Len1: [%d], len2: [%d]\n", len2, len2);
	fflush(stdout);
	if (len1 != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("success\n");
	return (0);
}
