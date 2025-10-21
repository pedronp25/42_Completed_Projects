/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:22:52 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/13 15:25:40 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2);
void	ft_strswap(char **s1, char **s2);
void	ft_put_str(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	int	x;
	int	y;
	int	cmp;

	x = 0;
	while (x < argc - 1)
	{
		y = 1;
		while (y < argc - x - 1)
		{
			cmp = ft_strcmp(argv[y], argv[y + 1]);
			if (cmp > 0)
			{
				ft_strswap(&argv[y], &argv[y + 1]);
			}
			y++;
		}
		x++;
	}
	ft_put_str(argc, argv);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	x;

	x = 0;
	while (s1[x] && s2[x] && s1[x] == s2[x])
		x++;
	return (s1[x] - s2[x]);
}

void	ft_strswap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	ft_put_str(int argc, char *argv[])
{
	int	x;
	int	y;

	x = 1;
	while (x < argc)
	{
		y = 0;
		while (argv[x][y])
		{
			write(1, &argv[x][y], 1);
			y++;
		}
		write(1, "\n", 1);
		x++;
	}
}
