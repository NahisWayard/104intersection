/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** my_printf with same flags
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "printf.h"
#include "types.h"

int count_vargs(char *str)
{
	int vargs = 0;

	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == '%')
			vargs++;
	return (vargs);
}

int disp_arg(va_list list, params_t *params)
{
	if (params->type != -1) {
		errors(params);
		return (tab_types[params->type].function(list, params));
	}
	return (0);
}

int display(va_list list, char *str, params_t *params, int error)
{
	int i = 0;
	int displayed = 0;

	if (error == 1) {
		displayed += my_putchar(str[1]);
		displayed += my_putchar(str[2]);
		i = i + 3;
	}
	displayed += disp_arg(list, params);
	if ((str[0] == '\0') || (str[1] == '\0'))
		return (displayed);
	for (; str[i] != '%' && str[i] != '\0'; i++)
		displayed += my_putchar(str[i]);
	if ((str[i + 3] == '\0') && (str[i] == '%') && (params->type > 2))
		displayed++;
	reset_params(params);
	displayed += scan_flags(list, str + i, params, str + i - 1);
	return (displayed);
}

int my_printf(char const *str, ...)
{
	char *copy = my_strdup(str);
	int displayed_char = 0;
	va_list args;
	int args_count = count_vargs(copy);
	params_t *params = init_params();

	va_start(args, str);
	if (args_count == 0)
		return (my_putstr(copy));
	displayed_char += display(args, copy, params, 0);
	va_end(args);
	if (indexof(copy[my_strlen(copy) - 1], TYPES) == -1)
		my_putchar(copy[my_strlen(copy) - 1]);
	free(params->flags);
	free(params);
	free(copy);
	return (displayed_char);
}