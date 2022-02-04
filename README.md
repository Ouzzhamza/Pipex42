# Pipex

Pipex is a 42school project that reproduces the same behaviour as the command shell pipe **|** , the programme will lunch as  **./pipex file1 cmd1 cmd2 file2** and behave exactely as as this shell command line **< infile cmd1 | cmd2 > outfile**.

This programme will be written in C language, using the following functions : 
 access(), open(), unlink(), close(), read(), write(), malloc(), waitpid(), wait(), free(), pipe(), dup(), dup2(), execve(), fork(), perror(), strerror() and exit().

## Description 

### access()
  Prototype :
  ```
  access(const char *path, int mode);
  ```
  The function checks the file corresponding to the **path** following to the given **mode** 
  
  **F__OK** Existence of the file.
  
  **X_OK** Execute permission.
  
  **W_OK** Write permission.
  
  **R_OK** Read permission.
  
  ### unlink()
  Prototype : 
  ```
  int  unlink ( const  char  * path );
  ```
  The function deletes the given file as **pathe** by breaking the hard link 
  
  ####  -exemple 
  ```
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
```
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
### fork()
Prototype :
```
pid_t  fork ( void );
```
Create a child process from the current running one "parent process", withe the exact same since.
The only difference between the parent process and the child process is the assigned value: it returns 0 for the child process, a non-zero number for the parent process.

### wait()
Prototype : 
``` 
pid_t  wait ( int  * status );
```
Suspend the execution of the main process untill all of the sub_processes created by **fork()** terminates
  
 
