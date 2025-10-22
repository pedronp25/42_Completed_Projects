/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:35:15 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/14 01:09:49 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = n * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	return (ft_bzero(ptr, total_size));
}

/*
int	main(void)
{
	size_t	n = 5;
	size_t	size = sizeof(int);

	// Test calloc function
	int	*arr = (int *)ft_calloc(n, size);

	if (arr == NULL) {
		printf("Memory allocation failed\n");
		return 1;
	}

	// Print the allocated memory (should be all zeros)
	for (size_t i = 0; i < n; i++) {
		printf("arr[%zu] = %d\n", i, arr[i]);
	}

	// Free the allocated memory
	free(arr);

	return 0;
}
*/
