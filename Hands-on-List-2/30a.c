/*
============================================================================
Name : 30a.c
Author : Rao Shruti Mohankumar (MT2025101)
Description : Write a program to create a shared memory.
                a. write some data to the shared memory
                b. attach with O_RDONLY and check whether you are able to overwrite.
                c. detach the shared memory
                d. remove the shared memory
Date: 23 Sept, 2025.
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
void main()
{
    key_t key = 12345;
    // shared memory created
    int shmid = shmget(key, 1024, IPC_CREAT | 0744);
    // attach shared memory to process adress space
    char *data;
    data = shmat(shmid, (void *)0, 0);
    printf("write in shared memory\n");
    scanf("%[^\n]", data);

    printf("data from shared memory : %s\n", data);
}
/*
============================================================================
Command line: cc 30a.c && ./a.out
Output: 
write in shared memory
Hello
data from shared memory : Hello
============================================================================
*/
