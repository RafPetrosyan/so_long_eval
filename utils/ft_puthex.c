/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:57:56 by rafpetro          #+#    #+#             */
/*   Updated: 2024/07/21 18:26:00 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_puthex_helper(unsigned long long p, char *hex, int *count)
{
	if (p / 16 != 0)
		ft_puthex_helper(p / 16, hex, count);
	ft_putchar(hex[p % 16]);
	++(*count);
}

int	ft_puthex(unsigned long long p, char spec)
{
	int		count;
	char	*a;
	char	*b;

	a = "0123456789abcdef";
	b = "0123456789ABCDEF";
	count = 0;
	if (spec == 'p')
	{
		write(1, "0x", 2);
		count += 2;
	}
	if (spec == 'x' || spec == 'p')
		ft_puthex_helper(p, a, &count);
	else
		ft_puthex_helper(p, b, &count);
	return (count);
}
