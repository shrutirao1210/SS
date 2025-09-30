/*
============================================================================
Name : 10a.c
Author : Rao Shruti Mohankumar (MT2025101)
Description : Write a separate program using sigaction system call to catch the following signals.
                a. SIGSEGV
                b. SIGINT
                c. SIGFPE
Date: 20 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Signal handler function for SIGSEGV
void handle_sigsegv(int sig) {
    printf("Caught SIGSEGV: Segmentation Fault\n");
    exit(1);  // Exit the program after catching the signal
}

int main() {
    struct sigaction sa;

    // Setting up SIGSEGV handler
    sa.sa_handler = handle_sigsegv;
    sigemptyset(&sa.sa_mask);  // No signals blocked during the execution of the handler
    sa.sa_flags = 0;  // No special flags
    sigaction(SIGSEGV, &sa, NULL);  // Register the handler for SIGSEGV

    // Trigger a SIGSEGV for testing purposes by accessing invalid memory
    int *ptr = NULL;
    *ptr = 42;  // This will trigger SIGSEGV

    return 0;
}

/*
============================================================================
Command line: cc 10a.c && ./a.out
Output: 
Caught SIGSEGV: Segmentation Fault
============================================================================
*/
