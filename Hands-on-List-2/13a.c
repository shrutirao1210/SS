/*
============================================================================
Name : 13a.c
Author : Rao Shruti Mohankumar (MT2025101)
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
                will send the signal (using kill system call). Find out whether the first program is able to catch
                the signal or not.
Date: 21 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function for catching signals
void signal_handler() {
    // if (sig == SIGINT) {
    //     printf("Caught SIGINT (Ctrl+C)\n");
    // } else if (sig == SIGSTOP) {
    //     printf("Caught SIGTSTP (Ctrl+Z)\n");
    // } else {
    //     printf("Caught signal %d\n", sig);
    // }
    printf("Caught SIGTSTP (Ctrl+Z)\n");
}

int main() {
    // Set up signal handler for SIGINT and SIGTSTP (just as an example)
     // Catch Ctrl+C
    signal(SIGSTOP, signal_handler); // Catch Ctrl+Z
    
    // Inform the user
    printf("Waiting for signals (SIGSTOP cannot be caught)\n");
    
    // Infinite loop to keep the program running and waiting for signals
    while (1) {
        sleep(30);  // Wait for signals
    }

    return 0;
}

/*
============================================================================
Command line: cc 13a.c && ./a.out
Output: 
============================================================================
*/

/* 
    A program cannot catch a SIGSTOP signal.We can conclude this by observing that the customHandler function is never executed and instead the program is terminated !
    Two signals that cannot be caught or ignored
    SIGSTOP
    SIGKILL
*/
