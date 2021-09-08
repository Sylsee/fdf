/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 20:20:31 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/25 02:25:46 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_charset(char const c, char const *set)
{
	size_t	i;

	i = -1;
	if (set)
		while (set[++i])
			if (set[i] == c)
				return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*pt;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen((char *)s1) - 1;
	if ((int)len == -1)
		return (ft_strdup(""));
	while (s1[i] && ft_is_charset(s1[i], set))
		i++;
	while (len >= i && ft_is_charset(s1[len], set))
		len--;
	pt = malloc(sizeof(char) * (len - i + 2));
	if (!pt)
		return (0);
	while (i <= len)
		pt[j++] = s1[i++];
	pt[j] = '\0';
	return (pt);
}
