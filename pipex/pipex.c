/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:55:50 by houazzan          #+#    #+#             */
/*   Updated: 2022/02/01 18:16:59 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(file1, file2, av)
{
	pid_t id;
	int end[2];

	id = fork();

	if(id < 0)
		return("error");
	if(id != 0)
		parent_process(file1, cmd);
	else
		chield_process(file2, cmd)
	return(0);
}

int main(int ac, char *av[])
{
	int file1;
	int file2;
	int fd[2];
	if(pip(fd) == -1)
		return("error");
	file1 = open(av[1], O_RDONLY);
	file2 = open(av[4], O_RDWR | O_CREAT  , 0666);
	if(file1 < 0 | file2 < 0)
		return("error");
	ft_pipex(file1, file2, av);
	return(0);
}
	

	
	
