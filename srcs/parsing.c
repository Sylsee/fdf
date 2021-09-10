/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 03:12:16 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/08 03:13:39 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_and_exit("Error when oppening file.fdf");
	while (get_next_line(fd, &line) == 1)
	{
		height++;
		free(line);
	}
	free(line);
	close(fd);
	return (height);
}

static int	get_width(char *filename)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_and_exit("Error when oppening file.fdf");
	get_next_line(fd, &line);
	width = ft_wdcounter(line, ' ');
	free(line);
	while (get_next_line(fd, &line) == 1)
		free(line);
	free(line);
	close(fd);
	return (width);
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

	env->height = get_height(filename);
	env->width = get_width(filename);
	env->matrix = malloc(sizeof(t_dot *) * (env->height + 1));
	if (!(env->matrix))
		print_and_exit("Malloc error");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_and_exit("Error");
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
