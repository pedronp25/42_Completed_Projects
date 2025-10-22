/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:23:31 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/30 17:55:25 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	ft_ultimate_initializer(int *bytes_read,
			int *nl_check, char **return_str);
int		ft_strlen_nl(char	*str);
char	*ft_strjoin_nl(char *s1, char *s2);
int		ft_cleanup_str(char *str);

#endif
