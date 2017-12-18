/*
** EPITECH PROJECT, 2017
** my_printf_params.c
** File description:
** Struct function for my_printf
*/

#include <stdlib.h>
#include "my.h"
#include "printf.h"

flags_t *init_flags(void)
{
	flags_t *flags = malloc(sizeof(flags_t));

	flags->l_align = 0;
	flags->sign_type = 0;
	flags->zeros = 0;
	flags->conv_info = 0;
	return (flags);
}

params_t *init_params(void)
{
	params_t *params = malloc(sizeof(params_t));

	params->flags = init_flags();
	params->width = 0;
	params->precision = -1;
	params->len = 0;
	params->type = -1;
	return (params);
}

void reset_params(params_t *params)
{
	params->flags->l_align = 0;
	params->flags->sign_type = 0;
	params->flags->zeros = 0;
	params->flags->conv_info = 0;
	params->width = 0;
	params->precision = -1;
	params->len = 0;
	params->type = -1;
}

void fill_params(params_t *params, char c)
{
	flags_t *f = params->flags;

	switch (indexof(c, FLAGS)) {
	case 0:
		f->l_align = 1;
		f->zeros = 0;
		break;
	case 1:
		f->sign_type = 1;
		break;
	case 2:
		f->sign_type = (f->sign_type == 0) ? 2 : f->sign_type;
		break;
	case 3:
		f->zeros = 1;
		break;
	case 4:
		f->conv_info = 1;
		break;
	}
}