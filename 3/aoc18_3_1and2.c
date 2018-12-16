#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* #define PRINT_FABRIC true */
#undef PRINT_FABRIC

#define FABRIC_SIZE 1000
#define MAX_CLAIMS 1500
typedef struct {
    unsigned n_claimed;
    unsigned first_claim;
} claim_cell;
static claim_cell fabric[FABRIC_SIZE][FABRIC_SIZE] = {{{0}}};

typedef struct {
    unsigned claim_no; /* To avoid 0 being a valid claim data */
    unsigned x;
    unsigned y;
    unsigned w;
    unsigned l;
} claim;
static claim claims[MAX_CLAIMS] = {{0}};

int main() {
    unsigned int elfno, x, y, w, l;

    while (scanf("#%u @ %u,%u: %ux%u\n", &elfno, &x, &y, &w, &l) != EOF) {
        claims[elfno] =
            (claim){.claim_no = elfno, .x = x, .y = y, .w = w, .l = l};

        for (size_t i = x; i < x + w; ++i) {
            for (size_t j = y; j < y + l; ++j) {
                fabric[j][i].n_claimed++;
                if (fabric[j][i].first_claim == 0) {
                    fabric[j][i].first_claim = elfno;
                }
            }
        }
    }

    unsigned inches = 0;
    for (size_t i = 0; i < FABRIC_SIZE; ++i) {
        for (size_t j = 0; j < FABRIC_SIZE; ++j) {
            if (fabric[j][i].n_claimed >= 2)
                inches++;
        }
    }

    /* Loop through claims to find claim that doesn't overlap */
    size_t the_claim = 0; /* Claim 0 doesn't exist */
    for (size_t c = 1; claims[c].claim_no != 0; c++) {
        the_claim = claims[c].claim_no;

        for (size_t i = claims[c].x;
             the_claim != 0 && i < claims[c].x + claims[c].w; ++i) {
            for (size_t j = claims[c].y; j < claims[c].y + claims[c].l; ++j) {
                /* For each claims' patch, see if area is uniquely claimed */
                if (fabric[j][i].n_claimed > 1) {
                    the_claim = 0;
                    break;
                }
            }
        }

        if (the_claim != 0)
            printf("Solution 2: %zd\n", the_claim);
    }

/* Code to print all fabric with number of claims and first claimant */
#ifdef PRINT_FABRIC
#define PRINT_FABRIC_SIZE 10
    for (size_t i = 0; i < PRINT_FABRIC_SIZE; ++i) {
        for (size_t j = 0; j < PRINT_FABRIC_SIZE; ++j) {
            printf("%02u %04u|", fabric[i][j].n_claimed,
                   fabric[i][j].first_claim);
        }
        puts("");
    }
#endif

    printf("Solution 1: %u\n", inches);

    return EXIT_SUCCESS;
}
