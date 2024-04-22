# 42_pipex

## Allowed functions

- open
- close
- read
- write
- malloc
- free
- perror
- strerror
- access
- dup
- dup2
- execve
- exit
- fork
- pipe
- unlink
- wait
- waitpid
- library


## Research:

### perror
```#include <stdio.h>```

```void perror(const char *s);```

The perror() function produces a message on standard error describing the last error encountered during a call to a system or library function.

The perror() function takes a single argument, which is a string containing a brief description of the error.

### strerror
```#include <string.h>```

```char *strerror(int errnum);```

The strerror() function returns a pointer to a string that describes the error code passed in the argument errnum.

### access
```#include <unistd.h>```

```int access(const char *pathname, int mode);```

access() checks whether the calling process can access the file pathname. If pathname is a symbolic link, it is dereferenced.

### dup & dup2
```#include <unistd.h>```

```int dup(int oldfd);```

```int dup2(int oldfd, int newfd);```

The dup() system call creates a copy of the file descriptor oldfd, using the lowest-numbered unused file descriptor for the new descriptor.

After a successful return, the old and new file descriptors may be used interchangeably. They refer to the same open file description and thus share file offset and file status flags.

The dup2() system call performs the same task as dup(), but instead of using the lowest-numbered unused file descriptor, it uses the descriptor number specified in newfd. If the descriptor newfd was previously open, it is silently closed before being reused.

### execve
```#include <unistd.h>```

```int execve(const char *pathname, char *const argv[], char *const envp[]);```

execve() executes the program referred to by pathname. This causes the program that is currently being run by the calling process to be replaced with a new program, with newly initialized stack, heap, and data segments.

pathname must be a binary executable file, or a script starting with a line of the form:

```#!/bin/sh```

~~~
int main(int argc, char **argv, char **env) {
    // env is the environment and it is used for execve
    // execve kills the actual process and replaces it with the new one. Important to create chils to execute execve
}
~~~

### fork
```#include <sys/types.h>```
```#include <unistd.h>```

```pid_t fork(void);```

fork() creates a new process by duplicating the calling process. The new process is referred to as the child process. The calling process is referred to as the parent process.

The child process and the parent process run in separate memory spaces. At the time of fork() both memory spaces have the same content.

~~~
if (pid == 0)   // child process

if (pid == -1 ) // error

if (pid > 0)    // parent process

~~~

echo hola -> 2 -> pid 3
fork() -> 3

### pipe
```#include <unistd.h>```

```int pipe(int pipefd[2]);```

pipe() crates a pipe, a unidirectional data channel that can be used for interprocess communication. The array pipefd is used to return two file descriptors referring to the ends of the pipe. pipefd[0] refers to the read end of the pipe. pipefd[1] refers to the write end of the pipe. Data written to the write end of the pipe is buffered by the kernel until it is read from the read end of the pipe.

~~~

cd /proc/[pid]/fd

ls -l

used to look the info on the pipe

~~~

### unlink
```#include <unistd.h>```

```int unlink(const char *pathname);```

unlink() deletes a name from the filesystem. If that name was the last link to a file and no processes have the file open, the file is deleted and the space it was using is made available for reuse. 

If the name was the last link to a file but any processes still have the file open, the file will remain in existence until the last file descriptor referring to it is closed.

If the name referred to a symbolic link, the link is removed.

### wait & waitpid
```#include <sys/types.h>```

```#include <sys/wait.h>```

```pid_t wait(int *status);```

```pid_t waitpid(pid_t pid, int *wstatus, int options);```

All of these system calls are used to wait for state changes in a child of the calling process, and obtain information about the child whose state has changed. A state change is considered to be: the child was stopped by a signal; or the child was resumed by a signal. In the case of a terminated child, performing a wait allows the system to release the resources associated with the child; if a wait was not performed, then the terminated child remains in a "zombie" state.

The wait() system call suspends execution of the calling thread until one of its children terminates. 

The waitpid() system call suspends execution of the calling thread until a child specified by pid argument has changed state. By default, waitpid() waits only for terminated children, but this behavior is modifiable via the options argument.

~~~
returns the pid it has been waiting for or -1 if an error occurred.

waitpid with pid = -1 is the same as wait, it will wait for any child process (the one that lasts less time).

~~~

## About the project

The program will be executed as follows: &nbsp; ```./pipex file1 cmd1 cmd2 file2```

The program will take 4 arguments:
- **file1** and **file2** are **file names**
- **cmd1** and **cmd2** are **shell commands** with their parameters

It must behave exactly like:
```< file1 cmd1 | cmd2 > file2```

### Execution examples

```./pipex infile "ls -l" "wc -l" outfile```

Should behave like: &nbsp;
```./pipex infile ls -l | wc -l > outfile```

<br>

```./pipex infile "grep a1" "wc -w" outfile```

Should behave like: &nbsp;
```./pipex infile grep a1 | wc -w > outfile```


## To do

1. Check that infile exists, if not trigger an error

2. Check that outfile exists, if not create it

3. Check both commands are valid, if not trigger an error

## More info

Proceso huerfano: se queda sin papi

Proceso zombie: el padre no recoge al hijo (wait & waitpid)