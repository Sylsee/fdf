/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 22:14:53 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/10 05:29:11 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../mlx_linux/mlx.h"

typedef struct s_dot
{
	float	x;
	float	y;
	float	z;
}				t_dot;

typedef struct s_env
{
	int		width;
	int		height;
	t_dot		**matrix;

	int		x_shift;
	int		y_shift;
	int		z_shift;
	int		zoom;
	float	angle;
	int		isometric;

	void	*mlx_ptr;
	void	*win_ptr;
}				t_env;

void	fdf(t_env *env);
void	parsing(char *filename, t_env *env);
void	print_and_exit(char *s);

#endif
