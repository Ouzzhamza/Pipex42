/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:03:22 by houazzan          #+#    #+#             */
/*   Updated: 2022/02/19 23:20:18 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/pipex.h"
#include "../bonus/bonus_pipex.h"

char	*get_next_line(int fd)
{
	char	line[800000];
	char	buff[1];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i > 0)
	{
		i = read (fd, buff, 1);
		if (buff[0] == '\n')
			break ;
		line[j++] = buff[0];
	}
	line[j++] = '\0';
	return (ft_strdup(line));
}
