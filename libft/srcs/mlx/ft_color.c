/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 00:20:06 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/12 00:26:50 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_r(int c)
{
	return (c >> 16);
}

int	ft_g(int c)
{
	return ((c >> 8) & 0xFF);
}

int	ft_b(int c)
{
	return (c & 0xFF);
}

int	ft_rgb(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}
