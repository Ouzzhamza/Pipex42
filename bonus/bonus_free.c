/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:45:46 by houazzan          #+#    #+#             */
/*   Updated: 2022/02/23 19:50:06 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "bonus_pipex.h"

/* **************************************************** */
/*                🅵🆃_🅵🆁🅴🅴_🅱🅾🅽🆄🆂                  */
/* **************************************************** */

void	free_bonus(t_bonus *pipex)
{	
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	if (pipex->h_d)
		unlink(".temp");
	while (pipex->cmd_path[i])
	{
		free(pipex->cmd_path[i]);
		i++;
	}
	free(pipex->cmd_path);
	free(pipex->cmd);
	free(pipex->end);
	free(pipex);
}

void	free_pipes(t_bonus *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	if (pipex->h_d)
		unlink(".heredoc_tmp");
	free(pipex->end);
	err_msg_bonus(PIPE);
	exit(1);
}
