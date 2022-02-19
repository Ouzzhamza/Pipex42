/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_doc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:51:12 by houazzan          #+#    #+#             */
/*   Updated: 2022/02/20 00:35:58 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "bonus_pipex.h"

void	her_doc(t_bonus *pipex, char *argv)
{
	int		fd;
	char	*buff;

	fd = open(".temp", O_CREAT | O_RDWR | O_TRUNC, 0666);
	while (1)
	{
		write(1, "her_doc>", 9);
		buff = get_next_line(0);
		if (ft_strcmp(buff, argv) == 0)
			break ;
		write(fd, buff, ft_strlen(buff));
		write(fd, "\n", 1);
		free(buff);
	}
	pipex->infile = open(".temp", O_RDONLY);
	if (pipex->infile < 0)
		ft_error_bonus(pipex, PIPE);
}
