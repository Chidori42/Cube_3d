/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-29 20:40:34 by ael-fagr          #+#    #+#             */
/*   Updated: 2024-07-29 20:40:34 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char				*s2;

	s2 = NULL;
	if (s1)
	{
		s2 = (char *)malloc(ft_strlen(s1) + 1);
		if (s2 == 0)
			return (0);
		ft_strlcpy(s2, s1, (ft_strlen(s1) + 1));
	}
	return (s2);
}
