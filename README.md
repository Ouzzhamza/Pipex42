# Pipex

Pipex is a 42school project that reproduces the same behaviour as the command shell pipe **|** , the programme will lunch as  **./pipex file1 cmd1 cmd2 file2** and behave exactely as as this shell command line **< infile cmd1 | cmd2 > outfile**.

This programme will be written in C language, using the following functions : 
 access(), open(), unlink(), close(), read(), write(), malloc(), waitpid(), wait(), free(), pipe(), dup(), dup2(), execve(), fork(), perror(), strerror() and exit().

## Description 

### fork()
Prototype :
```c
pid_t  fork ( void );
```
Create a child process from the current running one "parent process", withe the exact same since.
The only difference between the parent process and the child process is the assigned value: it returns 0 to the child process, a child [PID](https://en.wikipedia.org/wiki/Process_identifier#:~:text=In%20computing%2C%20the%20process%20identifier,uniquely%20identify%20an%20active%20process.) to the parent porcess, or -1 to the parent process in case of an error.

### wait()
Prototype : 
```c
pid_t  wait ( int  * status );
```
Suspend the execution of the main process until all of the sub_processes(child process) created by **fork()** terminates.
in case there is no child process the function returns **-1**, if the child process exists but not terminated or stopped it returns **0**, and returns the pid of the child process terminated on success.

####  -exemple 
without wait();

```c
#include	<stdio.h>
#include	<unistd.h>
#include	<sys/wait.h>
int main(int argc, char *argv[])
{
	int id = fork();
	int n;
	if(id  == 0)
	{
		n = 1;
	}
	else
	{
		n = 6;
	}
		// if(id != 0)
		// {
		// 	wait(NULL);
		// }
	int i;
	for(i = n; i < n + 5; i++)
	{
		printf("%d ", i);
	}
	return(0);
}
```

```c
┌──(cyber-z3ter㉿kali)-[~/Desktop]
└─$ gcc exemple.c
                                                                                
┌──(cyber-z3ter㉿kali)-[~/Desktop]
└─$ ./a.out        
6 7 8 9 10 1 2 3 4 5  

```

with wait();

```c
#include	<stdio.h>
#include	<unistd.h>
#include	<sys/wait.h>
int main(int argc, char *argv[])
{
	int id = fork();
	int n;
	if(id  == 0)
	{
		n = 1;
	}
	else
	{
		n = 6;
	}
		 if(id != 0)
		 {
		     wait(NULL);
		 }
	int i;
	for(i = n; i < n + 5; i++)
	{
		printf("%d ", i);
	}
	return(0);
}
```

```c
┌──(cyber-z3ter㉿kali)-[~/Desktop]
└─$ gcc exemple.c
                                                                                
┌──(cyber-z3ter㉿kali)-[~/Desktop]
└─$ ./a.out      
1 2 3 4 5 6 7 8 9 10

```

### waitpid()

Prototype : 
```c
pid_t  waitpid(pid_t pid, int *stat_loc, int options);
```

Waitpid() waits for a specific child equal to pid (given as paranmetre) to terminate.

### pipe()
  Prototype :
  ```c
  int pipe(int fildes[2]);
  ```
  Ensure the communication between processes, or in some cases with itself. and all of this is possible thank's to the two files descriptor stored by the **pipe** function 
  
  

### access()
  Prototype :
  ```c
  access(const char *path, int mode);
  ```
  The function checks the file corresponding to the **path** following to the given **mode** 
  
  **F__OK** Existence of the file.
  
  **X_OK** Execute permission.
  
  **W_OK** Write permission.
  
  **R_OK** Read permission.
  
  ### unlink()
  Prototype : 
  ```c
  int  unlink ( const  char  * path );
  ```
  The function deletes the given file as **pathe** by breaking the hard link 
  
  ####  -exemple 
  ```c
#include	<stdio.h>
#include	<unistd.h>
int main(int argc, char *argv[])
{
	int i = 1;
	while(i < argc)
	{
		if(access(argv[i], F_OK) == 0) // checks the file if it exist
		{
			if(unlink(argv[i]) == 0)
			{
				printf("The file unlinked\n");
			}
			else
				printf("The file still linked\n");
		}
		else
			printf("The file doesn't exist\n");
		i++;
	}
	return(0);
}
  ```
```c
┌──(cyber-z3ter㉿kali)-[~/Desktop]
└─$ ls             
a.out  exemple.c  Pipex
                                                                                                                                                                                                                                              
┌──(cyber-z3ter㉿kali)-[~/Desktop]
└─$ ./a.out a b c d
The file doesn't exist
The file doesn't exist
The file doesn't exist
The file doesn't exist
                                                                                                                                                                                                                                              
┌──(cyber-z3ter㉿kali)-[~/Desktop]
└─$ touch a b c d  
                                                                                                                                                                                                                                              
┌──(cyber-z3ter㉿kali)-[~/Desktop]
└─$ ls             
a  a.out  b  c  d  exemple.c  Pipex
                                                                                                                                                                                                                                              
┌──(cyber-z3ter㉿kali)-[~/Desktop]
└─$ ./a.out a b c d
The file unlinked
The file unlinked
The file unlinked
The file unlinked
                                                                                                                                                                                                                                              
┌──(cyber-z3ter㉿kali)-[~/Desktop]
└─$ ls             
a.out  exemple.c  Pipex
```



### dup() and dup2()

Prototype : 
```c
 int dup(int fildes);
 int dup2( int oldfd, int targetfd ); 
```


  
 
