#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 3;

void wait(int *s) {
    (*s)--;
}

void signal(int *s) {
    (*s)++;
}

void producer() {
    wait(&mutex);
    signal(&full);
    wait(&empty);
    signal(&mutex);
}

void consumer() {
    wait(&mutex);
    wait(&full);
    signal(&empty);
    signal(&mutex);
}

int main() {
    int ch;

    while (1) {
        printf("Choose an Operation : \n");
        printf("1 : Producer \n");
        printf("2 : Consumer\n");
        printf("3 : Exit\n");
        printf("Enter choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (mutex == 1 && empty > 0) {
                    producer();
                    printf("Produced an item successfully\n");
                } else {
                    printf("BUFFER FULL!!\n");
                }
                break;

            case 2:
                if (mutex == 1 && full > 0) {
                    consumer();
                    printf("Consumed an item successfully\n");
                } else {
                    printf("BUFFER EMPTY!!\n");
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Wrong choice\n");
        }
    }

    return 0;
}
