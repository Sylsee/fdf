/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:06:28 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/12 00:17:07 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_step(double *x_step, double *y_step, t_dot a, t_dot b)
{
	int	max;

	*x_step = b.x - a.x;
	*y_step = b.y - a.y;
	max = ft_max(ft_abs(*x_step), ft_abs(*y_step));
	*x_step /= max;
	*y_step /= max;
}

static void	bresenham(t_dot b, t_dot c, t_env *env)
{
	int		color;
	t_dot	a;
	t_dot	step;

	color = 0xFFFFFF;
	zoom(&b, &c, env);
	if (env->isometric)
	{
		isometric(&(b.x), &(b.y), b.z, env);
		isometric(&(c.x), &(c.y), c.z, env);
	}
	shift(&b, &c, env);
	a = b;
	(void)a;
	get_step(&(step.x), &(step.y), b, c);
	while ((int)(b.x - c.x) || (int)(b.y - c.y))
	{
		if (env->colorise)
			color = get_color(a, b, c, env);
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, b.x, b.y, color);
		b.x += step.x;
		b.y += step.y;
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
