/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:57:47 by rafpetro          #+#    #+#             */
/*   Updated: 2024/07/21 18:26:07 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	ft_putnbr_helper(n, &i);
	return (i);
}

void	ft_putnbr_helper(int n, int *count)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "-2147483648", 11);
			*count = 11;
			return ;
		}
		write(1, "-", 1);
		++(*count);
		n *= -1;
	}
	if (n / 10 > 0)
		ft_putnbr_helper(n / 10, count);
	ft_putchar(n % 10 + '0');
	++(*count);
}
