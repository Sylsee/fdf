/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 22:14:53 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/09 18:26:19 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../mlx_linux/mlx.h"

typedef struct s_env
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	float	angle;

	void	*mlx_ptr;
	void	*win_ptr;
}				t_env;

void	fdf(t_env *env);
void	parsing(char *filename, t_env *env);
void	print_and_exit(char *s);

#endif