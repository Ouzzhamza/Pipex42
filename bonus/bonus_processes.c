/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:32:43 by houazzan          #+#    #+#             */
/*   Updated: 2022/02/23 20:10:58 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "bonus_pipex.h"

/* **************************************************** */
/*           🅿🅰🆃🅷_🆃🆁🅰🅲🅺🅸🅽🅶_🅱🅾🅽🆄🆂             */
/* **************************************************** */

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
/*                 🅿🅰🆃🅷_🅷🅰🅽🅳🅻🅸🅽🅶                */
/* **************************************************** */

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

/* **************************************************** */
/*                 🅲🅷🅸🅻🅳_🅱🅿🆁🅾🅲🅴🆂🆂              */
/* **************************************************** */

void	child_bprocess(t_bonus *pipex, char *av[], char **envp)
{
	pipex->path = path_tracking_bonus(envp);
	pipex->cmd_path = ft_split(pipex->path, ':');
	if (pipex->path == NULL | pipex->cmd_path == NULL)
		ft_error_bonus(pipex, PATH);
	pipex->cmd_args = ft_split(av[pipex->and + pipex->h_d + 2], ' ');
	if (pipex->cmd_args[0] == NULL)
		ft_error_bonus(pipex, CMD);
	pipex->cmd = path_handling(pipex->cmd_path, pipex->cmd_args[0]);
	if (!pipex->cmd)
	{
		ft_error_bonus(pipex, CMD);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
	execve(pipex->cmd, pipex->cmd_args, envp);
}
