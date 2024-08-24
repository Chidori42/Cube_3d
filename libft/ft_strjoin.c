/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:41:00 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/24 11:40:41 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (free(s2), NULL);
		s1[0] = '\0';
	}
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (free(s1), free(s2), NULL);
	i = -1;
	c = 0;
	while (s1 && s1[++i] != '\0')
		str[i] = s1[i];
	while (s2 && s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}
