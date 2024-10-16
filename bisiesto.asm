section .text
global calcularBisiesto

calcularBisiesto:
    mov rax, rdi      ; Mover el año (número) a RAX

.bisiesto:
    mov rax, 0        ; Retornar 0 si es bisiesto
    ret

.no_bisiesto:
    mov rax, 1        ; Retornar 1 si no es bisiesto
    ret

