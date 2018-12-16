#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZES ((int)1000000)
static int frequencies[MAX_SIZES] = {0};
#define FREQ_IDX(_f) (_f >= 0 ? _f : _f + MAX_SIZES / 2 + 1)
static int input_buff[MAX_SIZES] = {0};

void check_frequency(int frequency) {
    frequencies[FREQ_IDX(frequency)]++;
    if (frequencies[FREQ_IDX(frequency)] == 2) {
        printf("%d\n", frequency);
        exit(EXIT_SUCCESS);
    }
}

int main() {
    size_t input_len = 0;
    int frequency = 0;
    frequencies[0]++;

    /* Process input and fill buffer for input looping */
    for (int input = 0; scanf("%d\n", &input) != EOF; input_len++) {
        input_buff[input_len] = input;
        frequency += input;
        check_frequency(frequency);
    }

    /* Loop until a frequency is seen two times */
    for (size_t i = 0; i < input_len; i = (i + 1) % input_len) {
        frequency += input_buff[i];
        check_frequency(frequency);
    }

    puts("This should never happen\n");

    return EXIT_FAILURE;
}
