#include <sys/mman.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>

#define PAGE_SIZE (4*1024)
#define START_ADDRESS 0x8000000
#define START_ADDRESS2 0x800000000
//#define N_ITERATIONS 524288

// one more iteration and mmap fails
#define N_ITERATIONS 524289

void allocate(void* base_address)
{
    long long int i;
    for (i = 0; i < N_ITERATIONS; ++i) {
        void* current_addr = base_address + PAGE_SIZE * i;
        void* ret = mmap((void*)current_addr, PAGE_SIZE, PROT_EXEC|PROT_READ|PROT_WRITE, 
                MAP_NORESERVE | MAP_FIXED | MAP_PRIVATE|MAP_ANONYMOUS, 0, 0);
        if (ret == MAP_FAILED) {
            fprintf(stderr, "Error mmap. errno: %d\n", errno);
            exit(-1);
        }
        printf("%d\n", i);
    }
}

int main()
{
    printf("%zu", sizeof(void*));
    allocate((void*)START_ADDRESS);
    allocate((void*)START_ADDRESS2);
    return 0;
}
