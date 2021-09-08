/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 13:00:49 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/25 02:26:50 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_all(char **ret, size_t i)
{
	while (--i + 1)
		free(ret[i]);
	free(ret);
	return (0);
}

static size_t	ft_wordlen(char const *s, char *set, size_t i)
{
	size_t	count;

	count = 0;
	while (s[i] && ft_charset(s[i], set))
		i++;
	while (s[i] && !(ft_charset(s[i], set)))
	{
		count++;
		i++;
	}
	return (count);
}

static size_t	ft_nb_word(char const *s, char *set)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	if (s[0] && !(ft_charset(s[0], set)))
		count++;
	while (s[i])
	{
		if (i > 0 && !(ft_charset(s[i], set)) && ft_charset(s[i - 1], set))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_fill_tab(char const *s, char *set, char *ret, size_t *i)
{
	size_t	j;

	j = 0;
	while (s[*i] && ft_charset(s[*i], set))
		(*i)++;
	while (s[*i] && !(ft_charset(s[*i], set)))
	{
		ret[j] = s[*i];
		(*i)++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char	**ft_split(char const *s, char *set)
{
	char	**ret;
	size_t	i;
	size_t	j;
	size_t	nb_word;

	i = 0;
	j = 0;
	nb_word = ft_nb_word(s, set);
	ret = malloc(sizeof(char *) * (nb_word + 1));
	if (!ret)
		return (NULL);
	while (nb_word--)
	{
		ret[j] = malloc(sizeof(char) * (ft_wordlen(s, set, i) + 1));
		if (!ret[j])
			return (ft_free_all(ret, j));
		ret[j] = ft_fill_tab(s, set, ret[j], &i);
		j++;
	}
	ret[j] = NULL;
	return (ret);
}
