#include <stdio.h>

int main() {
    int memblock, limit, i, j;
    printf("\t\t FIRST FIT\t\n");
    printf("Enter the number of memory blocks: ");
    scanf("%d", &memblock);

    struct memory {
        int size, alloc;
    } m[memblock];

    printf("Enter the size of memory block:\n");
    for (i = 0; i < memblock; i++) {
        scanf("%d", &m[i].size);
        m[i].alloc = 0;
    }

    printf("Enter the number of processes: ");
    scanf("%d", &limit);

    struct process {
        int psize, flag;
    } p[limit];

    printf("Enter the size of process:\n");
    for (i = 0; i < limit; i++) {
        scanf("%d", &p[i].psize);
        p[i].flag = 0;
    }

    printf("\n\tPROCESS\t\tPROCESS SIZE\tBLOCK SIZE\n");
    for (i = 0; i < limit; i++) {
        for (j = 0; j < memblock; j++) {
            if (p[i].flag == 0) {
                if (p[i].psize <= m[j].size) {
                    if (m[j].alloc == 1) {
                        continue;
                    }
                    else {
                        m[j].alloc = 1;
                        p[i].flag = 1;
                        printf("\t%d\t\t%d\t\t%d\n", i + 1, p[i].psize, m[j].size);
                        break;
                    }
                }
            }
        }
    }

    for (i = 0; i < limit; i++) {
        if (p[i].flag == 0) {
            printf("\n\tThere is no space for process %d with size %d\n", i + 1, p[i].psize);
        }
    }
}
