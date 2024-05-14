/*
** EPITECH PROJECT, 2021
** lm_macros
** File description:
** libmy_macros
*/

#ifndef LIBMY_MACROS_H_
#define LIBMY_MACROS_H_

/// Calculates absolute value of x
#define ABS(x) (((x) < 0) ? (-1 * (x)) : (x))
/// Determines if x is negative
#define ISNEG(x) (((x) < 0) ? (1) : (0))
/// Determines if character x is a number
#define NBR(x) ((x) <= '9' && (x) >= '0')

///////////////////////////////
// Printf internal functions //
///////////////////////////////

#define DIFF(min, max) (((min) < (max)) ? (((max) - (min)) + (min)) : (min))
#define UPC "0123456789ABCDEF"
#define LOC "0123456789abcdef"
#define MODE(x) ((x) ? (my_strdup(LOC)) : (my_strdup(UPC)))
#define ISDEC (args->converter / 10 == 10)
#define SLOT(x) (((args->space || args->sign) && ISDEC) || x < 0)
#define SLOTP(x) (((args->space || args->sign) && ISDEC) || result[0] == '-')
#define ZEROP (!args->left_adj * args->zero_paded)
#define PADD(x, y) ((args->padding - SLOT(x) - my_strlen(y)) * ZEROP)
#define ZPAD(x) (x->zero_paded * (x->padding - 2) * (!x->left_adj))
#define CAST(x) ((ISDEC && !(args->lm == 2)) ? (x = (int)x) : (x))

#endif /* !LIBMY_MACROS_H_ */