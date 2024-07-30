/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-29 20:41:27 by ael-fagr          #+#    #+#             */
/*   Updated: 2024-07-29 20:41:27 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			i;

	i = 0;
	while (src[i] && (i + 1) < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (0 < dstsize)
		dst[i] = '\0';
	return (ft_strlen(src));
}
