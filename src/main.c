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
#include "my.h"

char **argv = NULL;

void delta(float a, float b, float c)
{
	if ((b * b) - 4 * a *c >= 0) {
		printf("%i intersection point :\n", (((b * b) - 4 * a *c) == 0) ? 1 : 2);
		printf("(%.3f,%.3f,%.3f)\n", VX * (-b + sqrt((b * b) - 4 * a *c)) / (2 * a) + PX, VY * (-b + sqrt((b * b) - 4 * a *c)) / (2 * a) + PY, VZ * (-b + sqrt((b * b) - 4 * a *c)) / (2 * a) + PZ);
		if (((b * b) - 4 * a *c) != 0)
			printf("(%.3f,%.3f,%.3f)\n", VX * (-b - sqrt((b * b) - 4 * a *c)) / (2 * a) + PX, VY * (-b - sqrt((b * b) - 4 * a *c)) / (2 * a) + PY, VZ * (-b - sqrt((b * b) - 4 * a *c)) / (2 * a) + PZ);
	} else
		printf("No intersection point.\n");
}

int main(int ac, char **av)
{
	if ((ac != 9) || (av[1][1] != '\0') || !is_nbr(av[1]) || !is_nbr(av[2]) || !is_nbr(av[3]) || !is_nbr(av[4]) || !is_nbr(av[5]) || !is_nbr(av[6]) || !is_nbr(av[7]) || !is_nbr(av[8]))
		exit(84);
	argv = av;
	printf((argv[1][0] == 49) ? "sphere of radius %i\n" : (argv[1][0] == 50) ? "cylinder of radius %i\n" : "cone of %i degree angle\n", atoi(av[8]));
	printf("straight line going through the (%i,%i,%i) point and of direction vector (%i,%i,%i)\n", atoi(av[2]), atoi(av[3]), atoi(av[4]), atoi(av[5]), atoi(av[6]), atoi(av[7]));
	(argv[1][0] == 49) ? delta(VX * VX + VY * VY + VZ * VZ, (2 * PX * VX) + (2 * PY * VY) + (2 * PZ * VZ), PX * PX + PY * PY + PZ * PZ - RAD * RAD) : (argv[1][0] == 50) ? delta(VX * VX + VY * VY, (2 * PX * VX) + (2 * PY * VY), PX * PX + PY * PY - RAD * RAD) : delta(VX * VX + VY * VY - ((VZ * VZ) / (ANGLE)), (2 * PX * VX) + (2 * PY * VY)  - ((2 * PZ * VZ) / (ANGLE)), PX * PX + PY * PY - ((PZ * PZ) / (ANGLE)));
	return (0);
}