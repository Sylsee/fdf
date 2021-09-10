/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:56:57 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/10 05:17:30 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_close(t_env *env)
{
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	exit(0);
}

int	mouse_hook(int button, int x, int y, t_env *env)
{
	printf("button: [%d]\nx: [%d]\ny: [%d]\n", button, x, y);
//	if (key == 1)
//		rotate_right();
//	if (key == 3)
//		rotate_left();
	if (button == 4)
		env->zoom += 1;
	if (button == 5)
		env->zoom -= 1;
	if (button == 4 || button == 5)
	{
		mlx_clear_window(env->mlx_ptr, env->win_ptr);
		fdf(env);
	}
	return (0);
}

int	key_hook(int key, t_env *env)
{
	printf("key: [%d]\n", key);
	if (key == 65307)
		fdf_close(env);
/*	if (key == 65361)
		left(env);
	if (key == 65364)
		down(env);
	if (key == 65363)
		right(env);
	if (key == 65362)
		up(env);*/
	return (0);
}

static void	setup(t_env *env)
{
	env->zoom = 20;
	env->angle = 0.8;
	env->x_shift = 150;
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

/*
	int i;
	int j;
	printf("height: [%d]\nwidth: [%d]\n", env.height, env.width);
	i = 0;
	while (env.matrix[i])
	{
		j = 0;
		while (j < env.width)
		{
			printf("%4d", env.z_matrix[i][j]->z);
			j++;
		}
		printf("\n");
		i++;
	}
*/
