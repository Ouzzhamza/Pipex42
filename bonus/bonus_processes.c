/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:32:43 by houazzan          #+#    #+#             */
/*   Updated: 2022/02/22 23:50:19 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "bonus_pipex.h"

char	*path_handling(char **path, char *cmd)
{
	char	*temp;
	char	*command;

	while (*path)
	{
		temp = ft_strjoin(*path, "/");
		command = ft_strjoin(temp, cmd);
		free(temp);
		if (access(command, X_OK) == 0)
			return (command);
		free(command);
		path++;
	}
	return (NULL);
}

void	child_bprocess(t_bonus *pipex, char *av[], char **envp)
{
	pipex->cmd_args = ft_split(av[pipex->and + pipex->h_d + 2], ' ');
	if (pipex->cmd_args[0] == NULL)
		ft_error_bonus(pipex, CMD);
	pipex->path = path_tracking_bonus(envp);
	pipex->cmd_path = ft_split(pipex->path, ':');
	if (pipex->path == NULL | pipex->cmd_path == NULL)
		ft_error_bonus(pipex, PATH);
	pipex->cmd = path_handling(pipex->cmd_path, pipex->cmd_args[0]);
	if (!pipex->cmd)
	{
		ft_error_bonus(pipex, ft_strjoin(CMD, pipex->cmd_args[0]));
		ft_putstr_fd("\n", 2);
		ft_free_bonus(pipex);
		exit(1);
	}
	execve(pipex->cmd, pipex->cmd_args, envp);
}
