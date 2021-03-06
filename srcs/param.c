/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:41:39 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/11 09:30:47 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(double *x, double *y, double z, t_env *env)
{
	*x = (*x - *y) * cos(env->angle);
	*y = (*x + *y) * sin(env->angle) - z;
}

void	shift(t_dot *a, t_dot *b, t_env *env)
{
	a->x += env->x_shift;
	b->x += env->x_shift;
	a->y += env->y_shift;
	b->y += env->y_shift;
}

void	zoom(t_dot *a, t_dot *b, t_env *env)
{
	a->x *= env->zoom;
	b->x *= env->zoom;
	a->y *= env->zoom;
	b->y *= env->zoom;
	a->z *= env->z_zoom;
	b->z *= env->z_zoom;
}
