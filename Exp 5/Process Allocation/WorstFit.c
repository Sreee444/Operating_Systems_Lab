#include <stdio.h>

struct memory {
    int size, alloc, index;
};

struct process {
    int psize, flag;
};

int main() {
    int memblock, limit, i, j;

    printf("\t\t WORST FIT\t\n");
    printf("Enter the number of memory blocks: ");
    scanf("%d", &memblock);

    struct memory m[memblock];

    printf("Enter the size of memory blocks:\n");
    for(i = 0; i < memblock; i++) {
        scanf("%d", &m[i].size);
        m[i].alloc = 0;
        m[i].index = i + 1;
    }

    for(i = 0; i < memblock; i++) {
        for(j = i + 1; j < memblock; j++) {
            if(m[i].size < m[j].size) {
                struct memory temp = m[i];
                m[i] = m[j];
                m[j] = temp;
            }
        }
    }

    printf("Enter the number of processes: ");
    scanf("%d", &limit);

    struct process p[limit];

    printf("Enter the size of each process:\n");
    for(i = 0; i < limit; i++) {
        scanf("%d", &p[i].psize);
        p[i].flag = 0;
    }

    printf("\n\tPROCESS\t\tPROCESS SIZE\tBLOCK SIZE\tBLOCK NO.\n");
    for(i = 0; i < limit; i++) {
        for(j = 0; j < memblock; j++) {
            if(p[i].flag == 0 && p[i].psize <= m[j].size && m[j].alloc == 0) {
                m[j].alloc = 1;
                p[i].flag = 1;
                printf("\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, p[i].psize, m[j].size, m[j].index);
                break;
            }
        }
    }

    for(i = 0; i < limit; i++) {
        if(p[i].flag == 0) {
            printf("\n\tNo available memory block for process of size %d\n", p[i].psize);
        }
    }

    return 0;
}
