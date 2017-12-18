/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Main file for 104intersection
*/

#include <stdlib.h>
#include <stdio.h>

int check_nbr(char *str)
{
	for(int i = 0; str[i]; i++)
		if ((str[i] < '0' || str[i] > '9') && ((i == 0) ? str[i] != '-' : 1))
			return (0);
	return (1);
}

int main(int ac, char **av)
{
	if (ac != 9 || av[1][1] != '\0' || !check_nbr(av[1]) || !check_nbr(av[2]) || !check_nbr(av[3]) || !check_nbr(av[4]) || !check_nbr(av[5]) || !check_nbr(av[6]) || !check_nbr(av[7]) || !check_nbr(av[8]))
		exit (84);
	printf((atoi(av[1]) == 1) ? "sphere of radius %i\n" : ((atoi(av[1]) == 2)) ? "cylinder of radius %i\n" : "cone of %i degree angle\n", atoi(av[8]));
	printf("straight line going through the (%i,%i,%i) point and of direction vector (%i,%i,%i)\n", atoi(av[2]), atoi(av[3]), atoi(av[4]), atoi(av[5]), atoi(av[6]), atoi(av[7]));
	return (0);
}