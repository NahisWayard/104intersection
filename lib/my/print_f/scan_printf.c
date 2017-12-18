/*
** EPITECH PROJECT, 2017
** scan_printf.c
** File description:
** functiosn that scans for falgs ect
*/

#include <stdarg.h>
#include "my.h"
#include "printf.h"

int scan_flags(va_list list, char *str, params_t *params, char *init_ptr)
{
	int i;

	for (i = 1; indexof(str[i], FLAGS) != -1; i++)
		fill_params(params, str[i]);
	return (scan_width(list, str + i, params, init_ptr));
}

int scan_width(va_list list, char *str, params_t *params, char *init_ptr)
{
	int nb = (str[0] == '*') ? va_arg(list, int) : my_getnbr(str);

	if (nb < 0) {
		params->flags->l_align = 1;
		params->flags->conv_info = 0;
		params->width = -nb;
	} else if ((nb == 0) && (str[0] >= '0') && (str[0] <= '9'))
		params->flags->conv_info = 1;
	else
		params->width = nb;
	str = (str[0] == '*') ? str + 1 : str + get_digits(nb);
	return (scan_precision(list, str, params, init_ptr));
}

int scan_precision(va_list list, char *str, params_t *params, char *init_ptr)
{
	if (str[0] == '.') {
		params->precision = my_getnbr(str + 1);
		str = str + get_digits(params->precision) + 1;
	}
	return (scan_len(list, str, params, init_ptr));
}

int check_type(va_list list, char *str, params_t *params, char *init_ptr)
{
	params->type = indexof(str[0], TYPES);
	if (params->type == -1)
		return (display(list, init_ptr, params, 1));
	else
		return (display(list, str + 1, params, 0));
}

int scan_len(va_list list, char *str, params_t *params, char *init_ptr)
{
	if (str[0] == 'l') {
		if (str[1] != 'l')
			params->len = 1;
		else
			params->len = 2;
	} else if (str[0] == 'h') {
		if (str[1] != 'h')
			params->len = 3;
		else
			params->len = 4;
	}
	if ((str[0] == 'h') || (str[0] == 'l')) {
		if (str[0] == str[1])
			str = str + 2;
		else
			str = str + 1;
	}
	return (check_type(list, str, params, init_ptr));
}