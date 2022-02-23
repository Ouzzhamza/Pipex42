/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:47:35 by houazzan          #+#    #+#             */
/*   Updated: 2022/02/23 20:21:17 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* **************************************************** */
/*                🅿🅰🆃🅷 🆃🆁🅰🅲🅺🅸🅽🅶                 */
/* **************************************************** */

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
/*                🅲🅻🅾🆂🅴_🅿🅸🅿🅴🆂                     */
/* **************************************************** */

void	close_pipes(t_data *pipex)
{
	close (pipex->end[0]);
	close (pipex->end[1]);
}

/* **************************************************** */
/*                    🅵🅾🆁🅺🅸🅽🅶                      */
/* **************************************************** */
void	forking(t_data *pipex, char *av[], char **envp)
{	
	pipex->id = fork();
	if (pipex->id == 0)
		child_process(pipex, av, envp);
	pipex->id2 = fork();
	if (pipex->id2 == 0)
		parent_process(pipex, av, envp);
}

/* **************************************************** */
/*                    🆃🅷🅴 🅼🅰🅸🅽                      */
/* **************************************************** */

int	main(int ac, char *av[], char **envp)
{
	t_data	*pipex;

	pipex = (t_data *) malloc(sizeof(t_data));
	if (ac != 5)
		err_msg(NUMBER);
	if (pipe(pipex->end) == -1)
		err_msg(PIPE);
	pipex->infile = open(av[1], O_RDWR);
	pipex->outfile = open(av[4], O_TRUNC | O_RDWR | O_CREAT, 0666);
	if (pipex->infile < 0 | pipex->outfile < 0)
		err_msg(FILE);
	pipex->path = path_tracking(envp);
	pipex->cmd_path = ft_split(pipex->path, ':');
	if (pipex->path == NULL | pipex->cmd_path == NULL)
		ft_error(pipex, PATH);
	forking(pipex, av, envp);
	close_pipes(pipex);
	waitpid(pipex->id, NULL, 0);
	waitpid(pipex->id2, NULL, 0);
	ft_free(pipex);
	return (0);
}
