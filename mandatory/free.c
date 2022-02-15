/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:45:46 by houazzan          #+#    #+#             */
/*   Updated: 2022/02/15 19:50:29 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "pipex.h"

void	ft_free(t_data *pipex)
{
	int	i;

	i = 0;

	while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_path);
	free(pipex->cmd);
}
