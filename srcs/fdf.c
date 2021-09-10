/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:06:28 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/09 19:47:18 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MAX(X, Y) (X > Y) ? X : Y

void	zoom(float *x, float *y, float *x1, float *y1, t_env *env)
{
	*x *= env->zoom;
	*x1 *= env->zoom;
	*y *= env->zoom;
	*y1 *= env->zoom;
}

void	isometric(float *x, float *y, float z, t_env *env)
{
	*x = (*x - *y) * cos(env->angle);
	*y = (*x + *y) * sin(env->angle) - z;
}

void	step(float *x_step, float *y_step, float x, float y, float x1, float y1)
{
	int	max;

	*x_step = x1 - x;
	*y_step = y1 - y;
	max = MAX(ABS(*x_step), ABS(*y_step));
	*x_step /= max;
	*y_step /= max;
}

void	bresenham(float x, float y, float x1, float y1, t_env *env)
{
	int	z;
	int	z1;
	int	color;
	float	x_step;
	float	y_step;

	z = env->matrix[(int)y][(int)x].z;
	z1 = env->matrix[(int)y1][(int)x1].z;
	zoom(&x, &y, &x1, &y1, env);
	color = (z || z1) ? 0xfc0345 : 0xBBFAFF;
	isometric(&x, &y, z, env);
	isometric(&x1, &y1, z1, env);
	x += 150;
	y += 150;
	x1 += 150;
	y1 += 150;
	step(&x_step, &y_step, x, y, x1, y1);
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, x, y, color);
		x += x_step;
		y += y_step;
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
