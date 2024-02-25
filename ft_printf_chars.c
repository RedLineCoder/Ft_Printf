/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:42:21 by moztop            #+#    #+#             */
/*   Updated: 2024/02/25 15:29:32 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(char chr)
{
	ft_putchar_fd(chr, 1);
	return (1);
}

int	ft_printf_chars(char *str)
{
	int	count;

	count = 0;
	if (!str)
		count += ft_putnstr_fd("(null)", 1, 6);
	else
		count += ft_putnstr_fd(str, 1, ft_strlen(str));
	return (count);
}
