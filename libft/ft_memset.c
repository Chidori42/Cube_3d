/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-29 20:39:37 by ael-fagr          #+#    #+#             */
/*   Updated: 2024-07-29 20:39:37 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			ref;

	ref = len;
	while (len--)
	{
		*(unsigned char *)b = (unsigned char)c;
		b++;
	}
	return (b - ref);
}
