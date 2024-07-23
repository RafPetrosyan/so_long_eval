/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:57:39 by rafpetro          #+#    #+#             */
/*   Updated: 2024/07/22 11:21:43 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		++i;
	}
	return (i);
}

int	ft_putnbru(unsigned int n)
{
	int		i;

	i = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	ft_putnbru_helper(n, &i);
	return (i);
}

void	ft_putnbru_helper(unsigned int n, int *count)
{
	if (n != 0)
	{
		ft_putnbru_helper(n / 10, count);
		ft_putchar(n % 10 + '0');
		++(*count);
	}
}
