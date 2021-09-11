/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 06:34:59 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/12 00:15:47 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define R(a) (a) >> 16
#define G(a) ((a) >> 8) & 0xFF
#define B(a) (a) & 0xFF
#define RGB(a, b, c) ((a) << 16) + ((b) << 8) + (c)

static double	get_z(t_dot a, t_dot b, t_dot c)
{
	double	z;

	if (a.y == c.y)
		z = ((b.x - a.x) / (c.x - a.x)) * (c.z - a.z) + a.z;
	else
		z = ((b.y - a.y) / (c.y - a.y)) * (c.z - a.z) + a.z;
	return (z);
}

int	get_color(t_dot a, t_dot b, t_dot c, t_env *env)
{
	int		color;
	int		new[3];
	double	increment[3];

	b.z = get_z(a, b, c);
	if (env->colorise == 2 && b.z == 0)
		return (0);
	else if (b.z == 0)
		return (env->start_color);
	increment[0] = (double)((R(env->end_color)) - (R(env->start_color)))
					/ (env->z_len * env->z_zoom);
	increment[1] = (double)((G(env->end_color)) - (G(env->start_color)))
					/ (env->z_len * env->z_zoom);
	increment[2] = (double)((B(env->end_color)) - (B(env->start_color)))
					/ (env->z_len * env->z_zoom);
	new[0] = (R(env->start_color)) + ft_round(b.z * increment[0]);
	new[1] = (G(env->start_color)) + ft_round(b.z * increment[1]);
	new[2] = (B(env->start_color)) + ft_round(b.z * increment[2]);
	color = RGB(new[0], new[1], new[2]);
	return (color);
}
