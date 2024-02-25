/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:45:03 by moztop            #+#    #+#             */
/*   Updated: 2024/02/25 22:40:07 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_log	ft_printf_log_init(void)
{
	t_log	log;

	log.minus = 0;
	log.type = 0;
	log.plus = 0;
	log.precision = 0;
	log.dot = 0;
	log.sharp = 0;
	log.space = 0;
	log.width = 0;
	log.zero = 0;
	return (log);
}

static	t_log	ft_printf_parse_flags(t_log	log, char	*start)
{
	while (*start != '.' && !ft_strchr(TYPE, *start) && *start)
	{
		if (*start == '+')
			log.plus = 1;
		if (*start == '-')
			log.minus = 1;
		if (*start == '#')
			log.sharp = 1;
		if (*start == '0' && !ft_isdigit(*(start - 1)))
			log.zero = 1;
		if (*start == ' ')
			log.space = 1;
		start++;
	}
	return (log);
}

static	t_log	ft_printf_parse_width(t_log	log, char	*start, va_list	args)
{
	size_t	length;

	length = 0;
	while (*start != '.' && !ft_strchr(TYPE, *start) && *start)
	{
		if ((ft_isdigit(*start) && *start > '0') || *start == '*')
		{
			if (*start == '*')
				log.width = va_arg(args, int);
			else
			{
				log.width = ft_atoi(start);
				while (ft_isdigit(*start))
					start++;
			}
		}
		else
			start++;
	}
	return (log);
}

static	t_log	ft_printf_parse_precision(t_log log, char *start, va_list args)
{
	size_t	length;

	length = 0;
	while (!ft_strchr(TYPE, *start) && *start)
	{
		if ((ft_isdigit(*start) && *start > '0') || *start == '*')
		{
			if (*start == '*')
				log.precision = va_arg(args, int);
			else
			{
				log.precision = ft_atoi(start);
				while (ft_isdigit(*start))
					start++;
			}
		}
		else
			start++;
	}
	return (log);
}

int	ft_printf_parse(char *start, va_list args)
{
	t_log	log;

	log = ft_printf_parse_flags(ft_printf_log_init(), start);
	log = ft_printf_parse_width(log, start, args);
	while (*start != '.' && !ft_strchr(TYPE, *start) && *start)
		start++;
	if (*start == '.')
	{
		log.dot = 1;
		log = ft_printf_parse_precision(log, start, args);
	}
	while (!ft_strchr(TYPE, *start) && *start)
		start++;
	log.type = *start;
	return (ft_printf_print_type_bonus(log, args));
}
