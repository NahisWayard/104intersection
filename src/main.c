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
	for(int i = 0; str[i]; i++)
		if ((str[i] < '0' || str[i] > '9') && ((i == 0) ? str[i] != '-' : 1))
			return (0);
	return (1);
}

void disp(float a, float b, float c)
{
	printf("[DEBUG] Delta -> %f\n", (b * b) - (4 * a * c));
	if ((b * b) - (4 * a * c) < 0) {
		printf("No intersection point.\n");
	} else if ((b * b) - (4 * a * c) == 0) {
		printf("1 intersection points :\n");
	} else {
		printf("2 intersection points :\n");
	}
}

void sphere(char **av)
{
	float a = (XV * XV) + (YV + YV) + (ZV + ZV);
	float b = (2 * XP * XV) + (2 * YP * YV) + (2 * ZP * ZV);
	float c = (XP * XP) + (YP * YP) + (ZP * ZP) - (PAR * PAR);
	disp(a, b, c);
}

void cylinder(char **av)
{
	float a = (XV * XV) + (YV * YV);
	float b = (2 * XP * XV) + (2 * YP * YV);
	float c = (XP * XP) + (YP * YP) - (PAR * PAR);
	disp(a, b, c);
}

void cone(char **av)
{
	float a = (XV * XV) + (YV * YV) - (ZV * ZV) / ANGLE;
	float b = (2 * XP * XV) + (2 * YP * YV) - (2 * ZP * ZV / ANGLE);
	float c = (XP * XP) + (YP *YP) - (ZP * ZP) / ANGLE;
	disp(a, b, c);
}

int main(int ac, char **av)
{
	if (ac != 9 || av[1][1] != '\0' || !check_nbr(av[1]) || !check_nbr(av[2]) || !check_nbr(av[3]) || !check_nbr(av[4]) || !check_nbr(av[5]) || !check_nbr(av[6]) || !check_nbr(av[7]) || !check_nbr(av[8]))
		exit (84);
	printf((av[1][0] == 49) ? "sphere of radius %i\n" : (av[1][0] == 50) ? "cylinder of radius %i\n" : "cone of %i degree angle\n", atoi(av[8]));
	printf("straight line going through the (%i,%i,%i) point and of direction vector (%i,%i,%i)\n", atoi(av[2]), atoi(av[3]), atoi(av[4]), atoi(av[5]), atoi(av[6]), atoi(av[7]));
	(av[1][0] == 49) ? sphere(av) : (av[1][0] == 50) ? cylinder(av) : cone(av);
	return (0);
}