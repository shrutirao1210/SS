/*
============================================================================
Name : 4.c
Author : Rao Shruti Mohankumar (MT2025101)
Description : Write a program to measure how much time is taken to execute 100 getppid ( )
                system call. Use time stamp counter.
Date: 19 Sept, 2025.
============================================================================
*/

#include <stdio.h>     // Standard I/O functions
#include <stdint.h>    // For uint64_t type
#include <x86intrin.h> // For __rdtsc() intrinsic to access TSC
#include <unistd.h>    // For getppid() system call

int main() {
    uint64_t start, end; // Variables to store the start and end TSC values
    int i;

    // Read the Time Stamp Counter before the loop starts
    start = __rdtsc();

    // Execute getppid() 100 times in a loop
    for (i = 0; i < 100; i++) {
        getppid();
    }

    // Read the Time Stamp Counter after the loop ends
    end = __rdtsc();

    // Calculate and print the time taken in clock cycles
    printf("Time taken for 100 getppid() calls: %lu clock cycles\n", (end - start));

    return 0;
}

/*
============================================================================
Command line: cc 4.c && ./a.out
Output: 
Time taken for 100 getppid() calls: 123839 clock cycles
============================================================================
*/
