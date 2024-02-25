/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:56:10 by moztop            #+#    #+#             */
/*   Updated: 2024/02/23 17:02:53 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_printf_print_type(char spec, va_list args)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count = ft_printf_char(va_arg(args, int));
	if (spec == '%')
		count = ft_printf_char('%');
	if (spec == 's')
		count = ft_printf_chars(va_arg(args, char *));
	if (spec == 'x' || spec == 'X' || spec == 'u')
		count = ft_printf_base(va_arg(args, unsigned int), spec);
	if (spec == 'd' || spec == 'i')
		count = ft_printf_number(va_arg(args, int));
	if (spec == 'p')
		count = ft_printf_pointers(va_arg(args, unsigned long));
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		count;

	if (!input)
		return (0);
	va_start(args, input);
	count = 0;
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			while (*input == ' ' && *input)
				input++;
			count += ft_printf_print_type(*input, args);
		}
		else
		{
			ft_putchar_fd(*input, 1);
			count++;
		}
		input++;
	}
	va_end(args);
	return (count);
}
