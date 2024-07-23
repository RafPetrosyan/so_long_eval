/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:45:18 by rafpetro          #+#    #+#             */
/*   Updated: 2024/07/22 17:58:10 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2, int read_size)
{
	char	*str;

	if (s1 == 0)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	str = (char *)malloc((ft_strlen1(s1)
				+ ft_strlen1(s2) + 1) * (sizeof(char)));
	if (str == 0)
		return (0);
	ft_strjoin_helper(s1, s2, str, read_size);
	return (str);
}
