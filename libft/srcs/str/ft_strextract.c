/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strextract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:39:57 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/25 02:27:07 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isset(char const c, char const *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

int	ft_strlen_set(char const *str, char const *set)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (ft_isset(str[i], set))
			continue ;
		count++;
	}
	return (count);
}

char	*ft_strextract(char const *s, char const *set)
{
	int		i;
	int		j;
	char	*ret;

	i = -1;
	j = 0;
	if (!s)
		return (NULL);
	ret = malloc(sizeof(char) * (ft_strlen_set(s, set) + 1));
	if (!ret)
		return (NULL);
	while (s[++i])
	{
		if (ft_isset(s[i], set))
			continue ;
		ret[j] = s[i];
		j++;
	}
	ret[j] = '\0';
	return (ret);
}
