# Chess-Bitboards
Exploring the foundations of Chess Bitboards
**Introduction**

Chess engines need to efficiently represent chessboard positions and calculate possible moves. One approach is through bitboards, which use 64-bit integers to represent the 64 squares of a chessboard.

In this project, I explored how bitboards work, how bitwise operators manipulate them, and why masks are necessary to prevent invalid movements.

**What I explored**
- Binary representation of chessboard positions.
- Bitwise operators: AND, OR, XOR, and shifts.
- Hexadecimal representation of bit masks.
- Edge wraparound and how masks prevent it.
**Interesting discoveries**

1. Representing an entire chessboard using 64 bits

Each bit corresponds to one square. A 1 indicates that the square belongs to the selected piece group, while a 0 indicates that it does not.

2. Using bitwise operators to calculate moves

Rather than examining individual squares, chess engines can manipulate entire groups of squares through binary operations.

3. Preventing edge wraparound with masks

Computers do not inherently understand chessboard boundaries. Masks selectively remove bits that could otherwise produce invalid movements when shifted.

**Key takeaway**

Bitboards demonstrate how relatively simple binary operations can be combined to efficiently solve complex problems.
