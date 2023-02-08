/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:33:27 by ibenaait          #+#    #+#             */
/*   Updated: 2023/02/08 16:28:17 by ibenaait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**alloc_word_m(char const *s, char sep, size_t *wc)
{
	size_t	pos;
	size_t	count;
	char	**sp;

	if (!s)
		return (0);
	pos = 0;
	count = 0;
	while (s[pos])
	{
		while (s[pos] != '\0' && s[pos] == sep)
			pos++;
		if (s[pos] && s[pos] != sep)
			count++;
		while (s[pos] && s[pos] != sep)
			pos++;
	}
	*wc = count;
	sp = malloc(sizeof(char *) * (*wc + 1));
	if (!sp)
		return (NULL);
	return (sp);
}

static char	*al_word_sup(char const *s, char sep)
{
	size_t	word_len;
	char	*wp;

	word_len = 0;
	while (s[word_len] && s[word_len] != sep)
		word_len++;
	wp = ft_substr(s, 0, word_len);
	return (wp);
}

static char	**ft_free_up(char **s, size_t max)
{
	size_t	i;

	i = 0;
	while (i <= max)
	{
		if (s[i])
			free(s[i]);
		i++;
	}
	free(s);
	return (0);
}

static char	**check_for_alloc_error(char **s, size_t wc, size_t max)
{
	size_t	i;

	i = 0;
	while (max < wc && i <= max)
	{
		if (!s[i])
			return (ft_free_up(s, max));
		i++;
	}
	s[wc] = 0;
	return (s);
}

char	**ft_split(char const *s, char c)
{
	size_t	wc;
	char	**sp;
	size_t	pos;
	size_t	i;

	sp = alloc_word_m(s, c, &wc);
	if (!sp)
		return (0);
	pos = 0;
	i = 0;
	while (i < wc)
	{
		while (s[pos] && s[pos] == c)
			pos++;
		if (s[pos] && s[pos] != c)
		{
			sp[i] = al_word_sup(s + pos, c);
			if (!sp[i])
				break ;
			i++;
		}
		while (s[pos] && s[pos] != c)
			pos++;
	}
	return (check_for_alloc_error(sp, wc, i));
}
