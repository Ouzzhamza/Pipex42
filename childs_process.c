#include    "pipex.h"


/* **************************************************** */
/*                  Handling the pathe                  */
/* **************************************************** */

void *path_handling(t_data *pipex, char **envp)
{
	char *temp;
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	pipex->path = (*envp + 5);
	char *command;
	temp = ft_strjoin(pipex->path, "/");
	while(pipex->path)
	{
		command = ft_strjoin(temp, pipex->cmd_args[0]);
		free(temp);
		if(access(command, X_OK) == 0 )
			return(pipex->cmd_path);
		free(command);
		pipex->path++;		
	}
	return(NULL);
}



void child_process1(t_data *pipex, char *av[], char **envp)
{
	close(pipex->end[0]);
	dup2(pipex->infile, STDIN_FILENO);
	dup2(pipex->end[1], STDOUT_FILENO);
	pipex->cmd_args = ft_split(av[2], ' ');
	pipex->cmd_path = path_handling(pipex, envp);
	if(!pipex->cmd_path)
	{
		ft_error();
	}
	execve(pipex->cmd_path, pipex->cmd_args, envp);
}



void child_process2(t_data *pipex, char *av[], char **envp)
{
	close(pipex->end[1]);
	dup2(pipex->outfile, STDOUT_FILENO);
	dup2(pipex->end[0], STDIN_FILENO);
	pipex->cmd_args = ft_split(av[3], ' ');
	pipex->cmd_path = path_handling(pipex, envp);
	if(!pipex->cmd_path)
	{
		ft_error();
	}
	execve(pipex->cmd_path, pipex->cmd_args, envp);
}