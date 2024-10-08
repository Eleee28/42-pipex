<p align="center">
    <img src="https://github.com/ayogun/42-project-badges/blob/main/badges/pipexm.png" alt="pipex badge">
</p>

<h1 align="center">
    42 Pipex
</h1>

<!-- # 42_pipex -->

Statement of the project (in [Spanish](es.subject.pdf) / [English](en.subject.pdf))

## Introduction

This project is designed to deepen your understanding of Unix mechanisms, particularly **pipes**, **processes**, and **inter-process communication**. By the end of this project, you will have created a program that mimics the shell's piping capabilities, allowing to connect the output of one command directly into the input of another.  

## About the project

### Pipes

A **pipe** is a unidirectional data channel that can be used for inter-process communication. It allows the output (stdout) of one process to be used as the input (stdin) of another. This is a fundamental concept in Unix-based systems that enables the chaining of commands to perform complex tasks efficiently.

### Processes and forking

A **process** is an instance of a running program. WHen a program is executed, a new proces is created. In Unix, you can create new processes using the `fork()` system call.

- `fork()` : This system call creates a new process by duplicating the calling process. The new process is called the child process. The `fork()` function returns a Process ID (PID):
    - **0** to the child process.
    - The PID of the child process to the parent process.
    - **-1** if an error occurred.

**Example:**
```c
    pid_t pid = fork();
    if (pid == 0) {
        // This is the child process
    } else if (pid > 0) {
        // This is the parent process
    } else {
        // Fork failed
    }
```

### Wait and Waitpid

To manage child processes, you often need to wait for them to finish executing.
- `wait()` : This function makes the parent wait until any of its child processes have finished executing.
- `waitpid()` : This function allows you to wait for a specific child process to finish.

&nbsp;

```
    Parent Process (PID: 1000)
    |
    +--- fork() ---> Child Process 1 (PID: 1001)
    |                    |
    |                    +--- pipe1 (Parent to Child 1)
    |
    +--- fork() ---> Child Process 2 (PID: 1002)
                         |
                         +--- pipe2 (Parent to Child 2)
```

Legend:

- Parent Process communicates with Child Process 1 through pipe1
- Parent Process communicates with Child Process 2 through pipe2

## Mandatory part

The program must run in the following way:

    ./pipex file1 command1 command2 file2

And it must do the same as:

    < file1 command1 | command2 > file2

Errors must be handled in the same way as the shell commands.

## Bonus part

The bonus part consists on handling multiple pipes:

    ./pipex file1 command1 command2 command3 ... commandN file2

Must behave as:

    < file1 command1 | command2 | command3 | ... | commandN > file2

And also accepting << and >> when the first parameter is "here_doc" :

    ./pipex here\_doc DELIMITER command command1 file

Must behave as:

    command << DELIMITER | command1 >> file

## Implementation Steps

1. **Parse Arguments**: Extract the file names and commands from the program's arguments.

2. **Create Pipes**: Use the pipe() system call to create the necessary pipes for inter-process communication.

3. **Fork Processes**: Use fork() to create child processes for each command.

4. **Redirect Input/Output**: Use dup2() to redirect the stdin and stdout for each process.

5. **Execute Commands**: Use execve() to execute the commands in the child processes.

6. **Handle Errors**: Ensure that your program handles errors gracefully, similar to how the shell would.
