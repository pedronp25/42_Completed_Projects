/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:26:59 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/13 20:48:14 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	size;

	size = ft_strlen(s) + 1;
	copy = malloc(size);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s, size);
	return (copy);
}

/*
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);

	printf("Duplicated string: %s", ft_strdup(argv[1]));
}
*/
