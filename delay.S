; Mason Crim
; Jake Hoke

.text
.global delay1us, delay1ms  ; void delay1us( uint16_t n), void delay1ms( uint16_t n )

; 2 cycle NOP
.macro nop2                 ; 2 cycle, 1 word NOP
        nop                 ; 1 cycle
        nop                 ; 1 cycle
.endm                       ; End


delay1us:                   ; Assume call required (4 cycles)
        nop                 ; (1 cycle)
        nop2                ; (2 cycles)
        rjmp delay2         ; (2 cycles)
delay1:
        nop2                ; (2 cycles)
        nop2                ; (2 cycles)
        nop2                ; (2 cycles)
        nop2                ; (2 cycles)
        nop2                ; (2 cycles)
        nop2                ; (2 cycles)
delay2:
        sbiw r24, 1         ; subtract 1 from r24/r25 (2 cycles)
        brne delay1         ; branch if not zero (1 / 2 cycles)

        ret                 ; return (4 cycles)


delay1ms:                   ; assume called used (4 cycles)
        movw r26, r24       ; save millisecond count (1 cycle)
        rjmp delay4         ; (2 cycles)
delay3:
        nop2                ; (2 cycle)
        nop2                ; (2 cycle)
        nop2                ; (2 cycle)
        nop2                ; (2 cycle)
        nop2                ; (2 cycle)
delay4:
        ldi r24, 231        ; r24/r25 contains 231+3*256 (1 cycle)
        ldi r25, 3          ; = 999us (1 cycle)
        call delay1us       ; delays 999us
        sbiw r26, 1         ; subtract 1 from r26/r27 (2 cycles)
        brne delay3         ; branch if not zero (1 / 2 cycles)

        ret                 ; return (4 cycles)