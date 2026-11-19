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

    // Place a piece on H4.
    // H4 corresponds to bit 31.
    uint64_t piece = UINT64_C(1) << 31;

    // Shift left without applying a mask.
    uint64_t incorrect_move = piece << 1;

    printf("Original position (H4):\n");
    print_board(piece);

    printf("Shift without a mask:\n");
    print_board(incorrect_move);

    // Create a mask that removes every square on the H-file.
    const uint64_t not_file_h =
        UINT64_C(0x7f7f7f7f7f7f7f7f);

    // Apply the mask before shifting.
    uint64_t correct_move = (piece & not_file_h) << 1;

    printf("Shift after applying the mask:\n");
    print_board(correct_move);

    return 0;
}
