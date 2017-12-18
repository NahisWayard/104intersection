/*
** EPITECH PROJECT, 2017
** disp_conv_uint.c
** File description:
** Functions that displays differents uint
*/

#include <stdarg.h>
#include "my.h"
#include "printf.h"

int disp_uint(va_list list, params_t *params)
{
	unsigned int nb = va_arg(list, unsigned int);
	int displayed = 0;
	flags_t *f = params->flags;

	if (f->l_align == 1) {
		displayed += my_put_unbrbase(nb, "0123456789");
		for (int i = uget_digits_base(nb, 10); i < params->width; i++)
			displayed += my_putchar(' ');
	} else {
		for (int i = uget_digits_base(nb, 10); i < params->width; i++)
			displayed += my_putchar((f->zeros == 1) ? '0' : ' ');
		displayed += my_put_unbrbase(nb, "0123456789");
	}
	return (displayed);
}

int disp_hex_low(va_list list, params_t *params)
{
	unsigned int nb = va_arg(list, unsigned int);
	int displayed = 0;
	flags_t *f = params->flags;

	if (f->conv_info == 1) {
		displayed += my_putstr("0x");
		params->width -= 2;
	}
	if (f->l_align == 1) {
		displayed += my_put_unbrbase(nb, "0123456789abcdef");
		for (int i = uget_digits_base(nb, 16); i < params->width; i++)
			displayed += my_putchar(' ');
	} else {
		for (int i = uget_digits_base(nb, 16); i < params->width; i++)
			displayed += my_putchar((f->zeros == 1) ? '0' : ' ');
		displayed += my_put_unbrbase(nb, "0123456789abcdef");
	}
	return (displayed);
}

int disp_hex_up(va_list list, params_t *params)
{
	unsigned int nb = va_arg(list, unsigned int);
	int displayed = 0;
	flags_t *f = params->flags;

	if (f->conv_info == 1) {
		displayed += my_putstr("0X");
		params->width -= 2;
	}
	if (f->l_align == 1) {
		displayed += my_put_unbrbase(nb, "0123456789ABCDEF");
		for (int i = uget_digits_base(nb, 16); i < params->width; i++)
			displayed += my_putchar(' ');
	} else {
		for (int i = uget_digits_base(nb, 16); i < params->width; i++)
			displayed += my_putchar((f->zeros == 1) ? '0' : ' ');
		displayed += my_put_unbrbase(nb, "0123456789ABCDEF");
	}
	return (displayed);
}

int disp_oct(va_list list, params_t *params)
{
	unsigned int nb = va_arg(list, unsigned int);
	int displayed = 0;
	flags_t *f = params->flags;

	if (f->conv_info == 1) {
		displayed += my_putstr("0");
		params->width--;
	}
	if (f->l_align == 1) {
		displayed += my_put_unbrbase(nb, "01234567");
		for (int i = uget_digits_base(nb, 8); i < params->width; i++)
			displayed += my_putchar(' ');
	} else {
		for (int i = uget_digits_base(nb, 8); i < params->width; i++)
			displayed += my_putchar((f->zeros == 1) ? '0' : ' ');
		displayed += my_put_unbrbase(nb, "01234567");
	}
	return (displayed);
}

int disp_bin(va_list list, params_t *params)
{
	unsigned int nb = va_arg(list, unsigned int);
	int displayed = 0;
	flags_t *f = params->flags;

	if (f->l_align == 1) {
		displayed += my_put_unbrbase(nb, "01");
		for (int i = uget_digits_base(nb, 2); i < params->width; i++)
			displayed += my_putchar(' ');
	} else {
		for (int i = uget_digits_base(nb, 2); i < params->width; i++)
			displayed += my_putchar((f->zeros == 1) ? '0' : ' ');
		displayed += my_put_unbrbase(nb, "01");
	}
	return (displayed);
}