/*
** EPITECH PROJECT, 2017
** printf.h
** File description:
** Structures for my_printf arg
*/

#include <stdarg.h>

#ifndef __MY_PRINTF__
#define	__MY_PRINTF__

#define	FLAGS "-+ 0#"
#define	TYPES "%diuxXobsScp"

typedef struct
{
	char l_align;
	int sign_type;
	char zeros;
	char conv_info;
} flags_t;

typedef struct
{
	flags_t *flags;
	int width;
	int precision;
	char len;
	int type;
} params_t;

params_t *init_params(void);
flags_t *init_flags(void);
void reset_params(params_t *);
int scan_flags(va_list list, char *str, params_t *params, char *init_ptr);
int scan_width(va_list list, char *str, params_t *params, char *init_ptr);
int scan_precision(va_list list, char *str, params_t *params, char *init_ptr);
int check_type(va_list list, char *str, params_t *params, char *init_ptr);
int scan_len(va_list list, char *str, params_t *params, char *init_ptr);
int get_len(int nb);
int display(va_list list, char *str, params_t *params, int error);
int errors(params_t *);
void fill_params(params_t *, char);

int disp_mod(va_list list, params_t *params);
int disp_sint(va_list list, params_t *params);
int disp_uint(va_list list, params_t *params);
int disp_hex_low(va_list list, params_t *params);
int disp_hex_up(va_list list, params_t *params);
int disp_oct(va_list list, params_t *params);
int disp_bin(va_list list, params_t *params);
int disp_str(va_list list, params_t *params);
int print_str(va_list list, params_t *params);
int disp_c(va_list list, params_t *params);
int disp_ptr(va_list list, params_t *params);

#endif