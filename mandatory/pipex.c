/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:47:35 by houazzan          #+#    #+#             */
/*   Updated: 2022/02/15 22:06:09 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* **************************************************** */
/*                      The main                        */
/* **************************************************** */

int	main(int ac, char *av[], char **envp)
{
	t_data	*pipex = NULL;
	int		id;

	pipex = (t_data *) malloc(sizeof(t_data));
	if (ac != 5)
		return (err_msg(NUMBER));
	if (pipe(pipex->end) == -1)
		ft_error(PIPE);
	pipex->infile = open(av[1], O_RDWR);
	pipex->outfile = open(av[4], O_TRUNC | O_RDWR | O_CREAT, 0666);
	if (pipex->infile < 0 | pipex->outfile < 0)
		ft_error(FILE);
	while (ft_strncmp("PATH", *envp, 4))
	{
		if(ft_strncmp("PATH", *envp, 4))
			pipex->path = (*envp + 5);
		envp++;
	}
	if(pipex->path == NULL)
		exit(1);
	pipex->cmd_path = ft_split(pipex->path, ':');
	id = fork();
	if (id == 0)
		child_process(pipex, av, envp);
	else
	{
		waitpid(0, NULL, WNOHANG);
		parent_process(pipex, av, envp);
	}
	return (0);
}
