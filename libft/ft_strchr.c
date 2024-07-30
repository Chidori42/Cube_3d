/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-29 20:40:22 by ael-fagr          #+#    #+#             */
/*   Updated: 2024-07-29 20:40:22 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s || !c)
		return (NULL);
	while (*s && (*s != (char)c))
		s++;
	if ((*s == (char)c) || ((char)c == '\0'))
		return ((char *) s);
	return (0);
}
