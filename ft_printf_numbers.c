/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:42:24 by moztop            #+#    #+#             */
/*   Updated: 2024/02/22 20:03:26 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_number(int number)
{
	char	*str;
	int		count;

	count = 0;
	str = ft_itoa(number);
	count = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (count);
}

int	ft_printf_base(unsigned int number, char type)
{
	char	*str;
	int		count;

	count = 0;
	if (type == 'x' || type == 'X')
	{
		if (type == 'x')
			str = ft_itobase(number, HEXALOW);
		else
			str = ft_itobase(number, HEXAUP);
		count = ft_strlen(str);
		ft_putstr_fd(str, 1);
		free(str);
		return (count);
	}
	if (type == 'u')
	{
		str = ft_itobase(number, DECIMAL);
		count = ft_strlen(str);
		ft_putstr_fd(str, 1);
		free(str);
		return (count);
	}
	return (0);
}
