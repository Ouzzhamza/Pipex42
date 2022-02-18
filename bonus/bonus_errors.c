/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:45:47 by houazzan          #+#    #+#             */
/*   Updated: 2022/02/18 20:34:27 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "bonus_pipex.h"

void	ft_error_bonus(t_bonus *pipex, char *str)
{
	perror(str);
	ft_free_bonus(pipex);
	exit(EXIT_FAILURE);
}

/* **************************************************** */
/*                     msg_error                        */
/* **************************************************** */

int	err_msg_bonus(t_bonus *pipex, char *str)
{
	ft_putstr_fd(str, 2);
	ft_free_bonus(pipex);
	exit(EXIT_FAILURE);
}