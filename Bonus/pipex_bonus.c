/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:48:44 by houazzan          #+#    #+#             */
/*   Updated: 2022/02/17 17:51:10 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*path_tracking_bonus(char **envp)
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
	t_bdata	*pipex;
	int		id;

	pipex = (t_bdata *) malloc(sizeof(t_bdata));
	if (ac < type(av, pipex))
		return (err_msg_bonus(pipex, NUMBER));
	file_type(av, pipex);
	pipex->outfile = open(av[ac - 1], O_TRUNC | O_RDWR | O_CREAT, 0666);
	if (pipex->outfile < 0)
		ft_error_bonus(pipex, FILE);
	pipex->path = path_tracking_bonus(envp);
	if (pipex->path == NULL)
		err_msg_bonus(pipex, PATH);
	pipex->cmd_path = ft_split(pipex->path, ':');
	while (ac - 1 > 2)
	{
		id = fork();
		if (id == 0)		
			child_process_bonus(pipex, av, envp);
		else
		{
			waitpid(0, NULL, WNOHANG);
			parent_process_bonus(pipex, av, envp);
		}
		return (0);
	}
}
