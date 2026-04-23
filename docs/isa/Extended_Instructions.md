
Extended Instructions
=====================

There are 3 special instructions to perform operations which require large immediate data. These instructions only perform a single operation.

These are indicated by bit 17 being clear:

+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
| 17 | 16 | 15 | 14 | 13 | 12 | 11 | 10 |  9 |  8 |  7 |  6 |  5 |  4 |  3 |  2 |  1 |  0 |
+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
|  0 |  X |  X |  X |  X |  X |  X |  X |  X |  X |  X |  X |  X |  X |  X |  X |  X |  X |
+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+

Extended ops use the [X.] prefix.





X.PA#n					Push 16-bit immediate onto A-stack. T and N flags of A are affected.

+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
| 17 | 16 | 15 | 14 | 13 | 12 | 11 | 10 |  9 |  8 |  7 |  6 |  5 |  4 |  3 |  2 |  1 |  0 |
+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
|  0 |  0 |  n |  n |  n |  n |  n |  n |  n |  n |  n |  n |  n |  n |  n |  n |  n |  n |
+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+



X.JS#a					Jump to system subroutine at address #a.

+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
| 17 | 16 | 15 | 14 | 13 | 12 | 11 | 10 |  9 |  8 |  7 |  6 |  5 |  4 |  3 |  2 |  1 |  0 |
+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
|  0 |  1 |  a |  a |  a |  a |  a |  a |  a |  a |  a |  a |  a |  a |  a |  a |  a |  0 |
+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+



X.JU#a					Jump to user subroutine at address #a.

+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
| 17 | 16 | 15 | 14 | 13 | 12 | 11 | 10 |  9 |  8 |  7 |  6 |  5 |  4 |  3 |  2 |  1 |  0 |
+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
|  0 |  1 |  a |  a |  a |  a |  a |  a |  a |  a |  a |  a |  a |  a |  a |  a |  a |  1 |
+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+



Note X.JS and X.JU take a 15 bit address in bits 1~15, bit 0 indicates if the jump is to system or user space. 

The return address is pushed onto the R stack, but bit 0 of the R stack is used to indicate which program space the call originated from.

This means subroutines can only start aligned on even word boundaries.

