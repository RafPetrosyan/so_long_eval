/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:57:20 by rafpetro          #+#    #+#             */
/*   Updated: 2024/07/21 18:30:11 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	call_specifier(char c, va_list *list)
{
	if (c == 'c')
		return (ft_putchar((char)va_arg(*list, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*list, char *)));
	else if (c == 'd')
		return (ft_putnbr(va_arg(*list, int)));
	else if (c == 'i')
		return (ft_putnbr(va_arg(*list, int)));
	else if (c == 'u')
		return (ft_putnbru(va_arg(*list, unsigned int)));
	else if (c == 'p')
		return (ft_puthex(va_arg(*list, unsigned long long), 'p'));
	else if (c == 'x')
		return (ft_puthex(va_arg(*list, unsigned int), 'x'));
	else if (c == 'X')
		return (ft_puthex(va_arg(*list, unsigned int), 'X'));
	else if (c != '\0')
		return (ft_putchar(c));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	list;

	i = 0;
	count = 0;
	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count += call_specifier(format[++i], &list);
			if (format[i] != '\0')
				++i;
		}
		else
		{
			write(1, &format[i++], 1);
			++count;
		}
	}
	return (count);
}
