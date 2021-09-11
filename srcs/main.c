/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:56:57 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/12 01:13:02 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->height)
		free(env->matrix[i]);
	free(env->matrix);
}

int	fdf_close(t_env *env)
{
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	mlx_destroy_display(env->mlx_ptr);
	free_matrix(env);
	free(env);
	exit(0);
}

void	setup(t_env *env)
{
	env->colorise = 0;
	env->isometric = 1;
	env->zoom = -(17 * pow(env->width, 3) / 213750)
		+ ((1969 * pow(env->width, 2)) / 85500) - ((13981 * env->width) / 8550)
		+ 7546 / 171;
	if (env->zoom < 2)
		env->zoom = 2;
	env->z_zoom = 1;
	env->angle = 0.8;
	env->x_shift = 190;
	env->y_shift = 150;
	env->start_color = 0x0F9B0F;
	env->end_color = 0xDD1818;
}

/*		blue to red
	env->start_color = 0x12C2E9;
	env->end_color = 0xF64F59;

		yellow to red
	env->start_color = 0xFFD700;
	env->end_color = 0xDD1818;

		green to red
	env->start_color = 0x0F9B0F;
	env->end_color = 0xDD1818;
*/

void	matrix_min_max(t_env *env)
{
	int	i;
	int	j;

	i = -1;
	env->z_min = env->matrix[0][0].z;
	env->z_max = env->matrix[0][0].z;
	while (++i < env->height)
	{
		j = -1;
		while (++j < env->width)
		{
			if (env->z_min > env->matrix[i][j].z)
				env->z_min = env->matrix[i][j].z;
			if (env->z_max < env->matrix[i][j].z)
				env->z_max = env->matrix[i][j].z;
		}
	}
	env->z_len = env->z_max - env->z_min;
}

int	main(int argc, char **argv)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		print_and_exit("Malloc error");
	if (argc != 2 || (argv[1] && !(ft_str_end(argv[1], ".fdf"))))
		print_and_exit("Usage: ./fdf map.fdf");
	env->mlx_ptr = mlx_init();
	if (!(env->mlx_ptr))
		print_and_exit("Cannot init the minilibx");
	env->win_ptr = mlx_new_window(env->mlx_ptr, 500, 500, "FDF");
	if (!(env->win_ptr))
		print_and_exit("Cannot create the window");
	parsing(argv[1], env);
	setup(env);
	matrix_min_max(env);
	fdf(env);
	mlx_key_hook(env->win_ptr, &key_hook, env);
	mlx_mouse_hook(env->win_ptr, &mouse_hook, env);
	mlx_hook(env->win_ptr, 33, 0, &fdf_close, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
