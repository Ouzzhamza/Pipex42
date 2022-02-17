/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:17:49 by houazzan          #+#    #+#             */
/*   Updated: 2022/02/17 18:00:56 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../bonus/pipex_bonus.h"

int	type(char **av, t_bdata *pipex)
{
	if (strncmp("here_doc", av[1], 9) == 0)
	{
		pipex->type = 2;
		return (6);
	}
	else
	{
		pipex->type = 1;
		return (5);
	}
}

void	file_type(char **av, t_bdata *pipex)
{
	if (pipex->type == 2)
		her_doc(av, pipex);
	else
	{
		pipex->infile = open(av[1], O_RDWR);
		if (pipex->infile < 0)
			ft_error_bonus(pipex, FILE);
	}		
}
