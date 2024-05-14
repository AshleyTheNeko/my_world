/*
** EPITECH PROJECT, 2021
** lm
** File description:
** libmy_other_prototypes
*/

#ifndef LIBMY_OTHER_PROTOTYPES_H_
#define LIBMY_OTHER_PROTOTYPES_H_

#include "libmy_structs.h"
#include <stdarg.h>

void get_converter(char format, form_t *form_arg);
char is_flag(char format, form_t *format_arg);
int get_precision(char *format, form_t *format_arg);
int get_width(char *format, form_t *format_arg);
int get_lm(char *format, form_t *form_arg);
char *my_hexa_ptr(void *ptr, form_t *args);
char *base_convert(form_t *args, long long number, char mode);
char *get_result(form_t *format_arg, va_list *arg_list);
char *my_octal_str(char *str);
char *append_padding(form_t *args, char **in);
char *alt(form_t *args, long long nb);
int get_flags(char *format, form_t *format_arg);

#endif /* !LIBMY_OTHER_PROTOTYPES_H_ */