#include    "pipex.h"

void child_process(t_data *pipex, char *av[])
{
	if(dup2(pipex->file1, STDIN_FILENO) == -1)
		ft_error();
//	int fd = open(av[1], O_RDONLY);
	ft_putstr_fd(av[2], pipex->file1);
}