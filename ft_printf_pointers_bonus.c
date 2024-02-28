/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointers_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:50:44 by moztop            #+#    #+#             */
/*   Updated: 2024/02/28 19:19:45 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_pointers_bonus(t_log *log, unsigned long address)
{
	int	count;
	int	temp;

	count = 0;
	log->width -= 2;
	if (log->precision < ft_printf_number_length_address(address))
		log->precision = ft_printf_number_length_address(address);
	count = ft_printf_zero_space_flags(log);
	if (count == -1)
		return (-1);
	temp = ft_printf_pointers(address);
	if (temp == -1)
		return (-1);
	count += temp;
	temp = 0;
	if (log->minus && log->width > log->precision)
		temp = ft_putnchar_fd(' ', 1, log->width - log->precision);
	if (temp == -1)
		return (-1);
	count += temp;
	return (count);
}
