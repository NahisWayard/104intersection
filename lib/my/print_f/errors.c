/*
** EPITECH PROJECT, 2017
** errors.c
** File description:
** File that handles errors / conflicting flags
*/

#include "printf.h"
#include "my.h"

void incompatible_flags(params_t *p)
{
	flags_t *f = p->flags;

	if ((f->sign_type != 0) && (indexof(TYPES[p->type], "uxXo") != -1))
		f->sign_type = 0;
}

void precision_num_type(params_t *p)
{
	if (((p->type >= 1) && (p->type <= 7)) && (p->precision != -1)) {
		p->width = p->precision + 1;
		p->flags->zeros = 1;
	}
}

int errors(params_t *p)
{
	incompatible_flags(p);
	precision_num_type(p);
	if ((p->flags->zeros == 1) && (p->flags->l_align == 1))
		p->flags->zeros = 0;
	return (0);
}