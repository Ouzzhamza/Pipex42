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


// void	pipex(char *av[], char *envp[], t_data pipex)
// {
	
// 	pipex.path = 	
// 	pid_t id;
// 	int end[2];

// 	id = fork();

// 	if(id < 0)
// 		return("error");
// 	if(id != 0)
// 		parent_process(infile, cmd);
// 	else
// 		chield_process(outfile, cmd);
// 	return(0);
// }

/* **************************************************** */
/*                     The error                        */
/* **************************************************** */

void	ft_error(void)
{
	perror("warning ");
	exit(0);
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
		ft_error();
	if(pipe(pipex->end) == -1)
		ft_error();
	pipex->infile = open(av[1], O_RDWR);  // in case o f the first file doesn't exist i should return error 
	pipex->outfile = open(av[4], O_RDWR |O_CREAT, 0666);
	if(pipex->infile < 0 | pipex->outfile < 0)
		ft_error();
	id = fork();
	if (id == 0)
		child_process1(pipex, av, envp);
	id = fork();
	if(id == 0)
		child_process2(pipex, av, envp);
	return(0);
}
	

	
	
