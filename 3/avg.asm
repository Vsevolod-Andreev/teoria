%macro pushd 0
    push edx
    push ecx
    push ebx
    push eax
%endmacro

%macro popd 0
    pop eax
    pop ebx
    pop ecx
    pop edx
%endmacro

%macro print 2
    pushd
    mov     edx, %1
    mov     ecx, %2
    mov     ebx, 1
    mov     eax, 4
    int     0x80
    popd
%endmacro

%macro dprint 0
    pushd
    mov     bx, 0
    mov     ecx, 10
    
    %%_divide:
        mov     edx, 0
        div     ecx
        push    edx
        inc     bx
        test    eax, eax
        jnz     %%_divide
        
    %%_convert:
        pop     eax
        add     eax, '0'
        mov     [count], eax
        print   1, count
        dec     bx
        cmp     bx, 0
        jg      %%_convert
    popd
%endmacro

%macro mean 2
    pushd
    mov     al, %1
    mov     bl, 4
    mul     bl
    mov     edx, 0
    mov     ecx, %2
    div     ecx
    mov     [number], eax
    popd
%endmacro

section .text

global _start

_start:

    mov     ebx, 0
    mov     al, 0
    
_sum:
    add     al, [array1 + ebx]
    add     cl, [array2 + ebx]
    add     ebx, 4
    cmp     ebx, arraylen
    jl      _sum

    mean    al, arraylen
    mov     bl, [number]
    mov     [count], bl
    mean    cl, arraylen
    mov     bl, [number]
    sub     [count], bl
    mov     bl, [count]
    cmp     bl, al
    jg      _finish
    
_ifminus:
    mov     al, [count]
    neg     al
    mov     [count], al
    print   minuslen, minus

_finish:
    mov     al, [count]
    dprint
    print   nlen, newline
    print   len,message
    print   nlen, newline
    mov     eax, 1
    int     0x80
    
section .data
    array1      dd 5, 3, 2, 6, 1, 7, 4
    arraylen    equ $ -array1
    array2      dd 0, 10, 1, 9, 2, 8, 5
    number      dd 0
    count       dd 0
    minus       db "-"
    minuslen    equ $ -minus
    message     db "Done"
    len         equ $ -message
    newline     db 0xA, 0xD
    nlen        equ $ -newline