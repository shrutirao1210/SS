/*
============================================================================
Name : 30d.c
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
#include <fcntl.h>
int main()
{
    key_t key = 12345;
    // shared memory created
    int shmid = shmget(key, 1024, IPC_CREAT | 0744);
    // attach shared memory to process adress space
    char *data_pointer;
    data_pointer = shmat(shmid, (void *)0, 0);
    if (data_pointer == (void *)-1)
    {
        perror("Shared memory not attach");
        return 1;
    }
    printf("Shared memory attached press any key to delete shared memory\n");
    getchar();
    printf("Deleting shared memory\n");
    shmctl(key, IPC_RMID, NULL);
    return 1;
}
/*
============================================================================
Command line: cc 30d.c && ./a.out
Output: 
Shared memory attached press any key to delete shared memory

Deleting shared memory
============================================================================
*/
