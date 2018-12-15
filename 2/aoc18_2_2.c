#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_WL 256
#define MAX_WORDS 256

bool check_diff(const char left[static 1], const char right[static 1]) {
    unsigned differences = 0;

    for(size_t c = 0; left[c] != '\0'; c++) {
        if(left[c] != right[c]) differences++;
    }

    return (differences == 1);
}

int main() {
    char words[MAX_WORDS][MAX_WL] = {{0}};
    size_t lines = 0;

    while(fgets(words[lines++], MAX_WL, stdin) != NULL) {
        /* Fill up array */
    }

    for(size_t i = 0; i < lines; i++) {
        for(size_t j = i; j < lines; j++) {
            if(check_diff(words[i], words[j])) {
                printf("%s%s", words[i], words[j]);
            }
        }
    }

    return EXIT_SUCCESS;
}
