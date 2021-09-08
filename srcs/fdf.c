/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:56:57 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/08 03:17:05 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2 || (argv[1] && !(ft_str_end(argv[1], ".fdf"))))
		print_and_exit("Error: usage: ./fdf file.fdf");
	parsing(argv[1], &env);
	return (0);
}

/*
	int i;
	int j;
	printf("height: [%d]\nwidth: [%d]\n", env.height, env.width);
	i = 0;
	while (env.z_matrix[i])
	{
		j = 0;
		while (j < env.width)
		{
			printf("%d  ", env.z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
*/