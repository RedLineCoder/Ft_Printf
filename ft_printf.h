/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:56:04 by moztop            #+#    #+#             */
/*   Updated: 2024/02/25 21:57:57 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "LIBFT/libft.h"

/* 
The structure of a variable given to printf function
%[parameter][flags][width][.precision][length]type
*/

/*
First we will track log for structure in order to format input value
*/

typedef struct s_log
{
	int		minus;
	int		plus;
	int		width;
	int		precision;
	int		dot;
	char	type;
	int		zero;
	int		space;
	int		sharp;
}	t_log;

/* String containing printf's parameters */
# define TYPE		"cspdiuxX%"

/* Lower hexadecimal base */
# define HEXALOW	"0123456789abcdef"

/* Upper hexadecimal base */
# define HEXAUP		"0123456789ABCDEF"

/* Decimal base */
# define DECIMAL	"0123456789"

/* MANDATORY */

int		ft_printf(const char *start, ...);
char	*ft_itobase(unsigned int n, char *base);
char	*ft_longtobase(unsigned long n, char *base);
int		ft_printf_char(char chr);
int		ft_printf_chars(char *str);
int		ft_printf_number(int number);
int		ft_printf_base(unsigned int number, char type);
int		ft_printf_pointers(unsigned	long address);

/* BONUS */

int		ft_printf_bonus(const char *start, ...);
int		ft_printf_parse(char *start, va_list args);
int		ft_printf_print_type_bonus(t_log log, va_list args);
int		ft_printf_char_bonus(t_log log, char chr);
int		ft_printf_chars_bonus(t_log log, char *str);
int		ft_printf_number_bonus(t_log log, int number);
int		ft_printf_base_bonus(t_log log, unsigned int number);
int		ft_printf_pointers_bonus(t_log log, unsigned long address);

/* UTILS */

int		ft_putnchar_fd(char c, int fd, int n);
int		ft_putnstr_fd(char *s, int fd, int n);
char	*ft_printf_base_str(t_log log, unsigned int number);
char	*ft_number_str(int number);

#endif