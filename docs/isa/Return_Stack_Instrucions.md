
Address Stack Instructions
==========================

A minimal set of control instructions can be performed with the return stack. Opcode field is 4 bits.

Opcode field for address stack instructions is 4 bits, bits 8-11:

+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
| 17 | 16 | 15 | 14 | 13 | 12 | 11 | 10 |  9 |  8 |  7 |  6 |  5 |  4 |  3 |  2 |  1 |  0 |
+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
|  1 |    |    |    |    |    |  R |  R |  R |  R |    |    |    |    |    |    |    |    |
+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+



There are 3 system flags affected by R-stack ops:

S:		System flag; set when running in system code space, clear when running user code
I:		Interrupt Enable flag; set when interrupts are enabled
E:		Interrupt flag; set when running interrupt / trap code. Equivalent to supervisor mode.



Ops
===

R.NOP		0

R.EI		0	E			Enable interrupts
R.DI		0	E			Disable interrupts
R.STOP		0				Wait for interrupt

R.DROP		-
R.PA		+				Push A
R.PD		+				Push D

R.TRAP		+	EIS			Similar to R.JSR but sets I and S flags, interrupts disabled.
		
R.JSR		+				Jump to Subroutine at address (A)

R.RET		-				Return from subroutine
R.RETND		0/-				...if D.T flag is false
R.RETNA		0/-				...if A.T flag is false

R.RETI		-	EIS			Return from interrupt and enable interrupts

R.DO		+				Start loop; Push address of next instruction onto stack and continue execution.
R.WHILED	0/-				Loop if D is true; If D.T then jump to address on TOS, else drop TOS and continue.	
R.WHILEA     	0/-				Loop if A is true

[16 codes.]




Code Examples
=============


To do a JMP, push address onto to R stack and return:

\ Jump to (A)

R.JMP :
					R.PA
					R.RET
;


PC arithmetic is done on the A stack.

\ To perform a DUP, note this cannot be a subroutine because it trashes its own stack

R.DUP :
			A.PR
			A.DROP		R.PA

\ Subroutine version.

R.DUP :
			A.PR		R.DROP
			A.PR
			A.DROP		R.PA
			A.DROP		R.PA
					R.RET
;

\ To do a SWAP, NB cannot be a subroutine due to stack coherency issues


R.SWAP :
			A.PR		R.DROP
			A.PR		R.DROP
			A.SWAP
			A.DROP		R.PA
			A.DROP		R.PA
;

\ Subroutine version.

R.SWAP :
			A.PR		R.DROP		\ save return address
			A.PR		R.DROP
			A.PR		R.DROP
			A.SWAP
			A.DROP		R.PA
			A.DROP		R.PA
			A.DROP		R.PA
					R.RET

;


R.TUCKA :						\ tuck A under R
			
			A.PR		R.DROP		\ save return address
			A.PR		R.DROP
			A.ROT
			A.DROP		R.PA
			A.DROP		R.PA
			A.DROP		R.PA
					R.RET			
;













