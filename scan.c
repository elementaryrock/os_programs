#include<stdio.h>
#include<stdlib.h>

void main() {
    int ioq[20], i, n, j, ihead, temp, scan, tot;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the initial head position: ");
    scanf("%d", &ihead);

    ioq[0] = ihead; // First element is the head position
    ioq[1] = 0;     // Add 0th cylinder
    n += 2;         // Increase total number of elements to include head and 0

    printf("Enter the I/O queue requests:\n");
    for (i = 2; i < n; i++) {
        scanf("%d", &ioq[i]);
    }

    // Sort all requests including head and 0
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (ioq[j] > ioq[j + 1]) {
                temp = ioq[j];
                ioq[j] = ioq[j + 1];
                ioq[j + 1] = temp;
            }
        }
    }

    // Find the position of the head after sorting
    for (i = 0; i < n; i++) {
        if (ioq[i] == ihead) {
            scan = i;
            break;
        }
    }

    printf("\nOrder of request served:\n");

    // Move towards 0 (left side)
    for (i = scan; i > 0; i--) {
        printf("%d\t", ioq[i]);
    }
    printf("%d\t", ioq[0]);

    // From 0, go to the rightmost requests
    for (i = scan + 1; i < n; i++) {
        printf("%d\t", ioq[i]);
    }
    tot = abs(ihead - ioq[0]) + abs(ioq[n-1] - ioq[0]);
    printf("\n\nTotal Seek Distance: %d\n",tot);

}