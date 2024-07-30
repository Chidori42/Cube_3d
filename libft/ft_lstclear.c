/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-29 20:38:17 by ael-fagr          #+#    #+#             */
/*   Updated: 2024-07-29 20:38:17 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	struct s_list			*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = 0;
		if ((*lst)->content)
			del((*lst)->content);
		if ((*lst)->next)
			tmp = (*lst)->next;
		free (*lst);
		*lst = 0;
		*lst = tmp;
	}
}
