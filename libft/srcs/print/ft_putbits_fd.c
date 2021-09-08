/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbits_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:09:13 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/30 06:44:26 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbits_fd(size_t size, void *ptr, int fd)
{
	int				i;
	int				j;
	unsigned char	*b;
	unsigned char	byte;

	b = (unsigned char *)ptr;
	i = size - 1;
	while (i >= 0)
	{
		j = 7;
		while (j >= 0)
		{
			byte = (b[i] >> j) & 1;
			ft_putnbr_fd(byte, fd);
			j--;
		}
		i--;
	}
}
