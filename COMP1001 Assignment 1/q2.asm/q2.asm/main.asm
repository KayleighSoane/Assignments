; A simple template for assembly programs.
.386  ; Specify instruction set
.model flat, stdcall  ; Flat memory model, std. calling convention
.stack 4096 ; Reserve stack space
ExitProcess PROTO, dwExitCode: DWORD  ; Exit process prototype


;Tip. You have been taught how to use integer division only. So, implement the division using ‘div’ instruction; assume 
;that the reminder is always zero (we are interested in the quotient only).  
;unsigned int i, B[10], A[10]={3,2,3,1,7,5,0,8,9,2}, C[10]={1,3,2,5,4,6,0,4,5,8}; 
 


;for (i=0; i<10; i++){ 
 ; B[i] = (A[i]*2+1) + (C[i]*3+1) + (A[i]+C[i])/3; 
 ; }   


.data ; data segment
	; define your variables here
Barray BYTE ?,?,?,?,?,?,?,?,?,?		;Barray will hold value of B
Aarray BYTE 3,2,3,1,7,5,0,8,9,2
Carray BYTE 1,3,2,5,4,6,0,4,5,8
Darray BYTE ?,?,?,?,?,?,?,?,?,?		;Darray will have value of A+C
 

.code ; code segment

main PROC ; main procedure
	; write your assembly code here


mov esi, 0
segmenta:
mov ah, 2
mov al, [Aarray + TYPE Aarray*esi]
mul ah
mov ah, 1
add al, ah
mov [Aarray + TYPE Aarray*esi], al		;A now has value of *2, +1
inc esi
cmp esi, 10								;loop carried out 10 times
jne segmenta							;Aarray = {7,5,7,3,15,11,1,17,19,5}

mov esi, 0
segmentb:
mov ah, 3
mov al, [Carray + TYPE Carray*esi]
mul ah
mov ah, 1
add al, ah
mov [Carray + TYPE Carray*esi], al		;C now has value of *3, +1
inc esi
cmp esi, 10								;loop carried out 10 times
jne segmentb							;Carray = {4,10,7,16,13,19,1,13,16,25}

mov esi, 0
segmentc:
mov ah, [Carray + TYPE Carray*esi]
mov al, [Aarray + TYPE Aarray*esi]
add al, ah
mov [Darray + TYPE Darray*esi], al		;D now has value of A+C
inc esi
cmp esi, 10
jne segmentc							;Darray = {11,15,14,19,28,30,2,30,35,30}

mov esi, 0
segmentd:								;segmentd will calculate Darray/3
mov al, [Darray + TYPE Darray*esi]
mov ax, 3
div ax									;for second loop (esi=1), when eax/ecx, (F div 3), value of eax becomes AAAAAAAF. Does this need to be fixed? How?
mov [Darray + TYPE Darray*esi], al		;Darray now has value of (Aarray+Carray)/3 BUT doeesn't hold decimals - does it need to hold decimals? How?
inc esi									;^^^first value = 11, /3 = 3.233333 
cmp esi, 10								;Darray = {4,5,5,6,9,10,1,10,12,10}
jne segmentd							;now have three arrays, need to add together to make B

mov esi, 0
segmente:
mov al, [Aarray + TYPE Aarray*esi]
mov bl, [Carray + TYPE Carray*esi]
mov ah, [Darray + TYPE Darray*esi]		;get values from each array
add al, bl							
add al, ah							;add them together
mov [Barray + TYPE Barray*esi], al		;Barray now has value of A+C+D
inc esi
cmp esi, 10
jne segmente

INVOKE ExitProcess, 0 ; call exit function
  
main ENDP ; exit main procedure
END main  ; stop assembling