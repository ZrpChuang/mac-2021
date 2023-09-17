* TINY Compilation to TM Code
* File: SAMPLE.tm
* Standard prelude:
  0:     LD  6,0(0) 	load maxaddress from location 0
  1:     ST  0,0(0) 	clear location 0
* End of standard prelude.
  2:     IN  0,0,0 	read integer value
  3:     ST  0,0(5) 	read: store value
* -> if
* -> Op
* -> Const
  4:    LDC  0,0(0) 	load const
* <- Const
  5:     ST  0,0(6) 	op: push left
* -> Id
  6:     LD  0,0(5) 	load id value
* <- Id
  7:     LD  1,0(6) 	op: load left
  8:    SUB  0,1,0 	op <
  9:    JLT  0,2(7) 	br if true
 10:    LDC  0,0(0) 	false case
 11:    LDA  7,1(7) 	unconditional jmp
 12:    LDC  0,1(0) 	true case
* <- Op
* if: jump to else belongs here
* -> assign
* -> Const
 14:    LDC  0,0(0) 	load const
* <- Const
 15:     ST  0,1(5) 	assign: store value
* <- assign
* -> repeat
* repeat: jump after body comes back here
 16:     IN  0,0,0 	read integer value
 17:     ST  0,2(5) 	read: store value
* -> assign
* -> Op
* -> Id
 18:     LD  0,1(5) 	load id value
* <- Id
 19:     ST  0,0(6) 	op: push left
* -> Id
 20:     LD  0,2(5) 	load id value
* <- Id
 21:     LD  1,0(6) 	op: load left
 22:    ADD  0,1,0 	op +
* <- Op
 23:     ST  0,1(5) 	assign: store value
* <- assign
* -> assign
* -> Op
* -> Id
 24:     LD  0,0(5) 	load id value
* <- Id
 25:     ST  0,0(6) 	op: push left
* -> Const
 26:    LDC  0,1(0) 	load const
* <- Const
 27:     LD  1,0(6) 	op: load left
 28:    SUB  0,1,0 	op -
* <- Op
 29:     ST  0,0(5) 	assign: store value
* <- assign
* -> Op
* -> Id
 30:     LD  0,0(5) 	load id value
* <- Id
 31:     ST  0,0(6) 	op: push left
* -> Const
 32:    LDC  0,0(0) 	load const
* <- Const
 33:     LD  1,0(6) 	op: load left
 34:    SUB  0,1,0 	op ==
 35:    JEQ  0,2(7) 	br if true
 36:    LDC  0,0(0) 	false case
 37:    LDA  7,1(7) 	unconditional jmp
 38:    LDC  0,1(0) 	true case
* <- Op
 39:    JEQ  0,-24(7) 	repeat: jmp back to body
* <- repeat
* -> Id
 40:     LD  0,1(5) 	load id value
* <- Id
 41:    OUT  0,0,0 	write ac
* if: jump to end belongs here
 13:    JEQ  0,29(7) 	if: jmp to else
 42:    LDA  7,0(7) 	jmp to end
* <- if
* End of execution.
 43:   HALT  0,0,0 	
