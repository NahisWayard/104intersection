/*
** EPITECH PROJECT, 2017
** types.h
** File description:
** Structures for my_printf.h
*/

#include <stdarg.h>
#include "printf.h"

struct
{
	char c;
	int (*function)(va_list, params_t *);
} tab_types[] = {
	{'%', &disp_mod},
	{'d', &disp_sint},
	{'i', &disp_sint},
	{'u', &disp_uint},
	{'x', &disp_hex_low},
	{'X', &disp_hex_up},
	{'o', &disp_oct},
	{'b', &disp_bin},
	{'s', &disp_str},
	{'S', &print_str},
	{'c', &disp_c},
	{'p', &disp_ptr},
};