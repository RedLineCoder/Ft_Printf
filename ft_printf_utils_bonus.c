/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:14:26 by moztop            #+#    #+#             */
/*   Updated: 2024/02/25 21:58:04 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnchar_fd(char c, int fd, int n)
{
	int	count;

	count = n;
	while (n--)
		ft_putchar_fd(c, fd);
	return (count);
}

int	ft_putnstr_fd(char *s, int fd, int n)
{
	write(fd, s, n);
	return (n);
}

char	*ft_printf_base_str(t_log log, unsigned int number)
{
	char	*str;

	if (log.type == 'x' || log.type == 'X')
	{
		if (log.type == 'x')
			str = ft_itobase(number, HEXALOW);
		else
			str = ft_itobase(number, HEXAUP);
	}
	else
		str = ft_itobase(number, DECIMAL);
	return (str);
}

char	*ft_number_str(int number)
{
	char	*str;
	char	*temp;

	str = ft_itoa(number);
	if (str[0] == '-')
		temp = ft_substr(str, 1, ft_strlen(str) - 1);
	else
		temp = ft_strdup(str);
	free(str);
	return (temp);
}
