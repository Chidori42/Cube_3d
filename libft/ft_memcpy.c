/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-29 20:39:21 by ael-fagr          #+#    #+#             */
/*   Updated: 2024-07-29 20:39:21 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t					i;

	i = n;
	if (!src && !dst)
		return (0);
	else if (dst == src)
		return ((void *)src);
	while (n--)
		*(char *)dst++ = *(char *)src++;
	return (dst - i);
}
