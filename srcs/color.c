/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 06:34:59 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/11 10:27:34 by spoliart         ###   ########.fr       */
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
	int		new[3];
	int		new_color;
	double	increment[3];
	double	z;

	z = get_z(a, b, c);
	increment[0] = (double)((R(env->end_color)) - (R(env->start_color))) /
					(double)(a.);
	increment[1] = (double)((G(env->end_color)) - (G(env->start_color))) /
					(double)len;
	increment[2] = (double)((B(env->end_color)) - (B(env->start_color))) /
					(double)len;

	new[0] = (R(env->start_color)) + ft_round(pix * increment[0]);
	new[1] = (G(env->start_color)) + ft_round(pix * increment[1]);
	new[2] = (B(env->start_color)) + ft_round(pix * increment[2]);

	new_color = RGB(new[0], new[1], new[2]);
	return (new_color);
}
/*
   double	z;
   int		color[3];

   z = get_z(a, b, c);
   color[1] =  - z;
   color[2] = 0xFFFFFF - z;
   color[2] = 0xFFFFFF - z;
   if (env->colorise == 2 && !z)
   color = 0;
   return (color);*/
