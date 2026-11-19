#include <stdio.h>
#include <stdint.h>

// Print a bitboard as an 8x8 chessboard.
void print_bitboard(uint64_t board) {
    for (int rank = 7; rank >= 0; rank--) {
        for (int file = 0; file < 8; file++) {

            // Find the bit that corresponds to this square.
            int square = rank * 8 + file;

            // Check whether that bit is set to 1.
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

    // Create a bitboard with a piece on A1.
    uint64_t a1 = UINT64_C(1) << 0;

    // Create a bitboard with a piece on B1.
    uint64_t b1 = UINT64_C(1) << 1;

    // Create a bitboard with a piece on H1.
    uint64_t h1 = UINT64_C(1) << 7;

    printf("Piece on A1:\n");
    print_bitboard(a1);

    printf("Piece on B1:\n");
    print_bitboard(b1);

    // OR combines the squares from two bitboards.
    uint64_t combined = a1 | b1;

    printf("A1 OR B1:\n");
    print_bitboard(combined);

    // AND checks which squares are shared.
    uint64_t shared = combined & a1;

    printf("Combined AND A1:\n");
    print_bitboard(shared);

    // XOR keeps bits that are different.
    uint64_t different = combined ^ a1;

    printf("Combined XOR A1:\n");
    print_bitboard(different);

    // Shift the piece on A1 one square to the right.
    uint64_t shifted = a1 << 1;

    printf("A1 shifted left by one bit:\n");
    print_bitboard(shifted);

    // Demonstrate the H-file wraparound problem.
    uint64_t wrapped = h1 << 1;

    printf("H1 shifted left without a mask:\n");
    print_bitboard(wrapped);

    // This mask has 0s on the H-file and 1s everywhere else.
    const uint64_t not_file_h =
        UINT64_C(0x7f7f7f7f7f7f7f7f);

    // Remove H-file bits before shifting.
    uint64_t masked = (h1 & not_file_h) << 1;

    printf("H1 shifted left after applying the mask:\n");
    print_bitboard(masked);

    return 0;
}
