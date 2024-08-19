/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:40:09 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/19 03:14:05 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static size_t	ft_wrdlen(char const *s)
{
	size_t				wrd_len;

	wrd_len = 0;
	while (*s && !is_white_space(*s) && ++wrd_len)
		s++;
	return (wrd_len);
}

static void	ft_free_mem(char **strs)
{
	size_t			i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		strs[i] = 0;
		i++;
	}
	free (strs);
	strs = 0;
}

static size_t	ft_count_words(char const *s)
{
	size_t				count;

	count = 0;
	while (*s)
	{
		while (*s && is_white_space(*s))
			s++;
		if (*s && !is_white_space(*s))
			count++;
		while (*s && !is_white_space(*s))
			s++;
	}
	return (count);
}

char	**my_split(char const *s)
{
	char			**ref;
	char			**strs;

	if (!s)
		return (NULL);
	strs = (char **)malloc(sizeof(char *) * \
		(ft_count_words(s) + 1));
	if (!strs)
		return (NULL);
	ref = strs;
	while (*s)
	{
		while (*s && is_white_space(*s))
			s++;
		if (!(*s))
			break ;
		*strs = ft_substr(s, 0, ft_wrdlen(s));
		if (!(*strs++))
			return (ft_free_mem(ref), NULL);
		s += ft_wrdlen(s);
	}
	*strs = NULL;
	return (ref);
}
