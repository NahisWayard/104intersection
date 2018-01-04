/*
** EPITECH PROJECT, 2017
** lib_my
** File description:
** lib my
*/

#ifndef __MY__H_
#define	__MY__H_

int is_nbr(char *);
int my_put_nbr(int);
int my_putchar(char);
int my_putstr(char *);
int my_strlen(char const *);
int my_printf(char const *, ...);
int get_digits(int nb);
int my_getnbr(char *);
int get_digits_base(int, int);
int my_put_unbrbase(unsigned int, char *);
int indexof(char, char *);
int my_put_nbrbase(int, char *);
int my_put_unbr(unsigned int nb);
char *my_strdup(char const *str);
int uget_digits_base(unsigned int nb, int base_len);
int my_put_long_base(long nb, char *base);
int my_strshowlen(char const *str);
int my_showchar(char, int);

#endif