/*
============================================================================
Name : 19.c
Author : Rao Shruti Mohankumar (MT2025101)
Description : Create a FIFO file by
                a. mknod command
                b. mkfifo command
                c. use strace command to find out, which command (mknod or mkfifo) is better.
                c. mknod system call
                d. mkfifo library function
Date: 21 Sept, 2025.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    // Create a FIFO named "my_fifo" using mknod system call
    if (mknod("my_fifo", __S_IFIFO | 0666, 0) == -1) {
        perror("mknod failed");
        return 1;
    }
    printf("FIFO 'my_fifo' created using mknod system call.\n");

    // Create a FIFO named "my__fifo" using mkfifo system call
    if (mkfifo("my__fifo", 0666) == -1) {
        perror("mkfifo failed");
        return 1;
    }
    printf("FIFO 'my_fifo' created using mkfifo library function.\n");
    return 0;
}


/*
============================================================================
Command line: cc 19.c && ./a.out
Output:
FIFO 'my_fifo' created using mknod system call.
FIFO 'my__fifo' created using mkfifo library function.
============================================================================
*/
