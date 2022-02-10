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

char *find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return(*envp);
}

void	ft_error(void)
{
	perror("warning ");
	exit(0);
}

int main(int ac, char *av[], char **envp)
{
	t_data *pipex;

	pipex = (t_data *) malloc(sizeof(t_data));
	if(ac != 5)
		ft_error();
	if(pipe(pipex->fd) == -1)
		ft_error();
	if(av[1] != NULL)
	{
		pipex->file1 = open(av[1], O_CREAT, 0666);
		pipex->file2 = open(av[4], O_CREAT, 0666);
		if(pipex->file1 < 0 | pipex->file2 < 0)
			ft_error();
		pipex->path = find_path(envp);
		
		//ft_pipex(av, pipex);
	}
	return(0);
}
	

	
	
