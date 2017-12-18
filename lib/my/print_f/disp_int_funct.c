/*
** EPITECH PROJECT, 2017
** disp_int_funct.c
** File description:
** Display functions for my_printf
*/

#include <stdarg.h>
#include "printf.h"
#include "my.h"

int adjust_width_num(params_t *p, char *base, int nb)
{
	int digits = get_digits_base(nb, my_strlen(base));
	int displayed = 0;
	flags_t *f = p->flags;

	if ((f->sign_type != 0) && (nb >= 0) && (f->zeros != 1))
		p->width--;
	for (int i = 0; i < p->width - digits; i++)
		if (f->l_align == 1)
			displayed += my_putchar(' ');
		else
			displayed += my_putchar((f->zeros == 0) ? ' ' : '0');
	return (displayed);
}

int disp_sign(params_t *p, int nb)
{
	if ((nb >= 0) && (p->flags->sign_type != 0))
		return (my_putchar(FLAGS[p->flags->sign_type]));
	return (0);
}

int disp_sint_zeros(int nb, params_t *p)
{
	int displayed = 0;

	if (p->flags->sign_type != 0) {
		displayed += my_putchar(FLAGS[p->flags->sign_type]);
		p->width--;
	} else if (nb < 0) {
		nb = -nb;
		displayed += my_putchar('-');
		p->width--;
	}
	displayed += adjust_width_num(p, "0123456789", nb);
	my_put_nbr(nb);
	displayed = (nb < 0) ? displayed + 1 : displayed;
	displayed += get_digits(nb);
	return (displayed);
}

int disp_sint_no_zeros(int nb, params_t *p)
{
	int displayed = 0;

	if (p->flags->l_align == 1) {
		displayed += disp_sign(p, nb);
		my_put_nbr(nb);
		displayed = (nb < 0) ? displayed + 1 : displayed;
		displayed += get_digits(nb);
		displayed += adjust_width_num(p, "0123456789", nb);
	} else {
		displayed += adjust_width_num(p, "0123456789", nb);
		displayed += disp_sign(p, nb);
		displayed += get_digits(nb);
		my_put_nbr(nb);
		displayed = (nb < 0) ? displayed + 1 : displayed;
	}
	return (displayed);
}

int disp_sint(va_list list, params_t *p)
{
	int displayed = 0;
	int nb = va_arg(list, int);

	if (p->flags->zeros == 1)
		displayed = disp_sint_zeros(nb, p);
	else
		displayed = disp_sint_no_zeros(nb, p);
	return (displayed);
}