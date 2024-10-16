section .data
    numero1 dq 0  ;Reserva espacio para un número (El ingresado por el usuario en C)

section .text
    global calcularBisiesto

calcularBisiesto:
    ;Guarda el número recibido en C en RDI
    mov [numero1], rdi

    ;Valor de result. Solo puede seer 0 (Bisiesto) o 1 (No bisiesto)
    mov rax, 1  ;Devuelve 1 en RAX
    ret
