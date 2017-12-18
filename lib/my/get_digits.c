/*
** EPITECH PROJECT, 2017
** get_digits.c
** File description:
** return the number of digits of an int
*/

int get_digits(int nb)
{
	int i = (nb <= 0) ? 1 : 0;

	for (i = 0; nb != 0; i++)
		nb = nb / 10;
	return (i);
}

int get_digits_base(int nb, int base_len)
{
	int i = (nb < 0) ? 1 : 0;

	for (; nb != 0; i++)
		nb = nb / base_len;
	return (i);
}

int uget_digits_base(unsigned int nb, int base_len)
{
	int i = 0;

	for (; nb != 0; i++)
		nb = nb / base_len;
	return (i);
}