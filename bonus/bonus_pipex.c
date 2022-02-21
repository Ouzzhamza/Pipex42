/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:20:51 by houazzan          #+#    #+#             */
/*   Updated: 2022/02/21 17:12:08 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_pipex.h"

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
/*                  🅱🅾🅽🆄🆂_🆃🆈🅿🅴                    */
/* **************************************************** */

void	bonus_type(t_bonus *pipex, char *av)
{
	if (strcmp("here_doc", av) == 0)
	{
		dup2(pipex->infile, STDIN_FILENO);
		pipex->type = 1;
		pipex->j = 3;
	}
	else if (strcmp("infile", av) == 0)
	{
		dup2(pipex->infile, STDIN_FILENO);
		pipex->type = 2;
		pipex->j = 4;
	}
	else
		err_msg_bonus(pipex, ARG);
}

/* **************************************************** */
/*                🅲🆁🅴🅰🆃🅴_🅿🅸🅿🅴🆂                   */
/* **************************************************** */

void	create_pipes(t_bonus *pipex, int argc, char *argv[], char **envp)
{
	while (pipex->j < argc - 2)
	{
		if (pipe(pipex->end) == -1)
			err_msg_bonus(pipex, PIPE);
		pipex->id = fork();
		if (pipex->id == 0)
			child_bprocess(pipex, argv, envp);
		else
		{
			close(pipex->end[1]);
			dup2(pipex->end[0], STDIN_FILENO);
		}
		pipex->j++;
	}
	parent_bprocess(pipex, argv, envp, argc);
}

/* **************************************************** */
/*                    🆃🅷🅴 🅼🅰🅸🅽                     */
/* **************************************************** */

int	main(int argc, char *argv[], char **envp)
{
	t_bonus	*pipex ;

	pipex = (t_bonus *) malloc(sizeof(t_bonus));
	if (argc < 5)
		err_msg_bonus(pipex, NUMBER);
	bonus_type(pipex, argv[1]);
	if (pipex->type == 2)
		pipex->infile = open(argv[1], O_RDWR);
	pipex->outfile = open(argv[argc - 1], O_TRUNC | O_RDWR | O_CREAT, 0666);
	if (pipex->outfile < 0)
		ft_error_bonus(pipex, FILE);
	if (pipex->type == 1)
		her_doc(argv[2]);
	pipex->id = fork();
	create_pipes(pipex, argc, argv, envp);
}
