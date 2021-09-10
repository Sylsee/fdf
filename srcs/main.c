/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:56:57 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/09 18:21:50 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_close(t_env *env)
{
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	exit(0);
}

int	hook(int key, t_env *env)
{
	printf("key: [%d]\n", key);
	if (key == 65307)
		fdf_close(env);
	return (0);
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
	env.zoom = 20;
	env.angle = 0.8;
	fdf(&env);
	mlx_key_hook(env.win_ptr, &hook, &env);
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
