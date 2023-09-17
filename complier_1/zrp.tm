* TINY Compilation to TM Code
* File: zrp.tm
* Standard prelude:
  0:     LD  6,0(0) 	load maxaddress from location 0
  1:     ST  0,0(0) 	clear location 0
* End of standard prelude.
  2:     IN  0,0,0 	read integer value
  3:     ST  0,0(5) 	read: store value
* -> assign
* -> Const
  4:    LDC  0,1(0) 	load const
* <- Const
  5:     ST  0,1(5) 	assign: store value
* <- assign
* -> assign
* -> Const
  6:    LDC  0,1(0) 	load const
* <- Const
  7:     ST  0,2(5) 	assign: store value
* <- assign
* -> assign
* -> Const
  8:    LDC  0,3(0) 	load const
* <- Const
  9:     ST  0,3(5) 	assign: store value
* <- assign
* -> repeat
* repeat: jump after body comes back here
* -> assign
* -> Op
* -> Id
 10:     LD  0,1(5) 	load id value
* <- Id
 11:     ST  0,0(6) 	op: push left
* -> Id
 12:     LD  0,2(5) 	load id value
* <- Id
 13:     LD  1,0(6) 	op: load left
 14:    ADD  0,1,0 	op +
* <- Op
 15:     ST  0,4(5) 	assign: store value
* <- assign
* -> Id
 16:     LD  0,4(5) 	load id value
* <- Id
 17:    OUT  0,0,0 	write ac
* -> assign
* -> Id
 18:     LD  0,2(5) 	load id value
* <- Id
 19:     ST  0,1(5) 	assign: store value
* <- assign
* -> assign
* -> Id
 20:     LD  0,4(5) 	load id value
* <- Id
 21:     ST  0,2(5) 	assign: store value
* <- assign
* -> assign
* -> Op
* -> Id
 22:     LD  0,3(5) 	load id value
* <- Id
 23:     ST  0,0(6) 	op: push left
* -> Const
 24:    LDC  0,1(0) 	load const
* <- Const
 25:     LD  1,0(6) 	op: load left
 26:    ADD  0,1,0 	op +
* <- Op
 27:     ST  0,3(5) 	assign: store value
* <- assign
* -> Op
* -> Id
 28:     LD  0,3(5) 	load id value
* <- Id
 29:     ST  0,0(6) 	op: push left
* -> Op
* -> Id
 30:     LD  0,0(5) 	load id value
* <- Id
 31:     ST  0,-1(6) 	op: push left
* -> Const
 32:    LDC  0,1(0) 	load const
* <- Const
 33:     LD  1,-1(6) 	op: load left
 34:    ADD  0,1,0 	op +
* <- Op
 35:     LD  1,0(6) 	op: load left
 36:    SUB  0,1,0 	op ==
 37:    JEQ  0,2(7) 	br if true
 38:    LDC  0,0(0) 	false case
 39:    LDA  7,1(7) 	unconditional jmp
 40:    LDC  0,1(0) 	true case
* <- Op
 41:    JEQ  0,-32(7) 	repeat: jmp back to body
* <- repeat
* End of execution.
 42:   HALT  0,0,0 	
