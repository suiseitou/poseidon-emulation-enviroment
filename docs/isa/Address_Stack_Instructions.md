
Address Stack Instructions
==========================

A limited number of instructions can be performed on the address stack. Opcode field is 5 bits.

Opcode field for address stack instructions is 5 bits, bits 12-16:

+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
| 17 | 16 | 15 | 14 | 13 | 12 | 11 | 10 |  9 |  8 |  7 |  6 |  5 |  4 |  3 |  2 |  1 |  0 |
+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
|  1 |  A |  A |  A |  A |  A |    |    |    |    |    |    |    |    |    |    |    |    |
+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+

There are only 2 flags. All items on the A-stack are treated as unsigned.

T:	set when A is not zero
C:	carry



Load / Store
============

A.P0		+	T			Push zero
A.PD		+	T			Push data
A.PR		+	T			Push return
A.PPC		+	T			Push program counter

A.LD       	0	T			Load D (overwrites)
A.LR		0	T			Load R (overwrites)

[6 codes.]



Arithmetic
==========

A.ADD#n     	+	TC			Add (range 1~4)
A.SUB#n     	+	TC			Subtract (range 1~4)

A.ADD		-	TC
A.ADDK		0	TC
A.ADDD		0	TC
A.ADDR		0	TC

A.SUB		-	TC
A.SUBK		0	TC
A.SUBD		0	TC
A.SUBR		0	TC

A.NEG  		0	TC			Negate
A.SR		0	TC			Logical Shift Right

[18 codes.]



Stack ops
=========     

A.SWAP		0
A.DUP		0
A.DROP		0
A.ROT		0
A.RROT		0
A.NIP		0
A.OVER		0

[7 codes.]



Misc.
=====

A.NOP		0

[1 code.]




[32 codes total.]

