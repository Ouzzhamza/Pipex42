/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:20:51 by houazzan          #+#    #+#             */
/*   Updated: 2022/02/22 23:50:02 by houazzan         ###   ########.fr       */
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

int	bonus_type(t_bonus *pipex, char *av)
{
	if (strcmp("here_doc", av) == 0)
	{
		pipex->type = 1;
		pipex->h_d = 1;
		return (6);
	}
	else
	{
		pipex->infile = open(av, O_RDWR, 0666);
		if (pipex->infile < 0)
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
	while (i < pipex->ncmd  - 1)
	{
		if (pipe(pipex->end) < 0)
		{
			ft_error_bonus(pipex, PIPE);
		}
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
	if (pipex->id != 0)
	{
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
	if (argc < bonus_type(pipex, argv[1]))
		err_msg_bonus(NUMBER);
	pipex->ncmd = argc - 3 - pipex->h_d;
	pipex->outfile = open(argv[argc - 1], O_TRUNC | O_RDWR | O_CREAT, 0666);
	if (pipex->outfile < 0)
		err_msg_bonus(FILE);
	if (pipex->type == 1)
		her_doc(pipex, argv[2]);
	create_pipes(pipex);
	pipex->and = -1;
	while (++pipex->and < pipex->ncmd)
		call_process(pipex, argv, envp);
	close_pipes(pipex);
	ft_free_bonus(pipex);
	return (0);
}


//here_doc --seg
//./pipex_bonus infile ls cat " " out 
//./pipex_bonus infile " " cat ls out