/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-29 20:39:15 by ael-fagr          #+#    #+#             */
/*   Updated: 2024-07-29 20:39:15 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!n)
		return (0);
	while (--n && (*(unsigned char *)s1) == (*(unsigned char *)s2))
	{
		s2++;
		s1++;
	}
	return ((*(unsigned char *)s1) - (*(unsigned char *)s2));
}
