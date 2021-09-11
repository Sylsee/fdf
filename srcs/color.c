/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 06:34:59 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/11 10:05:21 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	get_z(t_dot a, t_dot b, t_dot c)
{
	double	z;

	if (a.y == c.y)
		z = ((b.x - a.x) / (c.x - a.x)) * (c.z - a.z) + a.z;
	else
		z = ((b.y - a.y) / (c.y - a.y)) * (c.z - a.z) + a.z;
	if (z > 30)
		z = 30;
	else if (z < -30)
		z = -30;
	return (z);
}

int	get_color(t_dot a, t_dot b, t_dot c, t_env *env)
{
	double	z;
	int	color;

	z = get_z(a, b, c);
	if (z <= 0)
	{
		color =  - z;
		color << 8 = 0xFFFFFF - z;
		color << 16 = 0xFFFFFF - z;
	}
	else
	{
		color = 0xFFFFFF - z;
		color << 8 = 0xFFFFFF - z;
		color << 16 = 0xFFFFFF - z;
	}
	if (env->colorise == 2 && !z)
		color = 0;
	return (color);
}
