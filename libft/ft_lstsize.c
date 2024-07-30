/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-29 20:38:57 by ael-fagr          #+#    #+#             */
/*   Updated: 2024-07-29 20:38:57 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t			lst_len;

	lst_len = 0;
	if (lst == 0)
		return (0);
	while (++lst_len && lst->next)
		lst = lst->next;
	return (lst_len);
}
