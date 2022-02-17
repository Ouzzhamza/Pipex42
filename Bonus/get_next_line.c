/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:03:22 by houazzan          #+#    #+#             */
/*   Updated: 2022/02/17 12:21:54 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "pipex_bonus.h"

/* *********************************** */
/*		    assign.c			       */
/* *********************************** */

void	assign(char **dest, char *src, char **to_free)
{
	if (to_free == dest)
	{
		free(*to_free);
		*to_free = NULL;
	}
	*dest = src;
	if (to_free != dest)
	{
		free(*to_free);
		*to_free = NULL;
	}
}

/* *********************************** */
/*		    get_the_line.c			   */
/* *********************************** */

char	*get_the_line(char **statiq)
{
	char	*ptr;
	char	*rest;

	rest = NULL;
	ptr = ft_strchr(*statiq, '\n');
	if (ptr)
	{
		rest = ft_strdup(ptr + 1);
		ptr[1] = '\0';
		ptr = ft_strdup(*statiq);
		free(*statiq);
		if (*rest == '\0')
		{
			free(rest);
			rest = NULL;
		}
		*statiq = rest;
	}
	return (ptr);
}

/* *********************************** */
/*		    ft_init.c  			   */
/* *********************************** */

int	init(int fd, int *read_size, char **line, char **buf)
{
	*read_size = 0;
	*line = NULL;
	*buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (*buf == NULL || BUFFER_SIZE <= 0 || read(fd, *buf, 0) == -1)
		return (0);
	return (1);
}

/* *********************************** */
/*		    get_next_line.c			   */
/* *********************************** */

char	*get_next_line(int fd)
{
	int			read_size;
	char		*line;
	char		*buf;
	static char	*statiq;

	if (init(fd, &read_size, &line, &buf))
	{
		while (line == NULL && read_size >= 0)
		{
			read_size = read(fd, buf, BUFFER_SIZE);
			if (read_size == -1 || (read_size == 0 && !statiq))
				break ;
			if (read_size == 0 && statiq)
			{
				line = get_the_line(&statiq);
				if (line == NULL)
					assign(&line, ft_strdup(statiq), &statiq);
				break ;
			}
			buf[read_size] = '\0';
			assign(&statiq, ft_strjoin(statiq, buf), &statiq);
			line = get_the_line(&statiq);
		}
	}
	return (free(buf), line);
}
