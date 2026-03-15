/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:17:31 by pedromig          #+#    #+#             */
/*   Updated: 2025/06/23 03:10:29 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *t_new)
{
	t_list	*last_node;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = t_new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = t_new;
}
