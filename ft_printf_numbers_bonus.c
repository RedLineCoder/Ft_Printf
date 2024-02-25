/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:50:29 by moztop            #+#    #+#             */
/*   Updated: 2024/02/25 19:36:09 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*ft_base_indicator(t_log log)
{
	if (log.type == 'x')
		return ("0x");
	else
		return ("0X");
}

static	char	ft_number_sign(t_log log, int number)
{
	if (log.plus && number >= 0)
		return ('+');
	return ('-');
}

static	char	*ft_number_padding(t_log log, char *str)
{
	char	*padding;
	int		zero;

	zero = log.precision - (int)ft_strlen(str);
	if (zero < 0)
		zero = 0;
	padding = ft_calloc(sizeof(char), log.precision + 1);
	ft_memset(padding, '0', zero);
	ft_memcpy(padding + zero, str, ft_strlen(str));
	free(str);
	return (padding);
}

int	ft_printf_number_bonus(t_log log, int number)
{
	char	*str;
	int		count;

	count = 0;
	str = ft_number_str(number);
	if (number < 0 || log.plus || log.space)
		log.width--;
	if (!log.dot || (log.precision < (int)ft_strlen(str)
			&& !(number == 0 && log.precision == 0)))
		log.precision = ft_strlen(str);
	if (!log.minus && log.width > log.precision && (!log.zero || log.dot))
		count += ft_putnchar_fd(' ', 1, log.width - log.precision);
	if (number < 0 || log.plus)
		count += ft_putnchar_fd(ft_number_sign(log, number), 1, 1);
	else if (log.space)
		count += ft_putnchar_fd(' ', 1, 1);
	if (log.precision > (int)ft_strlen(str))
		str = ft_number_padding(log, str);
	if (!log.minus && log.width > log.precision && log.zero && !log.dot)
		count += ft_putnchar_fd('0', 1, log.width - log.precision);
	count += ft_putnstr_fd(str, 1, log.precision);
	if (log.minus && log.width > log.precision)
		count += ft_putnchar_fd(' ', 1, log.width - log.precision);
	free(str);
	return (count);
}

int	ft_printf_base_bonus(t_log log, unsigned int number)
{
	char	*str;
	int		count;

	count = 0;
	str = ft_printf_base_str(log, number);
	if (log.sharp && log.type != 'u' && number != 0)
		log.width -= 2;
	if (!log.dot || (log.precision < (int)ft_strlen(str) && number != 0))
		log.precision = ft_strlen(str);
	if (!log.minus && log.width > log.precision && (!log.zero || log.dot))
		count += ft_putnchar_fd(' ', 1, log.width - log.precision);
	if (log.precision > (int)ft_strlen(str))
		str = ft_number_padding(log, str);
	if (log.sharp && log.type != 'u' && number != 0)
		count += ft_putnstr_fd(ft_base_indicator(log), 1, 2);
	if (!log.minus && log.width > log.precision && log.zero && !log.dot)
		count += ft_putnchar_fd('0', 1, log.width - log.precision);
	count += ft_putnstr_fd(str, 1, log.precision);
	if (log.minus && log.width > log.precision)
		count += ft_putnchar_fd(' ', 1, log.width - log.precision);
	free(str);
	return (count);
}
