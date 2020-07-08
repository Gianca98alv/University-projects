.MODEL SMALL
.DATA

;Titulo del programa
TITULO DB 13,10, '                           ษอออออออออออออออออออออออออป  '
       DB 13,10, '                           บ Calculadora Hexadecimal บ  '
       DB 13,10, '                           ศอออออออออออออออออออออออออผ  '
       DB 13,10,13,10,'$'                          

;PARA PODER DESPLEGAR EL MENU EN PANTALLA
MENU DB 13,10,13,10
     DB           '                           ษอออออออออออออออออออออออออป',13,10
     DB           '                           บ     MENU DE OPCIONES    บ',13,10
     DB           '                           ฬอออออออออออออออออออออออออน',13,10
     DB           '                           บ  1.   SUMA              บ',13,10 
     DB           '                           บ  2.   RESTA             บ',13,10
     DB           '                           บ  3.   MULTIPLICACION    บ',13,10
     DB           '                           บ  4.   DIVISION          บ',13,10
     DB           '                           บ  5.   ELEVACION         บ',13,10
     DB           '                           บ  6.   SALIR             บ',13,10
     DB           '                           ศอออออออออออออออออออออออออผ ',13,10
     DB 13,10, '                         OPCION A ELEGIR: $',13,10
 

 ;Recibe los numeros que harรกn la operaciรณn

DNUM1 DB 13,10,'                             Primer valor:  = $' 

DNUM2 DB 13,10,'                             Segundo valor:  = $'

MSGHEXA DB 13,10,'                            Solo se pueden ingresar valores hexadecimales, maximo de dos digitos $'

NMB1 DB ?
NMB2 DB ?

fact1 db ?
fact2 db ?
res DB ?
cen DB ?
res_cen DB ?
uni DB ?
dece DB ?

;---------------Resultados---------------------

MSGRESULT DB 13, 10, '   El resultado es: $' 
RESULTF DB 11 DUP(?) ;Almacena el resultado 

;--------------Variables numerales---------------

NUM1D DB 6,0,6 DUP(?) ;Almacena lo que se digita 
NUM2D DB 6,0,6 DUP(?)

NUM1 DB 0 ;Almacena numeros en binario 
NUM2 DB 0
NUM  DW 0
NUMERO DW 0
NUMERO2 DW 0
POTENCIA DW 0001h, 000Ah, 0064h, 03E8h, 2710h

;------------------------------------------------------------------------
                         ;CODIGO
;------------------------------------------------------------------------

.CODE
INICIO: 
   MOV AH, 0Fh ;Captura de pantalla 
   INT 10h
   MOV AH, 00
   INT 10h
   MOV AX, @DATA
   MOV DS, AX
   MOV SI, OFFSET RESULTF ;Limpia el resultado 
   ADD SI,11
   MOV AL,'$'
   MOV [SI],AL

; --------------------- DESPLIEGA Y MANEJA EL MENU --------------------

MENU1:
   CALL CLRSCR
   MOV DL,0           ;POSICIONA EL CURSOR 
   MOV DH,0
   CALL CURSOR
   MOV DX, OFFSET TITULO ;DESPLIEGA EL TITULO
   MOV Ah,09
   INT 21h
   
   MOV DL,0           ;POSICIONA EL CURSOR
   MOV DH,4H
   CALL CURSOR
   MOV DX, OFFSET MENU  ;DESPLIEGA EL MENU
   MOV Ah,09
   INT 21h
   MOV Ah,0          ;CAPTURA LA TECLA
   INT 16h
   CMP AL,49          ;COMPARA LA TECLA CON 1
   JE SUMA          ;BRINCA A LA FUNCION  SUMA 
   CMP AL,50          ;COMPARA LA TECLA CON 2
   JE RESTA          ;BRINCA A LA FUNCION RESTA
   CMP AL,51         ;COMPARA LA TECLA CON 3
   JE MULTIPLICA ;BRINCA A LA FUNCION MULTIPLICA 
   CMP AL,52         ;COMPARA LA TECLA CON 4
   JE DIVISION         ;BRINCA A LA FUNCION DIVISION 
   CMP AL,53          ;COMPARA LA TECLA CON 5
   JE TERMINAR         ;BRINCA A LA FUNCION TERMINAR 
   
SUMA:
   CALL CAPTURA       ;CAPTURA LOS NUMEROS
   CALL SUMAOP          ;REALIZA LA SUMA E IMPRIME EL RESULTADO
   JMP MENU1          ;BRINCA AL MENU PRINCIPAL

RESTA:
   CALL CAPTURA  ;CAPTURA LOS DATOS
   CALL RESTAOP  ;REALIZA LA RESTA E IMPRIME EL RESULTADO
   JMP MENU1          ;BRINCA AL MENU PRINCIPAL

MULTIPLICA:
   CALL CAPTURA         ;CAPTURA LOS DATOS
   CALL MULTIPLICAOP ;REALIZA LA MULTIPLICACION E IMPRIME RESULTADO
   JMP MENU1         ;BRINCA AL MENU PRINCIPAL

DIVISION:
   CALL CAPTURA         ;CAPTURA LOS DATOS
   CALL DIVISIONOP ;REALIZA LA MULTIPLICACION E IMPRIME RESULTADO
   JMP MENU1         ;BRINCA AL MENU PRINCIPAL

TERMINAR:
   MOV AX, 4C00h ;Se echa el arroz
   INT 21h

; -------------------------------------------------------------------
;                 DESPEJAR PANTALLA
; -------------------------------------------------------------------
CLRSCR PROC NEAR
MOV AX,0600H
MOV BH,011011110B
MOV CX,0000
MOV DX,184FH
INT 10H
RET
CLRSCR ENDP

; -------------------------------------------------------------------
;                 POSICIONA CURSOR
; -------------------------------------------------------------------

CURSOR PROC NEAR     ;POSICIONA EL CURSOR EL LA FILA 0 COLUMNA 0
        MOV BH,0
        MOV AH,2
        INT 10H
        RET
CURSOR ENDP

;------------------------------------------------------------------------
                 ;Captura los numeros
;------------------------------------------------------------------------
CAPTURA PROC NEAR 

    CALL CLRSCR
    MOV DL, 0
    MOV DH, 3 

    MOV DX, OFFSET MSGHEXA; Instruccion
    MOV Ah,09
    INT 21h

    CALL CURSOR 
    MOV DX, OFFSET DNUM1; Recibe el primer valor
    MOV Ah, 09
    INT 21h
    MOV Ah, 0Ah ; Obtiene datos del teclado
    MOV DX, OFFSET NUM1D ; Captura primer valor
    INT 21h
    MOV NUM, 0 ; Primer digito
    CALL CONV1 ;Invoca la funcion 'Convertir'
    MOV NUM1, AL ;Guarda el valor digitado en una variable
    SUB NUM1, 30H
    MOV DL,0 ;Posiciona el cursor
    MOV DH,5


    CALL CURSOR
    MOV DX, OFFSET DNUM2 ; Recibe segundo valor
    MOV Ah, 09
    INT 21h
    MOV AH, 0AH ; Obtiene datos del teclado
    MOV DX, OFFSET NUM2D ; Captura segundo valor
    INT 21h
    MOV NUM, 1 ; Segundo digito
    CALL CONV1 
    MOV NUM2, AL
    SUB NUM2, 30H

    RET

CAPTURA ENDP ;Finaliza la funcion

;------------------------------------------------------------------------
                   ;CONVIERTE UN HEXADECIMAL A DECIMAL
;------------------------------------------------------------------------

CONV1 PROC

    CMP NUM1, 17
    JE cam_A
    CMP NUM1, 18
    JE cam_B
    CMP NUM1, 19
    JE cam_C
    CMP NUM1, 20
    JE cam_D
    CMP NUM1, 21
    JE cam_E
    CMP NUM1, 22
    JE cam_F    

    CMP NUM1, 49
    JE cam_ax
    CMP NUM1, 50
    JE cam_bx
    CMP NUM1, 51
    JE cam_cx
    CMP NUM1, 52
    JE cam_dx
    CMP NUM1, 53
    JE cam_ex
    CMP NUM1, 54
    JE cam_fx

    MOV AL, NUM1
    MOV NMB1, AL
    JMP sec_num

    ; Etiquetas

    cam_A:
    MOV NMB1, 10
    JMP sec_num
    cam_B:
    MOV NMB1, 11
    JMP sec_num
    cam_C:
    MOV NMB1, 12
    JMP sec_num
    cam_D:
    MOV NMB1, 13
    JMP sec_num
    cam_E:
    MOV NMB1, 14
    JMP sec_num
    cam_F:
    MOV NMB1, 15
    JMP sec_num

    cam_ax:
    MOV NMB1, 10
    JMP sec_num
    cam_bx:
    MOV NMB1, 11
    JMP sec_num
    cam_cx:
    MOV NMB1, 12
    JMP sec_num
    cam_dx:
    MOV NMB1, 13
    JMP sec_num
    cam_ex:
    MOV NMB1, 14
    JMP sec_num
    cam_fx:
    MOV NMB1, 15

    ;------------------------2NUMERO----------------------

    sec_num:
    CMP NUM2, 17
    JE cam_A2
    CMP NUM2, 18
    JE cam_B2
    CMP NUM2, 19
    JE cam_C2
    CMP NUM2, 20
    JE cam_D2
    CMP NUM2, 21
    JE cam_E2
    CMP NUM2, 22
    JE cam_F2 

    CMP NUM2, 49
    JE cam_a2x
    CMP NUM2, 50
    JE cam_b2x
    CMP NUM2, 51
    JE cam_c2x
    CMP NUM2, 52
    JE cam_d2x
    CMP NUM2, 53
    JE cam_e2x
    CMP NUM2, 54
    JE cam_f2x

    MOV AL, NUM2
    MOV NMB2, AL
    JMP ope

    ; Etiquetas2

    cam_A2:
    MOV NMB2, 10
    JMP ope
    cam_B2:
    MOV NMB2, 11
    JMP ope
    cam_C2:
    MOV NMB2, 12
    JMP ope
    cam_D2:
    MOV NMB2, 13
    JMP ope
    cam_E2:
    MOV NMB2, 14
    JMP ope
    cam_F2:
    MOV NMB2, 15
    JMP ope

    cam_a2x:
    MOV NMB2, 10
    JMP ope
    cam_b2x:
    MOV NMB2, 11
    JMP ope
    cam_c2x:
    MOV NMB2, 12
    JMP ope
    cam_d2x:
    MOV NMB2, 13
    JMP ope
    cam_e2x:
    MOV NMB2, 14
    JMP ope
    cam_f2x:
    MOV NMB2, 15
    JMP ope

    ope: ; Realiza el cambio
    MOV AL, num2
    MOV BL, 1
    MUL BL
    MOV fact1, AL

    MOV AL, num1
    MOV BL, 16
    MUL BL
    MOV fact2, AL

    MOV AX, 0
    MOV AL, fact1
    ADD AL, fact2
    MOV res, AL

    ; DIVIDE EL NUMERO EN UNIDADES, DECENAS Y CENTENAS

    MOV BL, 0
    MOV AX, 0

    MOV AL, res
    MOV BL, 100
    DIV BL
    MOV cen, AL
    MOV res_cen, AH  

    MOV BL, 0
    MOV AX, 0

    MOV AL, res_cen
    MOV BL, 10
    DIV BL
    MOV dece, AL
    MOV uni, AH


    ; DA ESPACIO PARA EL RESULTADO

    MOV AH, 2
    MOV DL, ' '
    INT 21H  
    
    ; IMPRIME EL RESULTADO

    MOV AH, 2
    MOV AL, cen
    ADD AL, 30H
    MOV cen, AL
    MOV DL, cen
    INT 21H
    
    MOV AH, 2
    MOV AL, dece
    ADD AL, 30H
    MOV dece, AL
    MOV DL, dece
    INT 21H
    
    MOV AH, 2
    MOV AL, uni
    ADD AL, 30H
    MOV uni, AL
    MOV DL, uni
    INT 21H
    
CONV1 ENDP
;------------------------------------------------------------------------
                         ;SUMA
;------------------------------------------------------------------------

SUMAOP PROC NEAR ;PROCEDIMIENTO QUE REALIZA LA SUMA
  XOR DX,DX
  MOV AL,NUM1 ;ALMACENA NUMERO 1
  MOV BL,NUM2 ;ALMACENA NUMERO 2
  ADD AL,BL ;REALIZA LA SUMA
  JNC SUMA1 ;SI NO HAY ACARREO
  ADC DX,0 ;SI HAY ACARREO
SUMA1:
  ;CALL CONVIERTE_ASCII
SUMAOP ENDP ;FINA
  RET
;------------------------------------------------------------------------
                         ;RESTA
;------------------------------------------------------------------------

RESTAOP PROC NEAR ;REALIZA LA RESTAL DE LA SUMA
                              
  XOR DX,DX
  MOV AL,NUM1 ;ALMACENA NUMERO 1
  MOV BL, NUM2 ;ALMACENA NUMERO 2
  SUB AL, BL ;HACE LA REST
  JNC RESTA1 ;SI NO HAY ACARREO
  SBB DX,0 ;SI HAY ACARREOA
RESTA1:
  ;CALL CONVIERTE_ASCII
  RET
RESTAOP ENDP ;FINAL DE LA RESTA
;------------------------------------------------------------------------
                 ;MULTIPLICACION
;------------------------------------------------------------------------
MULTIPLICAOP PROC NEAR;PROCEDIMEINTO QUE MULTIPLICA
  XOR DX,DX
  MOV AL,NUM1
  MOV BL,NUM2
  MUL BX
  ;CALL CONVIERTE_ASCII
  RET
MULTIPLICAOP ENDP

;------------------------------------------------------------------------
                 ;DIVISION
;------------------------------------------------------------------------
DIVISIONOP PROC NEAR ;REALIZA LA DIVISION
  XOR DX,DX
  MOV AL,NUM1
  MOV BL,NUM2
  DIV BX
  ;CALL CONVIERTE_ASCII
  RET
DIVISIONOP ENDP

;------------------------------------------------------------------------
   




.STACK 100H
END INICIO