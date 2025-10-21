/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:51:42 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/04 18:30:24 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_str(char *str[]);

int	main(int argc, char *argv[])
{
	int		x;
	int		y;
	char	*temp;

	if (argc < 2)
		return (1);
	x = 0;
	while (x < argc - 1)
	{
		y = 1;
		while (y < argc - x - 1)
		{
			if (ft_strcmp(argv[y], argv[y + 1]) > 0)
			{
				temp = argv[y];
				argv[y] = argv[y + 1];
				argv[y + 1] = temp;
			}
			y++;
		}
		x++;
	}
	ft_putstr_str(argv);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	x;

	x = 0;
	while (s1[x] && s2[x] && s1[x] == s2[x])
		x++;
	return (s1[x] - s2[x]);
}

void	ft_putstr_str(char *str[])
{
	int	x;
	int	y;

	x = 1;
	while (str[x])
	{
		y = 0;
		while (str[x][y])
		{
			ft_putchar(str[x][y]);
			y++;
		}
		x++;
		ft_putchar('\n');
	}
}

/*
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
*/
