/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:47:17 by spoliart          #+#    #+#             */
/*   Updated: 2021/06/28 21:37:37 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	res;

	while (n--)
	{
		res = *((unsigned char *)s1++) - *((unsigned char *)s2++);
		if (res)
			return (res);
	}
	return (0);
}
