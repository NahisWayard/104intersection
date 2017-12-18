/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** Function that displays a char*
*/

#include "my.h"

int my_putstr(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		my_putchar(str[i]);
	return (i);
}