/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:56:57 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/10 17:50:05 by spoliart         ###   ########.fr       */
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
	exit(0);
}

void	setup(t_env *env)
{
	env->isometric = 1;
	env->zoom = 20;
	env->angle = 0.8;
	env->x_shift = 190;
	env->y_shift = 150;
	env->z_shift = 0;
}

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2 || (argv[1] && !(ft_str_end(argv[1], ".fdf"))))
		print_and_exit("Usage: ./fdf file.fdf");
	env.mlx_ptr = mlx_init();
	if (!(env.mlx_ptr))
		print_and_exit("Cannot init the minilibx");
	env.win_ptr = mlx_new_window(env.mlx_ptr, 500, 500, "FDF");
	if (!(env.win_ptr))
		print_and_exit("Cannot create the window");
	parsing(argv[1], &env);
	setup(&env);
	fdf(&env);
	mlx_key_hook(env.win_ptr, &key_hook, &env);
	mlx_mouse_hook(env.win_ptr, &mouse_hook, &env);
	mlx_hook(env.win_ptr, 33, 0, &fdf_close, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
