
Data Stack Instructions
=======================

All data stack instructions are prefixed with [D.]

Opcode field for data stack instructions is 8 bits, bits 0-7:

+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
| 17 | 16 | 15 | 14 | 13 | 12 | 11 | 10 |  9 |  8 |  7 |  6 |  5 |  4 |  3 |  2 |  1 |  0 |
+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
|  1 |    |    |    |    |    |    |    |    |    |  D |  D |  D |  D |  D |  D |  D |  D |
+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+

Data stack has associated flags:

T	Test: is set when result of test or comparison was true. Also acts as a non-zero flag.
N	Negative: Bit 15 was set.
V	oVerflow: Signed overflow.
C	Carry.
H	Half-word carry: is set when bit 7 generates a carry (useful for graphics).

The top 3 (or 6?) items on the stack are registered for fast and easy stack manipulation.



Immediate field instructions
============================

D.ADD#n		0	TNVCH			Add (2,3,4,8,16,32,64 or 128) (Use D.INC for +1) 
D.SUB#n		0	TNVCH			Sub (2,3,4,8,16,32,64 or 128) (Use D.DEC for -1) 

D.P#n		+	TN			Push n (0~15)
D.PBIT#n	+	TN			Push 2**n (n= 0~15)
D.PB#n		+	TN			Push 4-bit blocks (uses ALU) e.g. D.PB#$F00F or D.PB#$00FF	

[Total 64 codes.]



Shift / bit manips
==================

-- These ops use the shifter. Note D.SL and D.SBLC are ALU ops

D.LSR		0	TNVCH			Logical Shift Right
D.LSRC		0	TNVCH			... with Carry
D.ASR		0	TNVCH			Arithmetic Shift Right, no carry
D.ROL		0	TNVCH			Rotate Left, no carry
D.ROR		0	TNVCH			Rotate Right, no carry
D.BSWAP		0	TN			Swap byte halves
D.BREV		0	TN			Reverse bits within each byte half (for graphics)
D.SBRC		0	TNVCH			Shift bytes right with carries (for graphics)

[Total 8 codes.]



Read / Write
============

D.R		+	TN			Read Data from RAM and push onto D; (A0)->D0
D.RO		0	TN			.. but overwrite D
D.W		-				Write Data to RAM D0->(A0)
D.WK		0				.. but keep D

D.RV		+	TN			Read from video RAM
D.RVO		0	TN
D.WV		-				Write to video RAM
D.WVK		0

[Total 8 codes.]



Push / Load
===========

D.PA		+	TN			Push A
D.PR		+	TN			Push R

D.LA		0	TN			Load A (overwrites)
D.LR		0	TN			Load R

D.RRPR 		+				Read RAM page register (?)
D.WRPR		-				Write RAM page register	(?)

D.RF		+				Read Flags
D.WF		-	TNVCH			Write Flags

[Total 8 codes.]



Monadic ALU
===========

D.CLR		0	TN			Clear TOS
D.SET		0	TN			Set TOS = $FFFF
D.NEG		0	TNVCH			Negate
D.NOT		0	TN			Invert
D.ABS		0	TNVCH			Absolute Value
D.INC		0	TNVCH			Increment (ignores carry flag)
D.DEC		0 	TNVCH			Decrement (ignores carry flag)
D.ADDCF		0 	TNVCH			Add carry flag
D.SUBCF		0	TNVCH			Sub carry flag
D.SLC		0	TNVCH			Shift bytes left thru carries (for graphics)

[Total 16 codes.]



Dyadic arithmetic
=================

D.ADD		-	TNVCH
D.ADDC		-	TNVCH			Add with Carry
D.SUB		-	TNVCH
D.SUBC		-	TNVCH

D.ADDK		0	TNVCH			Keeps NOS, only overwrites TOS
D.ADDKC		0	TNVCH
D.SUBK		0	TNVCH
D.SUBKC		0	TNVCH

D.ADDA		0	TNVCH			Adds A
D.ADDAC		0	TNVCH
D.SUBA		0	TNVCH
D.SUBAC		0	TNVCH

D.ADDR		0	TNVCH			Adds R
D.ADDRC		0	TNVCH
D.SUBR		0	TNVCH
D.SUBRC		0	TNVCH


[Total 16 codes.]



Dyadic logical
==============

D.AND 		-	TN
D.OR		-	TN
D.XOR		-	TN
D.NAND		-	TN
D.NOR		-	TN
D.NXOR		-	TN
D.ANDN		-	TN			TOS.¬NOS
D.ORN		-	TN			TOS+¬NOS

D.ANDK 		0	TN
D.ORK		0	TN
D.XORK		0	TN
D.NANDK		0	TN
D.NORK		0	TN
D.NXORK		0	TN
D.ANDNK		0	TN
D.ORNK		0	TN
	
D.ANDA 		0	TN
D.ORA		0	TN
D.XORA		0	TN
D.NANDA		0	TN
D.NORA		0	TN
D.NXORA		0	TN
D.ANDNA		0	TN
D.ORNA		0	TN

D.ANDR 		0	TN
D.ORR		0	TN
D.XORR		0	TN
D.NANDR		0	TN
D.NORR  	0	TN
D.NXORR		0	TN
D.ANDNR		0	TN
D.ORNR		0	TN

[Total 32 codes.]



Stack manips
============

These mostly match standard Forth words

D.DROP		-
D.SWAP		0
D.ROT		0
D.RROT		0				Reverse ROT

D.DUP		+
D.OVER		+
D.NIP		-

Could have more such as 2SWAP, 2ROT, 2RROT if more stack items are registered (6 instead of 3)

[Total 16 codes.]



Flag ops / Test Conditions
==========================

D.PT		+				If T=1 push -1, if T=0 push 0
D.PNT		+				If T=1 push 0, if T=0 push -1

D.TZ		0	T			T=¬T	
D.TNZ		0				T=T; Does nothing, could be synonymous with D.NOP

D.TMI		0	T			T=N
D.TMIZ		0	T			T=N+¬T
D.TPLZ		0	T			T=¬N
D.TPL		0	T			T=¬N.T
D.TV		0	T			T=V
D.TNV		0	T			T=¬V
		
D.TC		0	T			T=C
D.TNC		0	T			T=¬C
D.TH		0	T			T=H
D.TNH		0	T			T=¬H

D.TT		0	T			T=1
D.TF		0	T			T=0

[Total 16 codes.]



Compares
========

Compare the top 2 items on the stack and set T flag accordingly.

Other flags get set as a side-effect of the underlying SUB (?)

Agnostic
--------

D.CMPNE		0	TNVCH			<>	T=T
D.CMPEQ		0	TNVCH			=	T=¬T

Unsigned
--------

D.CMPUL		0	TNVCH			<	T=¬C
D.CMPULE	0	TNVCH			<=	T=¬C+¬T
D.CMPUGE	0	TNVCH			>=	T=C	
D.CMPUG		0	TNVCH			>	T=C.T

Signed
------
	
D.CMPSL		0	TNVCH			<	T=N^V
D.CMPSLE	0	TNVCH			<=	T=¬T+(N^V)
D.CMPSGE	0	TNVCH			>=	T=¬(N^V)
D.CMPSG		0	TNVCH			>	T=T.¬(N^V)

D.CMPSMI	0	TNVCH			<0	T=N
D.CMPSPLZ	0	TNVCH			>=0	T=¬N

D.CMPSV		0	TNVCH			T=V
D.CMPSNV	0	TNVCH			T=¬V

[Total 16 codes.]



Bit Set
=======

Set a bit in TOS according to 2nd operand

***

D.PBIT		0	TN			
D.PBITA		+	TN
D.PBITR		+	TN
D.PBITK		+	TN

[Total 4 codes.]



Accumulate and Shift
====================

NOS is added to TOS if condition is true. NOS always shifted left regardless of condition. 

D.AS		0	TNVCH			Accumulate and Shift
D.ASAC   	0    	TNVCH			Accumulate and Shift on Address Carry
D.ASC		0	TNVCH			Accumulate and Shift on Carry
D.AST		0	TNVCH			Accumulate and Shift on Test

[Total 4 codes.]



LZC / TZC
=========

D.LZC		0	TN			Leading zero count
D.LZCK		+	TN
D.TZC		0	TN			Trailing zero count
D.TZCK		+	TN

[Total 4 codes.]



Compare and Swap
================

D.CUMAX		0	TNVCH			Compare unsigned and swap on carry. Note flags result from the compare
D.CUMIN		0	TNVCH			Compare unsigned and swap on no carry
D.CSMAX		0	TNVCH			Compare signed and swap if N^V
D.CSMIN		0	TNVCH			Compare signed and swap if ¬(N^V)

[Total 4 codes.]



Misc.
=====

D.NOP		0				No operation 
D.CC		0	CH			Clear carries
D.BYTE		0	TN			Masks lower byte half = [ D.PB#$00FF, D.AND ]

[Total 8 codes.]



Barrel Shifter
==============

Codes reserved for optional barrel shifter

[Total 8 codes.]



ROM ops + reserved codes
========================

[Total ?? codes.]



Page handling
=============

Multiple stack pages to facilitate task-switching

D.RSPR		+	TN			Read stack page register
D.WSPR		-				Write 

Multiple RAM pages for extra RAM

D.RRPR		+	TN			Read RAM page register
D.WRPR		-				Write
D.RVPR		+	TN			Read video page register
D.WVPR		-				Write

[Total 8 codes.]



Stack pointer ops
=================

D.RDSP		+	TN			Read D-stack Pointer
D.WDSP 		-				Write
D.RASP 		+	TN			Read A-stack Pointer
D.WASP 		-				Write
D.RRSP 		+	TN			Read R-stack Pointer
D.WRSP 		-				Write

[Total 8 codes.]


