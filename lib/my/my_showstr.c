/*
** EPITECH PROJECT, 2017
** my_showstr.c
** File description:
** my_showstr
*/

#include "my.h"

int my_showchar(char c, int remaining)
{
	if ((c >= 32) && (c < 127))
		return (my_putchar(c));
	else {
		(remaining > 0) ? my_putchar('\\') : 0;
		(c < 8 && remaining > 1) ? my_putchar('0') : 0;
		(remaining > 2) ? my_putchar('0') : 0;
		(remaining > 3) ? my_printf("%o", c) : 0;
		return ((remaining > 4) ? 4 : remaining);
	}
}