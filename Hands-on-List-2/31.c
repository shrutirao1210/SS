/*
============================================================================
Name : 31.c
Author : Rao Shruti Mohankumar (MT2025101)
Description : Write a program to create a semaphore and initialize value to the semaphore.
                a. create a binary semaphore
                b. create a counting semaphore
Date: 23 Sept, 2025.
============================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
typedef union semun
{
    int val;                   // val for set val /* 1 for binary else > 1 for Counting Semaphore */
    struct semid_ds *buf;      // Data structure describing a set of semaphores.
    unsigned short int *array; // array for GETALL, SETALL
} semun;

int main()
{
    semun arg;
    key_t key = ftok(".", 3);
    int semid = semget(key, 1, IPC_CREAT | 0744);
    arg.val = 1; // 1 for binary
    printf("binary semaphore created\n");
    semctl(semid, 0, SETVAL, arg); // set val of binary semaphore to 0;

    // counting semaphore
    semun args;
    key = ftok(".", 4);
    semid = semget(key, 1, IPC_CREAT | 0744);
    args.val = 10; // 1 for binary
    printf("counting semaphore created size is :%d \n", args.val);
    semctl(semid, 1, SETVAL, args); // set val of binary semaphore to 0;

    return 0;
}
/*
============================================================================
Command line: cc 31.c && ./a.out
Output: 
binary semaphore created
counting semaphore created size is :10 
============================================================================
*/
