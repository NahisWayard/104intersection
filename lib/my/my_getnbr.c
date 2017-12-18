/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** my_get_number
*/

int my_getnbr(char *str)
{
	int nb = 0;

	for (int i = 0; str[i] >= '0' && str[i] <= '9'; i++) {
		nb = nb * 10;
		nb = nb + str[i] - '0';
	}
	return (nb);
}