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

char type = 0;
char **argv = NULL;

int check_nbr(char *str)
{
	for (int i = 0; str[i]; i++)
		if (((str[i] < '0') || (str[i] > '9')) && ((i == 0) ? (str[i] != '-') : 1))
			return (0);
	return (1);
}

void disp_c(float t)
{
	//printf("VZ %.2f t %.2f PZ %.2f\n", VZ, t, PZ);
	printf("(%.3f,%.3f,%.3f)\n", VX * t + PX, VY * t + PY, VZ * t + PZ);
}

void delta(float a, float b, float c)
{
	//printf("[DEBUG] DELTA: %.2f\n", (b * b) - 4 * a *c);
	if ((b * b) - 4 * a *c >= 0) {
		float x1 = (-b + sqrt((b * b) - 4 * a *c)) / (2 * a), x2 = (-b - sqrt((b * b) - 4 * a *c)) / (2 * a);
		printf("%i intersection point :\n", (((b * b) - 4 * a *c) == 0) ? 1 : 2);
		disp_c(x1);
		if (((b * b) - 4 * a *c) != 0) {
			disp_c(x2);
		}
	} else
		printf("No intersection point.\n");
}

void sphere(char **av)
{
	delta(VX * VX + VY * VY + VZ * VZ, (2 * PX * VX) + (2 * PY * VY) + (2 * PZ * VZ), PX * PX + PY * PY + PZ * PZ - RAD * RAD);
}

void cylinder(char **av)
{
	delta(VX * VX + VY * VY, (2 * PX * VX) + (2 * PY * VY), PX * PX + PY * PY - RAD * RAD);
}

void cone(char **av)
{
	delta(VX * VX + VY * VY - ((VZ * VZ) / (tan(RAD) * tan(RAD))), (2 * PX * VX) + (2 * PY * VY)  - ((2 * PZ * VZ) / (tan(RAD) * tan(RAD))), PX * PX + PY * PY - ((PZ * PZ) / (tan(RAD) * tan(RAD))));
}

int main(int ac, char **av)
{
	if ((ac != 9) || (av[1][1] != '\0') || !check_nbr(av[1]) || !check_nbr(av[2]) || !check_nbr(av[3]) || !check_nbr(av[4]) || !check_nbr(av[5]) || !check_nbr(av[6]) || !check_nbr(av[7]) || !check_nbr(av[8]))
		exit(84);
	type = av[1][0];
	argv = av;
	printf((type == 49) ? "sphere of radius %i\n" : (type == 50) ? "cylinder of radius %i\n" : "cone of %i degree angle\n", atoi(av[8]));
	printf("straight line going through the (%i,%i,%i) point and of direction vector (%i,%i,%i)\n", atoi(av[2]), atoi(av[3]), atoi(av[4]), atoi(av[5]), atoi(av[6]), atoi(av[7]));
	(type == 49) ? sphere(av) : (type == 50) ? cylinder(av) : cone(av);
	return (0);
}