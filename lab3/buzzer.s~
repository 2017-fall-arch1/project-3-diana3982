/* this is an attempt at assembly version of the method
 * winner(int counter) in assembly */

	.data
win:	.word 2			;default case 2
	
	.text
cases:	.word case0 //player 1 wins
	.word case1 //player 2 wins
	.word case2 //default
	
winner:	mov &win, r12
	mov cases(r12), r0 	;find case r12

case0:	mov #4000, r12
	call #buzzer_advance_frequency
	brk break

case1:	mov #6000, r12
	call #buzzer_advance_frequency
	brk break

case2:	brk break

brk:
	pop(r0)
