#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_LETTERS ('z' - 'a' + 1)

void count_letters(const char word[static 1],
                   unsigned letter_c['z' - 'a' + 1]) {
    memset_s(letter_c, NUM_LETTERS * sizeof(letter_c[0]), 0,
             NUM_LETTERS * sizeof(letter_c[0]));
    for (size_t i = 0; isalpha(word[i]); ++i) {
        letter_c[word[i] - 'a']++;
    }
}

static char line_buf[256];

int main() {
    unsigned letter_c[NUM_LETTERS] = {0};
    /* Variables and flags to count two and three letters once per word */
    unsigned c2l = 0, c3l = 0;
    bool set_c2l = false, set_c3l = false;

    for (; fgets(line_buf, 255, stdin) != NULL; set_c2l = set_c3l = false) {
        count_letters(line_buf, letter_c);

        for (size_t i = 0; i < NUM_LETTERS; i++) {
            if (letter_c[i] == 2 && false == set_c2l) {
                printf("two %zd\n", i);
                c2l++;
                set_c2l = true;
            }
            if (letter_c[i] == 3 && false == set_c3l) {
                printf("three %zd\n", i);
                c3l++;
                set_c3l = true;
            }
        }
    }

    printf("%u", c2l * c3l);

    return EXIT_SUCCESS;
}
