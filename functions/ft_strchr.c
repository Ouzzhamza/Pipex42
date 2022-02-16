/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:55:59 by houazzan          #+#    #+#             */
/*   Updated: 2022/02/16 21:35:44 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/pipex.h"
#include "../bonus/pipex_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;
	char	*b;

	b = ((char *) s);
	i = 0;
	a = (char) c;
	if (c == 0)
		return (b + ft_strlen(b));
	while (b[i])
	{
		if (b[i] == a)
			return (&b[i]);
		i++;
	}
	return (NULL);
}
