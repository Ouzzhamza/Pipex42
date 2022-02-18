/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:55:15 by houazzan          #+#    #+#             */
/*   Updated: 2022/02/18 19:21:29 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/pipex.h"
#include "../bonus/bonus_pipex.h"

void	ft_bzero(void *s, size_t n)
{
	char	*t;

	t = (char *)s;
	while (n > 0)
	{
		*(t++) = 0;
		n--;
	}
}
