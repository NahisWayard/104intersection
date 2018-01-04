/*
** EPITECH PROJECT, 2017
** indexof.c
** File description:
** index of function
*/

int is_nbr(char *str)
{
	for (int i = 0; str[i]; i++)
		if (((str[i] < '0') || (str[i] > '9')) && ((i == 0) ? (str[i] != '-') : 1))
			return (0);
	return (1);
}