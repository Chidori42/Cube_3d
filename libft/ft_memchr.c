/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-29 20:39:09 by ael-fagr          #+#    #+#             */
/*   Updated: 2024-07-29 20:39:09 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*str;

	str = (unsigned char *)s;
	while (0 < n--)
		if (*str++ == (unsigned char)c)
			return (--str);
	return (0);
}
