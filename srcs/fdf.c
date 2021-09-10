/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:06:28 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/10 06:27:34 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	isometric(float *x, float *y, float z, t_env *env)
{
	*x = (*x - *y) * cos(env->angle);
	*y = (*x + *y) * sin(env->angle) - z;
}

static void	step(float *x_step, float *y_step, t_dot a, t_dot b)
{
	int	max;

	*x_step = b.x - a.x;
	*y_step = b.y - a.y;
	max = ft_max(ft_abs(*x_step), ft_abs(*y_step));
	*x_step /= max;
	*y_step /= max;
}

void	shift(t_dot *a, t_dot *b, t_env *env)
{
	a->x += env->x_shift;
	b->x += env->x_shift;
	a->y += env->y_shift;
	b->y += env->y_shift;
	a->z += env->z_shift;
	b->z += env->z_shift;
}

static void	zoom(t_dot *a, t_dot *b, t_env *env)
{
	a->x *= env->zoom;
	b->x *= env->zoom;
	a->y *= env->zoom;
	b->y *= env->zoom;
}

void	param(t_dot *a, t_dot *b, t_env *env)
{
	zoom(a, b, env);
}

static void	bresenham(t_dot a, t_dot b, t_env *env)
{
	int		color;
	float	x_step;
	float	y_step;

	param(&a, &b, env);
	color = (a.z || b.z) ? 0xfc0345 : 0xBBFAFF;
	if (env->isometric)
	{
		isometric(&(a.x), &(a.y), a.z, env);
		isometric(&(b.x), &(b.y), b.z, env);
	}
	shift(&a, &b, env);
	step(&x_step, &y_step, a, b);
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, a.x, a.y, color);
		a.x += x_step;
		a.y += y_step;
	}
}

void	fdf(t_env *env)
{
	int	x;
	int	y;

	y = -1;
	while (++y < env->height)
	{
		x = -1;
		while (++x < env->width)
		{
			if (x < env->width - 1)
				bresenham(env->matrix[y][x], env->matrix[y][x + 1], env);
			if (y < env->height - 1)
				bresenham(env->matrix[y][x], env->matrix[y + 1][x], env);
		}
	}
}
//	printf("x: [%d]\ny: [%d]\n", x, y);
