/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:47:35 by houazzan          #+#    #+#             */
/*   Updated: 2022/02/16 13:46:14 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_tracking(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp("PATH", *envp, 4) == 0)
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

/* **************************************************** */
/*                      The main                        */
/* **************************************************** */

int	main(int ac, char *av[], char **envp)
{
	t_data	*pipex;
	int		id;

	pipex = (t_data *) malloc(sizeof(t_data));
	if (ac != 5)
		return (err_msg(pipex ,NUMBER));
	if (pipe(pipex->end) == -1)
		ft_error(pipex, PIPE);
	pipex->infile = open(av[1], O_RDWR);
	pipex->outfile = open(av[4], O_TRUNC | O_RDWR | O_CREAT, 0666);
	if (pipex->infile < 0 | pipex->outfile < 0)
		ft_error(pipex, FILE);
	pipex->path = path_tracking(envp);
	if (pipex->path == NULL)
		err_msg(pipex, PATH);
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
