/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 01:03:45 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/17 19:45:19 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int	beg;
	int	end;

	beg = 0;
	end = ft_strlen(s1);
	while (is_set(s1[beg], set))
		beg++;
	while (is_set(s1[end - 1], set))
		end--;
	return (ft_substr(s1, beg, (end - beg)));
}

static int	is_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	printf("Returned String: %s\n", ft_strtrim("cabbcameowaababc", "abc"));
}
*/
