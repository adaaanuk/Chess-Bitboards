CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: bitboard_demo bitwise_operators bitboard_shifts bitboard_masks

bitboard_demo: src/bitboard_demo.c
	$(CC) $(CFLAGS) src/bitboard_demo.c -o bitboard_demo

bitwise_operators: src/bitwise_operators.c
	$(CC) $(CFLAGS) src/bitwise_operators.c -o bitwise_operators

bitboard_shifts: src/bitboard_shifts.c
	$(CC) $(CFLAGS) src/bitboard_shifts.c -o bitboard_shifts

bitboard_masks: src/bitboard_masks.c
	$(CC) $(CFLAGS) src/bitboard_masks.c -o bitboard_masks

clean:
	rm -f bitboard_demo bitwise_operators bitboard_shifts bitboard_masks
