#include <stdio.h>
#include <stdint.h>

void print_board(uint64_t board) {
    for (int rank = 7; rank >= 0; rank--) {
        for (int file = 0; file < 8; file++) {
            int square = rank * 8 + file;

            if (board & (UINT64_C(1) << square)) {
                printf("1 ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {

    // Start with a piece on D4.
    // D4 corresponds to bit 27.
    uint64_t piece = UINT64_C(1) << 27;

    printf("Starting position (D4):\n");
    print_board(piece);

    // Move one square to the right.
    uint64_t right = piece << 1;

    printf("One square to the right (E4):\n");
    print_board(right);

    // Move one square to the left.
    uint64_t left = piece >> 1;

    printf("One square to the left (C4):\n");
    print_board(left);

    // Move one rank upward.
    uint64_t up = piece << 8;

    printf("One rank upward (D5):\n");
    print_board(up);

    // Move one rank downward.
    uint64_t down = piece >> 8;

    printf("One rank downward (D3):\n");
    print_board(down);

    return 0;
}
