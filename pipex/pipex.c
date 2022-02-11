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
// 		parent_process(file1, cmd);
// 	else
// 		chield_process(file2, cmd);
// 	return(0);
// }

/* **************************************************** */
/*                   Finding the pathe                  */
/* **************************************************** */
char *find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return(*envp + 5);
}


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
	//int id;

	pipex = (t_data *) malloc(sizeof(t_data));
	if(ac != 5)
		ft_error();
	// if(pipe(pipex->fd) == -1)
	// 	ft_error();
	pipex->file1 = open(av[1], O_CREAT, 0777);  // in case o f the first file doesn't exist i should return error 
	pipex->file2 = open(av[4], O_RDWR |O_CREAT, 0777);
	if(pipex->file1 < 0 | pipex->file2 < 0)
		ft_error();
	pipex->path = find_path(envp);

	// id = fork();
	// if(id == -1)
	// 	ft_error();
	// else if (id == 0)
	// 	child_process(pipex, av);
	// else
	// 	parent_process(pipex, av);

	return(0);
}
	

	
	
