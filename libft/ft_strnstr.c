/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-29 20:42:04 by ael-fagr          #+#    #+#             */
/*   Updated: 2024-07-29 20:42:04 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t					needle_len;
	size_t					i;

	i = 0;
	needle_len = ft_strlen(needle);
	if (!haystack && !len)
		return (0);
	else if (!*needle)
		return ((char *)haystack);
	while (*haystack && (i < len))
	{
		if ((*haystack == *needle) && ((len - i) >= needle_len))
			if (ft_strncmp(haystack, needle, needle_len) == 0)
				return ((char *)haystack);
		haystack++;
		i++;
	}
	return (0);
}
