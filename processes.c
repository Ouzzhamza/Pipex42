#include    "pipex.h"


/* **************************************************** */
/*                  Handling the pathe                  */
/* **************************************************** */

char  *path_handling(char **path, char *cmd)
{
	char *temp;
	char *command;

	while(*path)
	{
		temp = ft_strjoin(*path, "/");
		command = ft_strjoin(temp, cmd);
		free(temp);
		if(access(command, X_OK) == 0 )
			return(command);
		free(command);
		path++;		
	}
	return(NULL);
}


void child_process(t_data *pipex, char *av[], char **envp)
{
	dup2(pipex->infile, STDIN_FILENO);
	dup2(pipex->end[1], STDOUT_FILENO);
	close(pipex->end[0]);

	pipex->cmd_args = ft_split(av[2], ' ');
	pipex->cmd = path_handling(pipex->cmd_path, pipex->cmd_args[0]);
	if(!pipex->cmd)
	{
		err_msg(ft_strjoin(CMD, pipex->cmd_args[0]));
		ft_putstr_fd("\n", 2);
		ft_free(pipex);
		exit(1);
	}
	execve(pipex->cmd, pipex->cmd_args, envp);
}


void parent_process(t_data *pipex, char *av[], char **envp)
{
	dup2(pipex->outfile, STDOUT_FILENO);
	dup2(pipex->end[0], STDIN_FILENO);
	close(pipex->end[1]);

	pipex->cmd_args = ft_split(av[3], ' ');
	pipex->cmd = path_handling(pipex->cmd_path, pipex->cmd_args[0]);
	if(!pipex->cmd)
	{
		err_msg(ft_strjoin(CMD, pipex->cmd_args[0]));
		ft_putstr_fd("\n", 2);
		ft_free(pipex);
		exit(1);
	}
	execve(pipex->cmd, pipex->cmd_args, envp);
}