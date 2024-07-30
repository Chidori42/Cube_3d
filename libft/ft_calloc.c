/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-29 20:37:04 by ael-fagr          #+#    #+#             */
/*   Updated: 2024-07-29 20:37:04 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*ptr;

	if (!count || !size || ((SSIZE_MAX / count) < size) || \
		((SSIZE_MAX / size) < count))
		return (NULL);
	ptr = (char *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ptr[0] = '\0';
	ptr[count * size - 1] = '\0';
	return (ptr);
}
