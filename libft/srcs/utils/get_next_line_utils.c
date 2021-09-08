/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:08:12 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/25 02:30:28 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_chr_gnl(char *s, int c)
{
	size_t	i;

	i = 0;
	if (s)
		while (s[i] && s[i] != c)
			i++;
	return (i);
}

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

int	ft_check_gnl(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (1);
	while (s[++i])
		if (s[i] == '\n')
			return (0);
	return (1);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	j = ft_strlen_gnl((char *)s1) + ft_strlen_gnl((char *)s2);
	ret = malloc(sizeof(char) * (j + 1));
	if (!ret)
		return (NULL);
	j = -1;
	if (s1)
		while (s1[++j])
			ret[i++] = s1[j];
	j = -1;
	if (s2)
		while (s2[++j])
			ret[i++] = s2[j];
	ret[i] = '\0';
	free((char *)s1);
	return (ret);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	size_t	n;
	size_t	i;
	size_t	size;
	char	*ret;

	i = 0;
	n = ft_strlen_gnl(s);
	if (!s || start > n)
		return (0);
	if (len > n + 1)
		size = n;
	else
		size = len;
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	while (s[start + i] && i < len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
