/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:56:57 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/08 02:03:53 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_wdcounter(char const *str, char c)
{
	int i;
	int words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

int	get_height(char *filename)
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

int	get_width(char *filename)
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

int	*fill_arr(char *line, int *arr)
{
	int		i;
	char	**nums;

	i = 0;
	nums = ft_split(line, " \t");
	if (!nums)
		print_and_exit("Error");
	while (nums[i])
	{
		arr[i] = ft_atoi(nums[i]);
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
	env->z_matrix = malloc(sizeof(int *) * (env->height + 1));
	if (!(env->z_matrix))
		print_and_exit("Malloc error");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_and_exit("Error");
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		env->z_matrix[i] = malloc(sizeof(int) * (env->width + 1));
		if (!(env->z_matrix[i]))
			print_and_exit("Malloc error");
		fill_arr(line, env->z_matrix[i]);
		free(line);
		i++;
	}
	env->z_matrix[i] = NULL;
	free(line);
	close(fd);
}

int	main(int argc, char **argv)
{
	int i;
	int j;
	t_env	env;

	if (argc != 2 || (argv[1] && ft_str_end(argv[1], ".fdf")) == 0)
		print_and_exit("Error: usage: ./fdf file.fdf");
	parsing(argv[1], &env);
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
	return (0);
}