/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-29 20:42:28 by ael-fagr          #+#    #+#             */
/*   Updated: 2024-07-29 20:42:28 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*str;
	size_t				s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	else if (len > (s_len - start))
		len = s_len - start;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, (s + start), (len + 1));
	return (str);
}
