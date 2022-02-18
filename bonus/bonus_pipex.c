/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:20:51 by houazzan          #+#    #+#             */
/*   Updated: 2022/02/18 21:34:07 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_pipex.h"

void	bonus_type(t_bonus *pipex, char *av)
{
	if (strcmp("her_doc", av) == 0)
		pipex->type = 1;
	else
		pipex->type = 2;
}

void	create_pipes(t_bonus *pipex, int argc, char *argv[], char **envp)
{
	int	i;
	int	id;

	i = 0;

	while (i < argc - 3)
	{
		id = fork();
		if (pipe(pipex->end) == -1)
			err_msg_bonus(pipex, PIPE);
		if (id == 0)
			child_bprocess(pipex, argv, envp);
		else
		{
			waitpid(0, NULL, WNOHANG);
			dup2(pipex->end[0], STDIN_FILENO);
			close(pipex->end[1]);
		}
		i++;
	}
	parent_bprocess(pipex, argv, envp);
}


int	main(int argc, char *argv[], char **envp)
{
	t_bonus	*pipex;

	pipex = (t_bonus *) malloc(sizeof(t_bonus));
	if (argc < 5)
		err_msg_bonus(pipex, NUMBER);
	dup2(pipex->infile, STDIN_FILENO);
	dup2(pipex->outfile, STDOUT_FILENO);
	bonus_type(pipex, argv[2]);
	create_pipes(pipex, argc, argv, envp);
	
}
