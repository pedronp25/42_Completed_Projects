/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:22:41 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/30 17:57:58 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_ultimate_initializer(int *bytes_read,
		int *nl_check, char **return_str)
{
	*bytes_read = 0;
	*nl_check = 0;
	*return_str = NULL;
}

int	ft_strlen_nl(char *str)
{
	int	x;

	x = 0;
	if (!str)
		return (0);
	while (str[x] && str[x] != '\n')
		x++;
	if (str[x] == '\n')
		x++;
	return (x);
}

char	*ft_strjoin_nl(char *s1, char *s2)
{
	int		x;
	int		y;
	char	*final_str;

	x = 0;
	y = 0;
	final_str = malloc(ft_strlen_nl(s1) + ft_strlen_nl(s2) + 1);
	if (!final_str)
		return (free(s1), NULL);
	while (s1 && s1[x])
	{
		final_str[x] = s1[x];
		x++;
	}
	while (s2 && s2[y])
	{
		final_str[x] = s2[y];
		x++;
		if (s2[y] == '\n')
			break ;
		y++;
	}
	final_str[x] = '\0';
	return (free(s1), final_str);
}

int	ft_cleanup_str(char *str)
{
	int	check;
	int	x;
	int	y;

	x = 0;
	y = 0;
	check = 0;
	while (str[x])
	{
		if (check)
		{
			str[y] = str[x];
			y++;
		}
		if (str[x] == '\n')
			check = 1;
		str[x] = '\0';
		x++;
	}
	while (y < x)
	{
		str[y] = '\0';
		y++;
	}
	return (check);
}
