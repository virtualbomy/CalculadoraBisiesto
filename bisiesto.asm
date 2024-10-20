section .text
global calcularBisiesto

calcularBisiesto:
    mov rax, rdi        ; Mover el año (número) a RAX
    
    ; Verificar si es divisible por 400
    xor rdx, rdx        ; Limpiar rdx para la división
    mov rbx, 400
    div rbx
    cmp rdx, 0
    je .bisiesto        ; Si es divisible por 400, es bisiesto
    
    ; Verificar si es divisible por 100
    mov rax, rdi        ; Restaurar el año original
    xor rdx, rdx
    mov rbx, 100
    div rbx
    cmp rdx, 0
    je .no_bisiesto     ; Si es divisible por 100 (y no por 400), no es bisiesto
    
    ; Verificar si es divisible por 4
    mov rax, rdi        ; Restaurar el año original
    xor rdx, rdx
    mov rbx, 4
    div rbx
    cmp rdx, 0
    je .bisiesto        ; Si es divisible por 4 (y no por 100), es bisiesto
    
.no_bisiesto:
    mov rax, 1          ; Retornar 1 si NO es bisiesto
    ret

.bisiesto:
    mov rax, 0          ; Retornar 0 si ES bisiesto
    ret
