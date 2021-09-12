/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 23:02:52 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/13 01:03:35 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_and_exit(char *s, t_env *env)
{
	if (env)
	{
		if (env->win_ptr)
		{
			mlx_clear_window(env->mlx_ptr, env->win_ptr);
			mlx_destroy_window(env->mlx_ptr, env->win_ptr);
		}
		if (env->mlx_ptr)
			mlx_destroy_display(env->mlx_ptr);
		free_matrix(env);
		free(env);
	}
	ft_putendl_fd(s, 2);
	exit(1);
}
