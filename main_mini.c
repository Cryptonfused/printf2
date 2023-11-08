#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    mini_printf("String:[%s]\n", "I am a string !");
    mini_printf("String:[%s]\n", NULL);
    mini_printf("%!\n");
    mini_printf("%K\n");
    return (0);
}
