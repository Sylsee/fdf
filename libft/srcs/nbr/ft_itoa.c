/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:23:56 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/25 02:27:51 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	long	tmp;
	char	*str;

	tmp = n;
	i = ft_nbrlen(tmp);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (tmp < 0)
	{
		str[0] = '-';
		tmp *= -1;
	}
	i--;
	while (tmp > 9)
	{
		str[i] = tmp % 10 + '0';
		tmp /= 10;
		i--;
	}
	str[i] = tmp % 10 + '0';
	return (str);
}
