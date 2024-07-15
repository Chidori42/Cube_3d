/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:07:25 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/02/09 12:01:45 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_ber(char *str)
{
	char	*s;
	int		len;
	int		i;

	s = ft_strrchr(str, '.');
	if (!s)
		return (1);
	len = ft_strlen(s);
	i = ft_strncmp(s, ".ber", len);
	return (i);
}
