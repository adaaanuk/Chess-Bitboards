#include <stdio.h>
#include <stdint.h>

int main(void) {

    // Two example bitboards.
    uint64_t board_a = UINT64_C(0x000000000000000F);
    uint64_t board_b = UINT64_C(0x0000000000000005);

    // AND: Keeps bits that are 1 in both bitboards.
    uint64_t and_result = board_a & board_b;

    // OR: Sets bits that are 1 in either bitboard.
    uint64_t or_result = board_a | board_b;

    // XOR: Sets bits that are different.
    uint64_t xor_result = board_a ^ board_b;

    // NOT: Flips every bit.
    uint64_t not_result = ~board_a;

    printf("Board A:  0x%016llX\n",
           (unsigned long long)board_a);

    printf("Board B:  0x%016llX\n",
           (unsigned long long)board_b);

    printf("AND:      0x%016llX\n",
           (unsigned long long)and_result);

    printf("OR:       0x%016llX\n",
           (unsigned long long)or_result);

    printf("XOR:      0x%016llX\n",
           (unsigned long long)xor_result);

    printf("NOT A:    0x%016llX\n",
           (unsigned long long)not_result);

    return 0;
}
