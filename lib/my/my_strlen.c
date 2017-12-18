/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** Write a function that reverses a string.
*/

#include "my.h"

int my_strlen(char const *str)
{
	int len;

	for (len = 0; str[len] != '\0'; len++);
	return (len);
}

int my_strshowlen(char const *str)
{
	int len = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		len++;
		if ((str[i] < 32) || (str[i] >= 127))
			len += 3;
	}
	return (len);
}