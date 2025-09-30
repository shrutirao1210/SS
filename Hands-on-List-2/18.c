/*
============================================================================
Name : 18.c
Author : Rao Shruti Mohankumar (MT2025101)
Description : Write a program to find out total number of directories on the pwd.
                execute ls -l | grep ^d | wc ? Use only dup2.
Date: 21 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main()
{
    int pipefd[2], pipefd2[2];
    int cid, cid2;

    if (pipe(pipefd) == -1)
    {
        printf("ERROR");
    }
    if (pipe(pipefd2) == -1)
    {
        printf("ERROR");
    }
    else
    {
        cid = fork();
        if (cid == 0)
        {
            cid2 = fork();
            if (cid2 == 0)
            {
                close(pipefd[0]);  // closing unused pipe reading end of pipefd
                close(pipefd[1]);  // closing unused pipe writing end of pipefd
                close(pipefd2[1]); // closing unused pipe writing end of pipefd

                // closing stdin
                close(0);

                // reassigning stdin to pipe reading end;
                // dup2 will reassign pipefd2[0] to 0 as it avalible.so now pipefd2[0] will act as STDIN
                dup2(pipefd2[0], 0);
                execlp("wc", "wc", NULL);
            }
            else
            {
                close(pipefd[1]);  // closing unused pipe writing end of pipefd
                close(pipefd2[0]); // closing unused pipe resding end of pipefd

                // closing stdin
                close(0);
                // reassigning stdin to pipe reading end;
                // dup2 will reassign pipefd[0] to 0 as it avalible.so now pipefd[0] will act as STDIN
                dup2(pipefd[0], 0);

                // closing stdout
                close(1);
                // reassigning stdout to pipe writing end
                // dup2 will reassign pipefd2[1] to 1(STDOUT) as it is avalible fd. so now pipefd2[1] will act as STDOUT
                dup2(pipefd2[1], 1);
                execlp("grep", "grep", "^d", NULL);
            }
        }
        else
        {
            close(pipefd2[0]); // closing unused reading end
            close(pipefd2[1]); // closing unused writing end
            close(pipefd[0]);  // closing unused reading end

            close(1); // closing stdout
            // dup2 will reassign pipefd[1] to 1(STDOUT) as it is avalible fd. so now pipefd[1] will act as STDOUT
            dup2(pipefd[1], 1); // reassigning stdout to pipe writing end

            execlp("ls", "ls", "-l", NULL);
        }
    }
}

/*
============================================================================
Command line: cc 18.c && ./a.out
Output:     0     0    0
============================================================================
*/
