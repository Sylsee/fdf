/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:17:20 by spoliart          #+#    #+#             */
/*   Updated: 2021/09/08 02:00:26 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int	ft_return_gnl(char *s, size_t i)
{
	if (i == 0)
	{
		if (s)
			free(s);
		return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*tab[FDMAX];
	size_t		i;
	size_t		len;
	char		*buffer;
	char		*tmp;

	i = -1;
	if (read(fd, 0, 0) == -1 || fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	while (i != 0 && ft_check_gnl(tab[fd]))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		buffer[i] = '\0';
		tab[fd] = ft_strjoin_gnl(tab[fd], buffer);
	}
	len = ft_strlen_chr_gnl(tab[fd], '\n');
	*line = ft_substr_gnl(tab[fd], 0, len);
	tmp = tab[fd];
	tab[fd] = ft_substr_gnl(tab[fd], len + 1, ft_strlen_gnl(tab[fd]) - len);
	free(tmp);
	free(buffer);
	return (ft_return_gnl(tab[fd], i));
}
