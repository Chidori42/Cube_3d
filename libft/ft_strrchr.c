/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-29 20:42:11 by ael-fagr          #+#    #+#             */
/*   Updated: 2024-07-29 20:42:11 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t				slen;

	slen = ft_strlen(s);
	s += slen;
	while ((*s != (char)c) && slen--)
		s--;
	if (*s == (char)c)
		return ((char *) s);
	return (0);
}
