/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longtobase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:30:15 by moztop            #+#    #+#             */
/*   Updated: 2024/02/22 19:53:17 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_length(unsigned long n, char	*base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= ft_strlen(base);
		len++;
	}
	return (len);
}

static char	*handle(unsigned long num, char *table, int len, char *base)
{
	int		index;
	int		size;

	index = 0;
	size = len - 1;
	while (size >= index)
	{
		table[size--] = base[(num % ft_strlen(base))];
		num /= ft_strlen(base);
	}
	table[len] = '\0';
	return (table);
}

char	*ft_longtobase(unsigned long n, char *base)
{
	int		len;
	char	*table;
	long	num;

	num = n;
	len = ft_length(num, base);
	table = (char *)malloc(sizeof(char) * len + 1);
	if (!table)
		return (free(table), NULL);
	return (handle(num, table, len, base));
}
