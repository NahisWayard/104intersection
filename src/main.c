/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Main file for 104intersection
*/

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "104.h"

int check_nbr(char *str)
{
	for (int i = 0; str[i]; i++)
		if (((str[i] < '0') || (str[i] > '9')) && ((i == 0) ? (str[i] != '-') : 1))
			return (0);
	return (1);
}

void delta(float delta)
{
	printf("[DEBUG] DELTA: %.2f\n", delta);
}

void sphere(char **av)
{
	;
}

void cylinder(char **av)
{
	;
}

void cone(char **av)
{
	;
}

int main(int ac, char **av)
{
	if ((ac != 9) || (av[1][1] != '\0') || !check_nbr(av[1]) || !check_nbr(av[2]) || !check_nbr(av[3]) ||
	    !check_nbr(av[4]) || !check_nbr(av[5]) || !check_nbr(av[6]) || !check_nbr(av[7]) || !check_nbr(av[8]))
		exit(84);
	printf(
		(av[1][0] == 49) ? "sphere of radius %i\n" : (av[1][0] == 50) ? "cylinder of radius %i\n" : "cone of %i degree angle\n",
		atoi(av[8]));
	printf("straight line going through the (%i,%i,%i) point and of direction vector (%i,%i,%i)\n", atoi(
		       av[2]), atoi(av[3]), atoi(av[4]), atoi(av[5]), atoi(av[6]), atoi(av[7]));
	(av[1][0] == 49) ? delta(pow((int) ((2 * PX * VX) + (2 * PY * VY) + (2 * PZ * VZ)), 2) - (4 * (int) (VX * VX + VY * VY + VZ * VZ) * (int) (PX * PX + PY * PY + PZ * PZ - RAD * RAD))) : (av[1][0] == 50) ? delta(pow((int) ((2 * PX * VX) + (2 * PY * VY)), 2) - (4 * (int) (VX * VX + VY * VY) * (int) (PX * PX + PY * PY - RAD * RAD))) : delta(pow((int) ((2 * PX * VX) + (2 * PY * VY)  - ((2 * PZ * VZ) / (tan(RAD) * tan(RAD)))), 2) - (4 * (int) (VX * VX + VY * VY - ((VZ * VZ) / (tan(RAD) * tan(RAD)))) * (int) (PX * PX + PY * PY - ((PZ * PZ) / (tan(RAD) * tan(RAD))))));
	return (0);
}