/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:30:48 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/25 02:28:09 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itox(int nb)
{
	int		n;
	int		len;
	char	*ret;

	if (nb < 0)
		nb *= -1;
	n = nb;
	len = 0;
	while (nb)
		nb /= 16 + 0 * len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	if (!len)
		ret[len++] = '0';
	ret[len] = '\0';
	while (len--)
	{
		if (n % 16 < 10)
			ret[len] = n % 16 + 48;
		else
			ret[len] = n % 16 + 55;
		n /= 16;
	}
	return (ret);
}
