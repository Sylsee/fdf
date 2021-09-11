/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 22:14:53 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/12 00:02:46 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../mlx_linux/mlx.h"


typedef struct s_dot
{
	double	x;
	double	y;
	double	z;
}				t_dot;

typedef struct s_env
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_dot	**matrix;
	int		width;
	int		height;

	int		z_min;
	int		z_max;
	int		z_len;
	int		x_shift;
	int		y_shift;
	int		zoom;
	int		z_zoom;
	int		isometric;
	int		colorise;
	int		start_color;
	int		end_color;
	double	angle;

}				t_env;

void	fdf(t_env *env);

void	parsing(char *filename, t_env *env);
void	setup(t_env *env);

void	isometric(double *x, double *y, double z, t_env *env);
void	shift(t_dot *a, t_dot *b, t_env *env);
void	zoom(t_dot *a, t_dot *b, t_env *env);
int		get_color(t_dot a, t_dot b, t_dot c, t_env *env);

int		key_hook(int key, t_env *env);
int		mouse_hook(int button, int x, int y, t_env *env);

int		fdf_close(t_env *env);
void	free_matrix(t_env *env);
void	print_and_exit(char *s);

#endif
