/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:45:40 by rafpetro          #+#    #+#             */
/*   Updated: 2024/07/22 11:21:58 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	ft_strlen1(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			++i;
			return (i);
		}
		++i;
	}
	return (i);
}

void	ft_strjoin_helper(char *s1, char *s2, char *str, int read_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		++i;
	}
	free(s1);
	while (s2[j] != '\0' && j < read_size && s2[j] != '\n')
	{
		str[i + j] = s2[j];
		++j;
	}
	if (s2[j] == '\n')
	{
		str[i + j] = s2[j];
		++j;
	}
	str[i + j] = '\0';
}

void	rearrange(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j] != '\0' && j < BUFFER_SIZE)
	{
		if (str[j] == '\n')
		{
			++j;
			break ;
		}
		++j;
	}
	while (j < BUFFER_SIZE && str[j] != '\0')
	{
		str[i] = str[j];
		++i;
		++j;
	}
	while (i < BUFFER_SIZE && str[i] != '\0')
		str[i++] = '\0';
}

int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int			read_size;
	char		*ret;
	char		*temp;
	static char	buffer[BUFFER_SIZE];

	temp = 0;
	ret = 0;
	if (buffer[0] != '\0')
	{
		temp = ft_strjoin(temp, buffer, BUFFER_SIZE);
		rearrange(buffer);
		if (ft_check(temp) == 1)
			return (temp);
	}
	read_size = read(fd, buffer, BUFFER_SIZE);
	while (read_size > 0)
	{
		ret = ft_strjoin(temp, buffer, read_size);
		temp = ret;
		rearrange(buffer);
		if (ft_check(ret) == 1)
			return (ret);
		read_size = read(fd, buffer, BUFFER_SIZE);
	}
	return (temp);
}
