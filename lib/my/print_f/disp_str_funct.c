/*
** EPITECH PROJECT, 2017
** disp_str_funct.c
** File description:
** Display functions for my_printf
*/

#include <stdarg.h>
#include "printf.h"
#include "my.h"

int disp_mod(va_list list, params_t *params)
{
	list = list;
	params =  params;
	return (my_putchar('%'));
}

int disp_str(va_list list, params_t *p)
{
	char *str = va_arg(list, char *);
	int len = my_strlen(str);
	int displayed = 0;

	if ((p->precision > 0) && (my_strlen(str) > p->precision))
		len = p->precision;
	for (int i = len; i < p->width && p->flags->l_align == 0; i++)
		displayed += my_putchar(' ');
	for (int i = 0; i < len; i++)
		displayed += my_putchar(str[i]);
	for (int i = len; i < p->width && p->flags->l_align == 1; i++)
		displayed += my_putchar(' ');
	return (displayed);
}

int print_str(va_list list, params_t *p)
{
	char *str = va_arg(list, char *);
	int len = my_strshowlen(str);
	int displayed = 0;

	if ((p->precision > 0) && (len > p->precision))
		len = p->precision;
	for (int i = len; i < p->width && p->flags->l_align == 0; i++)
		displayed += my_putchar(' ');
	for (int i = 0; displayed < len; i++)
		displayed += my_showchar(str[i], len - displayed);
	for (int i = len; i < p->width && p->flags->l_align == 1; i++)
		displayed += my_putchar(' ');
	return (displayed);
}

int disp_c(va_list list, params_t *p)
{
	for (int i = 1; i < p->width && (p->flags->l_align == 0); i++)
		my_putchar(' ');
	my_putchar(va_arg(list, int));
	for (int i = 1; i < p->width && p->flags->l_align == 1; i++)
		my_putchar(' ');
	return ((p->width != 0) ? p->width : 1);
}

int disp_ptr(va_list list, params_t *params)
{
	long ptr = va_arg(list, long);
	int displayed = 0;

	if (params->flags->sign_type != 0)
		displayed += my_putchar(FLAGS[params->flags->sign_type]);
	displayed += my_putstr("0x");
	displayed += my_put_long_base(ptr, "0123456789abcdef");
	return (displayed);
}