/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 00:30:47 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/12 00:31:21 by spoliart         ###   ########.fr       */
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
	increment[0] = (double)((ft_r(env->end_color)) - (ft_r(env->start_color)))
		/ (env->z_len * env->z_zoom);
	increment[1] = (double)((ft_g(env->end_color)) - (ft_g(env->start_color)))
		/ (env->z_len * env->z_zoom);
	increment[2] = (double)((ft_b(env->end_color)) - (ft_b(env->start_color)))
		/ (env->z_len * env->z_zoom);
	new[0] = (ft_r(env->start_color)) + ft_round(b.z * increment[0]);
	new[1] = (ft_g(env->start_color)) + ft_round(b.z * increment[1]);
	new[2] = (ft_b(env->start_color)) + ft_round(b.z * increment[2]);
	color = ft_rgb(new[0], new[1], new[2]);
	return (color);
}
