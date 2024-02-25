/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointers_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:50:44 by moztop            #+#    #+#             */
/*   Updated: 2024/02/25 17:17:17 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_pointers_bonus(t_log log, unsigned long address)
{
	char	*str;
	int		count;

	count = 0;
	str = ft_longtobase(address, HEXALOW);
	log.width -= 2;
	if (log.precision < (int)ft_strlen(str))
		log.precision = ft_strlen(str);
	if (log.minus == 0 && log.width > log.precision && log.zero == 1)
		count += ft_putnchar_fd('0', 1, log.width - log.precision);
	else if (log.minus == 0 && log.width > log.precision && log.zero == 0)
		count += ft_putnchar_fd(' ', 1, log.width - log.precision);
	count += ft_putnstr_fd("0x", 1, 2);
	count += ft_putnstr_fd(str, 1, log.precision);
	if (log.minus == 1 && log.width > log.precision)
		count += ft_putnchar_fd(' ', 1, log.width - log.precision);
	free(str);
	return (count);
}
