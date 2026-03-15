/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:08:21 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/13 23:27:57 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_size;

	s1_len = ft_strlen(s1) + 1;
	s2_len = ft_strlen(s2) + 1;
	total_size = s1_len + s2_len;
	final_str = malloc(total_size - 1);
	if (!final_str)
		return (NULL);
	ft_strlcpy(final_str, s1, s1_len);
	ft_strlcat(final_str, s2, total_size);
	return (final_str);
}

/*
int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (1);

	printf("Final String: %s\n", ft_strjoin(argv[1], argv[2]));
}
*/
