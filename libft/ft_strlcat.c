/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-29 20:41:18 by ael-fagr          #+#    #+#             */
/*   Updated: 2024-07-29 20:41:18 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t				dstlen;
	size_t				srclen;
	size_t				ref;

	srclen = ft_strlen(src);
	if (!dst && !dstsize)
		return (srclen);
	dstlen = ft_strlen(dst);
	ref = dstlen;
	if (dstsize < dstlen)
		return (dstsize + srclen);
	while (*src && (dstlen + 1) < dstsize)
	{
		dst[dstlen] = *src;
		dstlen++;
		src++;
	}
	if (ref < dstlen)
		dst[dstlen] = '\0';
	return (ref + srclen);
}
