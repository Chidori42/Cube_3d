/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-29 20:38:51 by ael-fagr          #+#    #+#             */
/*   Updated: 2024-07-29 20:38:51 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list			*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->content = content;
	new_node->next = 0;
	return (new_node);
}
