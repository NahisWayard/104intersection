/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** Displays a number
*/

#include "my.h"

static void hardcoded(void)
{
	my_putstr("-2147483648");
}

static void put_n_out(int nb)
{
	if (nb >= 10) {
		my_put_nbr(nb / 10);
		my_putchar('0' + nb % 10);
	} else
		my_putchar('0' + nb % 10);
}

static void disp_positive(int nb)
{
	if ((nb >= 0) && (nb != -2147483648))
		put_n_out(nb);
	else
		hardcoded();
}

int my_put_nbr(int nb)
{
	if ((nb < 0) && (nb != -2147483648)) {
		my_putchar('-');
		my_put_nbr(-nb);
	} else
		disp_positive(nb);
	return (0);
}

int my_put_unbr(unsigned int nb)
{
	int displayed = 0;

	if (nb == 0) {
		my_putchar('0');
		return (0);
	}
	if (nb / 10 != 0)
		my_put_unbr(nb / 10);
	my_putchar(nb % 10 + '0');
	return (displayed);
}