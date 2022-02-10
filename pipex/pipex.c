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


void	pipex(file1, file2, av, t_data *pipex)
{
	*pipex.path;

	pid_t id;
	int end[2];

	id = fork();

	if(id < 0)
		return("error");
	if(id != 0)
		parent_process(file1, cmd);
	else
		chield_process(file2, cmd);
	return(0);
}

int main(int ac, char *av[], char *envp[])
{
	t_data *pipex;

	if(ac != 5)
		return("insufisant number of argument");	
	pipex->file1;
	pipex->file2;
	int fd[2];
	if(pip(pipex->pend) == -1)
		return("error");
	pipex->file1 = open(av[1], O_RDONLY);
	pipex->file2 = open(av[4], O_RDWR | O_CREAT  , 0666);
	if(pipex->file1 < 0 | pipex->file2 < 0)
		return("error");
	ft_pipex(pipex->file2, pipex->file1, av, envp, pipex);
	return(0);
	}
}
	

	
	
