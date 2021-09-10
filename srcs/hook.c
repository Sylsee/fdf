/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:28:44 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/10 17:36:36 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	need_reset(int key, t_env *env)
{
	if (key == 65363)
		env->x_shift += 10;
	if (key == 65361)
		env->x_shift -= 10;
	if (key == 65364)
		env->y_shift += 10;
	if (key == 65362)
		env->y_shift -= 10;
	if (key == 32)
	{
		if (env->isometric)
			env->x_shift -= 120;
		else
			env->x_shift += 120;
		env->isometric = !(env->isometric);
	}
	if (key == 100)
		setup(env);
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	fdf(env);
}

int	mouse_hook(int button, int x, int y, t_env *env)
{
	printf("button: [%d]\nx: [%d]\ny: [%d]\n", button, x, y);
	if (button == 1)
		env->angle -= 0.1;
	if (button == 3)
		env->angle += 0.1;
	if (button == 4)
		env->zoom += 1;
	if (button == 5 && env->zoom > 1)
		env->zoom -= 1;
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	fdf(env);
	return (0);
}

int	key_hook(int key, t_env *env)
{
	printf("key: [%d]\n", key);
	if (key == 65307)
		fdf_close(env);
	if (key == 65361 || key == 65363 || key == 65364 || key == 65362
		|| key == 32 || key == 100)
		need_reset(key, env);
	return (0);
}
