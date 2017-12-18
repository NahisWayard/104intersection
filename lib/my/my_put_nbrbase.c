/*
** EPITECH PROJECT, 2017
** my_put_nbrbase.c
** File description:
** my_put_nbrbase
*/

#include "my.h"

int my_put_nbrbase(int nb, char *base)
{
	int base_len = my_strlen(base);
	int displayed = 0;

	if (nb < 0)
		my_putchar('-');
	nb = (nb < 0) ? -nb : nb;
	if (nb == 0) {
		my_putchar(base[0]);
		return (0);
	}
	if (nb / base_len != 0)
		displayed = my_put_nbrbase(nb / base_len, base) + 1;
	my_putchar(base[nb % base_len]);
	return (displayed);
}

int my_put_unbrbase(unsigned int nb, char *base)
{
	int base_len = my_strlen(base);
	int displayed = 0;

	if (nb == 0) {
		my_putchar(base[0]);
		return (0);
	}
	if (nb / base_len != 0)
		displayed = my_put_nbrbase(nb / base_len, base) + 1;
	displayed += my_putchar(base[nb % base_len]);
	return (displayed);
}

int my_put_long_base(long nb, char *base)
{
	int base_len = my_strlen(base);
	int displayed = 1;

	if (nb == 0) {
		my_putchar(base[0]);
		return (1);
	}
	if (nb / base_len != 0)
		displayed = my_put_long_base(nb / base_len, base) + 1;
	my_putchar(base[nb % base_len]);
	return (displayed);
}