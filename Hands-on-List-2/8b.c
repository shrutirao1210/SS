/*
============================================================================
Name : 8b.c
Author : Rao Shruti Mohankumar (MT2025101)
Description : Write a separate program using signal system call to catch the following signals.
                a. SIGSEGV
                b. SIGINT
                c. SIGFPE
                d. SIGALRM (use alarm system call)
                e. SIGALRM (use setitimer system call)
                f. SIGVTALRM (use setitimer system call)
                g. SIGPROF (use setitimer system call)
Date: 20 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// Signal handler function for SIGINT (Ctrl+C)
void handle_sigint(int sig) {
    printf("Caught SIGINT: Interrupt from keyboard (Ctrl+C)\n");
    exit(0);  // Exit the program gracefully after catching the signal
}

int main() {
    // Register the signal handler for SIGINT
    if(signal(SIGINT, handle_sigint) == SIG_ERR){
        printf("Error in setting sig");
    }

    // Infinite loop to keep the program running until interrupted
    while (1);

    return 0;
}


/*
============================================================================
Command line: cc 8b.c && ./a.out
Output: 
Caught SIGINT: Interrupt from keyboard (Ctrl+C)
============================================================================
*/
