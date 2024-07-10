# 42_pipex

Statement of the project (in [Spanish](es.subject.pdf) / [English](en.subject.pdf))

## About the project

The goal of the project is to discover a mechanism of Unix, **pipes**.

A **pipe** is a feature used to connect the output of one command directly into the input of another command. This allows users to create complex command sequences by combining simple commands, effectively enabling the chaining of multiple commands to perform sophisticated tasks. It takes the standard output (**stdout**) of one command and feeds it as the standard input (**stdin**) to another command.

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