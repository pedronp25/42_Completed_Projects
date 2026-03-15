/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:08:51 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/17 18:38:08 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node_ptr;
	t_list	*temp;

	if (!lst || !del)
		return ;
	node_ptr = *lst;
	while (node_ptr)
	{
		temp = node_ptr;
		node_ptr = node_ptr->next;
		ft_lstdelone(temp, del);
	}
	*lst = NULL;
}
