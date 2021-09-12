/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 03:12:16 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/13 00:57:35 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_width_height(char *filename, t_env *env)
{
	int		fd;
	int		height;
	int		width[2];
	char	*line;

	height = 0;
	width[0] = 0;
	width[1] = -1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_and_exit("Cannot open .fdf file");
	while (get_next_line(fd, &line) == 1 && ++height)
	{
		width[0] = ft_wdcounter(line, ' ');
		if (width[1] != width[0] && width[1] != -1)
			print_and_exit("Parsing error");
		width[1] = width[0];
		free(line);
	}
	free(line);
	close(fd);
	if (height == 0)
		print_and_exit("Parsing error");
	env->height = height;
	env->width = width[0];
}

static t_dot	*fill_arr(char *line, t_dot *arr, int y)
{
	int		i;
	char	**nums;

	i = 0;
	nums = ft_split(line, " \t");
	if (!nums)
		print_and_exit("Error");
	while (nums[i])
	{
		arr[i].x = i;
		arr[i].y = y;
		arr[i].z = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
	return (arr);
}

void	parsing(char *filename, t_env *env)
{
	int		i;
	int		fd;
	char	*line;

	get_width_height(filename, env);
	env->matrix = malloc(sizeof(t_dot *) * (env->height + 1));
	if (!(env->matrix))
		print_and_exit("Malloc error");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_and_exit("Cannot open .fdf file");
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		env->matrix[i] = malloc(sizeof(t_dot) * (env->width + 1));
		if (!(env->matrix[i]))
			print_and_exit("Malloc error");
		fill_arr(line, env->matrix[i], i);
		free(line);
		i++;
	}
	env->matrix[i] = NULL;
	free(line);
	close(fd);
}
