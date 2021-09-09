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

void	zoom(int x, int y, int x1, int y1, t_env *env)
{
	x *= env->zoom;
	x1 *= env->zoom;
	y *= env->zoom;
	y1 *= env->zoom;
}

void	bresenham(int x, int y, int x1, int y1, t_env *env)
{
	int	max;
	int	x_step;
	int	y_step;

	zoom(x, y, x1, y1, env);
	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(ABS(x_step), ABS(y_step));
	x_step /= max;
	y_step /= max;
	while (x - x1 > 0 || y - y1 > 0)
	{
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, x, y, 0xBBFAFF);
		x += x_step;
		y += y_step;
	}
}

void	fdf(t_env *env)
{
/*	int	x;
	int	y;

	x = -1;
	while (++x < env->height)
	{
		y = -1;
		while (++y < env->width)
		{
		//	if (x < env->height - 1)
		//		bresenham(x, y, x + 1, y, env);
		//	if (y < env->width - 1)
		//		bresenham(x, y, x, y + 1, env);
		}
	}*/
	int x = 49;
	while (++x < 100)
	{
		int y = 49;
		while (++y < 100)
			mlx_pixel_put(env->mlx_ptr, env->win_ptr, x, y, 255);
	}
	//bresenham(50, 50, 100, 100, env);
}
