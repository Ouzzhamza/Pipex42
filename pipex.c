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

/* **************************************************** */
/*                     The error                        */
/* **************************************************** */

void	ft_error(char *str)
{
	perror(str);
	exit(1);
}

int err_msg(char *str)
{
	ft_putstr_fd(str, 2);
	return(1);
}

/* **************************************************** */
/*                      The main                        */
/* **************************************************** */
int main(int ac, char *av[], char **envp)
{
	t_data *pipex;
	int id;

	pipex = (t_data *) malloc(sizeof(t_data));
	if(ac != 5)
		return (err_msg(NUMBER));
	if(pipe(pipex->end) == -1)
		ft_error(PIPE);
	pipex->infile = open(av[1], O_RDWR);  // in case o f the first file doesn't exist i should return error 
	pipex->outfile = open(av[4], O_RDWR |O_CREAT, 0666);
	if(pipex->infile < 0 | pipex->outfile < 0)
		ft_error(FILE);
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	pipex->path = (*envp + 5);
	pipex->cmd_path = ft_split(pipex->path, ':');
	id = fork();
	if (id == 0)
		child_process1(pipex, av, envp);
	id = fork();
	if(id == 0)
		child_process2(pipex, av, envp);
	return(0);
}
	

	
	
