/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:05:41 by spoliart          #+#    #+#             */
/*   Updated: 2021/06/28 21:30:47 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_end(char *s, char *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s);
	j = ft_strlen(set);
	while (i > 0 && j > 0)
		if (s[--i] != set[--j])
			return (0);
	if (j == 0)
		return (1);
	return (0);
}
