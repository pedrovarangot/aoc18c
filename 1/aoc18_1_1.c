#include <stdio.h>
#include <stdlib.h>

int main() {
    int frequency = 0;

    for (int input = 0; scanf("%d\n", &input) != EOF; frequency += input) {
        /* Empty loop */
    }

    printf("%d\n", frequency);

    return EXIT_SUCCESS;
}
