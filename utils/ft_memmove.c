/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:45:21 by rafpetro          #+#    #+#             */
/*   Updated: 2024/07/19 15:45:22 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	sr;

	i = 0;
	sr = n - 1;
	if (dest == src || n == 0)
		return (dest);
	if (src < dest)
	{
		while (i++ < n)
		{
			((unsigned char *)dest)[sr] = ((unsigned char *)src)[sr];
			--sr;
		}
		((unsigned char *)dest)[0] = ((unsigned char *)src)[0];
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			++i;
		}
	}
	return (dest);
}
