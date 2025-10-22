/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:17:31 by pedromig          #+#    #+#             */
/*   Updated: 2025/10/22 23:16:24 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newlst)
{
	t_list	*last_node;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = newlst;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = newlst;
}
