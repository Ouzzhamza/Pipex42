/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:01:02 by houazzan          #+#    #+#             */
/*   Updated: 2022/02/17 20:44:12 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/* **************************************************** */
/*                       her_doc                        */
/* **************************************************** */
void	her_doc(char *av[], t_bdata *pipex)
{
	int	fd;

	fd = open(".temp", O_CREAT | O_TRUNC | O_WRONLY, 00644);
	if (fd < 0)
		err_msg_bonus(pipex, H_FILE);
	while (1)
	{
		write (1, "herdoc> ", 9);
		pipex->buff = get_next_line(0);
		if (pipex->buff == NULL)
			err_msg_bonus(pipex, READING);
		else if (pipex->buff == av[2])
			break ;
		write(fd, pipex->buff, ft_strlen(pipex->buff));
		write(fd, "\n", 1);
		free(pipex->buff);
	}
	close(fd);
	pipex->infile = open(".temp", O_WRONLY);
	if (pipex->infile < 0)
		unlink(".temp");
	err_msg_bonus(pipex, H_FILE);
}

/* **************************************************** */
/*                  Handling the pathe                  */
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
		if (access(command, X_OK) == 0 )
			return (command);
		free(command);
		path++;
	}
	return (NULL);
}

/* **************************************************** */
/*                 chile process_bonus                  */
/* **************************************************** */

void	child_process_bonus(t_bdata *pipex, char *av[], char **envp)
{
	dup2(pipex->infile, STDIN_FILENO);
	dup2(pipex->end[1], STDOUT_FILENO);
	close(pipex->end[0]);
	pipex->cmd_args = ft_split(av[2], ' ');
	if (pipex->cmd_args[0] == NULL)
		err_msg_bonus(pipex, CMD);
	pipex->cmd = path_handling(pipex->cmd_path, pipex->cmd_args[0]);
	if (!pipex->cmd)
	{
		err_msg_bonus(pipex, ft_strjoin(CMD, pipex->cmd_args[0]));
		ft_putstr_fd("\n", 2);
		ft_free_bonus(pipex);
		exit(1);
	}
	execve(pipex->cmd, pipex->cmd_args, envp);
}

/* **************************************************** */
/*                parent process_bonus                  */
/* **************************************************** */

void	parent_process_bonus(t_bdata *pipex, char *av[], char **envp)
{
	pipex->cmd_args = NULL;
	dup2(pipex->outfile, STDOUT_FILENO);
	dup2(pipex->end[0], STDIN_FILENO);
	close(pipex->end[1]);
	pipex->cmd_args = ft_split(av[3], ' ');
	if (pipex->cmd_args[0] == NULL)
		err_msg_bonus(pipex, CMD);
	pipex->cmd = path_handling(pipex->cmd_path, pipex->cmd_args[0]);
	if (!pipex->cmd)
	{
		err_msg_bonus(pipex, ft_strjoin(CMD, pipex->cmd_args[0]));
		ft_putstr_fd("\n", 2);
		ft_free_bonus(pipex);
		exit(1);
	}
	execve(pipex->cmd, pipex->cmd_args, envp);
}
