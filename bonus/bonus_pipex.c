/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:20:51 by houazzan          #+#    #+#             */
/*   Updated: 2022/06/21 13:47:42 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_pipex.h"

/* **************************************************** */
/*                  🅱🅾🅽🆄🆂_🆃🆈🅿🅴                    */
/* **************************************************** */

int	bonus_type(t_bonus *pipex, char **av, int argc)
{
	if (strcmp("here_doc", av[1]) == 0)
	{
		pipex->outfile = open(av[argc -1], O_WRONLY | O_CREAT | O_APPEND, 0666);
		pipex->type = 1;
		pipex->h_d = 1;
		if (pipex->infile < 0 | pipex->outfile < 0)
			err_msg_bonus(FILE);
		return (6);
	}
	else
	{
		pipex->outfile = open(av[argc -1], O_CREAT | O_RDWR | O_TRUNC, 0666);
		pipex->infile = open(av[1], O_RDONLY);
		if (pipex->infile < 0 | pipex->outfile < 0)
			err_msg_bonus(FILE);
		pipex->type = 2;
		pipex->h_d = 0;
		return (5);
	}
}

/* **************************************************** */
/*                🅲🆁🅴🅰🆃🅴_🅿🅸🅿🅴🆂                   */
/* **************************************************** */

void	create_pipes(t_bonus *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->ncmd - 1)
	{
		if (pipe(pipex->end + 2 * i) < 0)
			free_pipes(pipex);
		i++;
	}
}

/* **************************************************** */
/*                  🅲🅻🅾🆂🅴_🅿🅸🅿🅴🆂                  */
/* **************************************************** */

void	close_pipes(t_bonus *pipex)
{
	int	i;

	i = 0;
	while (i < 2 * (pipex->ncmd - 1))
	{
		close(pipex->end[i]);
		i++;
	}
}

/* **************************************************** */
/*                  🅲🅰🅻🅻_🅿🆁🅾🅲🅴🆂🆂                 */
/* **************************************************** */

void	call_process(t_bonus *pipex, char *argv[], char **envp)
{
	pipex->id = fork();
	if (pipex->id == 0)
	{
		int i = 0;
		while (pipex->end[i])
		{
			fprintf(stdout, "pipex->end[%d] = %d\n", i, pipex->end[i]);
			i++;
		}
		if (pipex->and == 0)
		{
			dup2(pipex->infile, STDIN_FILENO);
			dup2(pipex->end[1], STDOUT_FILENO);
		}
		else if (pipex->and == pipex->ncmd - 1)
		{
			dup2(pipex->end[2 * pipex->and - 2], STDIN_FILENO);
			dup2(pipex->outfile, STDOUT_FILENO);
		}
		else
		{
			dup2(pipex->end[2 * pipex->and - 2], STDIN_FILENO);
			dup2(pipex->end[2 * pipex->and + 1], STDOUT_FILENO);
		}
		close_pipes(pipex);
		child_bprocess(pipex, argv, envp);
	}
}

/* **************************************************** */
/*                    🆃🅷🅴 🅼🅰🅸🅽                     */
/* **************************************************** */

int	main(int argc, char *argv[], char **envp)
{
	t_bonus	*pipex ;

	pipex = (t_bonus *) malloc(sizeof(t_bonus));
	if (!pipex)
		err_msg_bonus(ALLOCATION);
	if (argc < bonus_type(pipex, argv, argc))
		err_msg_bonus(NUMBER);
	pipex->ncmd = argc - 3 - pipex->h_d;
	if (pipex->type == 1)
		her_doc(pipex, argv[2]);
	pipex->path = path_tracking_bonus(envp);
	pipex->cmd_path = ft_split(pipex->path, ':');
	if (pipex->path == NULL | pipex->cmd_path == NULL)
		ft_error_bonus(pipex, PATH);
	pipex->end = (int *)malloc(sizeof(int) * (2 * (pipex->ncmd - 1)));
	if (!pipex->end)
		err_msg_bonus(PIPE);
	create_pipes(pipex);
	pipex->and = -1;
	while (++(pipex->and) < pipex->ncmd)
		call_process(pipex, argv, envp);
	close_pipes(pipex);
	waitpid(-1, NULL, 0);
	free_bonus(pipex);
	return (0);
}
