/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pipex.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:25:33 by houazzan          #+#    #+#             */
/*   Updated: 2022/02/18 20:59:32 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_PIPEX_H
# define BONUS_PIPEX_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<string.h>
# include	<unistd.h>
# include	<sys/wait.h>
# include	<sys/types.h>
# include   <fcntl.h>
# include   <errno.h> 


# define NUMBER   "insufficient Number of arguments.\n"
# define CMD   "command not found : "
# define PIPE   "Pipe"
# define FILE  "infile"
# define PATH "no path available"

typedef struct s_bonus
{
	int		infile;
	int		outfile;
	int		end[2];
	int		type;
	char	*path;
	char	*cmd;
	char	**cmd_args;
	char	**cmd_path;

}	t_bonus;



void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);



void	ft_error_bonus(t_bonus *pipex, char *str);
int		err_msg_bonus(t_bonus *pipex, char *str);
void	ft_free_bonus(t_bonus *pipex);
void	child_bprocess(t_bonus *pipex, char *av[], char **envp);
void	parent_bprocess(t_bonus *pipex, char *av[], char **envp);
void	create_pipes(t_bonus *pipex, int argc, char *argv[], char **envp);



#endif