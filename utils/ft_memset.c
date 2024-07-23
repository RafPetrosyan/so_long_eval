/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:45:23 by rafpetro          #+#    #+#             */
/*   Updated: 2024/07/19 15:45:24 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	a;
	char			*str;
	size_t			i;

	i = 0;
	str = (char *)b;
	a = (unsigned char)c;
	while (i < len)
		str[i++] = a;
	return (b);
}
