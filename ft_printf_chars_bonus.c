/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:50:13 by moztop            #+#    #+#             */
/*   Updated: 2024/02/25 22:42:01 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char_bonus(t_log log, char chr)
{
	int	count;

	count = 0;
	log.precision = 1;
	if (log.minus == 0 && log.width > log.precision && log.zero == 1)
		count += ft_putnchar_fd('0', 1, log.width - log.precision);
	else if (log.minus == 0 && log.width > log.precision)
		count += ft_putnchar_fd(' ', 1, log.width - log.precision);
	count += ft_putnchar_fd(chr, 1, log.precision);
	if (log.minus == 1 && log.width > log.precision)
		count += ft_putnchar_fd(' ', 1, log.width - log.precision);
	return (count);
}

int	ft_printf_chars_bonus(t_log log, char *str)
{
	int		count;
	char	*print;

	count = 0;
	print = NULL;
	if (str == NULL)
		print = ft_strdup("(null)");
	else
		print = ft_strdup(str);
	if (!log.dot || log.precision > (int)ft_strlen(print))
		log.precision = ft_strlen(print);
	if (!log.minus && log.width > log.precision && log.zero)
		count += ft_putnchar_fd('0', 1, log.width - log.precision);
	else if (!log.minus && log.width > log.precision)
		count += ft_putnchar_fd(' ', 1, log.width - log.precision);
	count += ft_putnstr_fd(print, 1, log.precision);
	if (log.minus && log.width > log.precision)
		count += ft_putnchar_fd(' ', 1, log.width - log.precision);
	free(print);
	return (count);
}
