/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:41:55 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/25 11:59:10 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;

	i = 0;
	while (s1[i] && (s1[i] == s2[i]))
		i++;
	if (s1 && s2)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
