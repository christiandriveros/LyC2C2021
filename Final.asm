include macros2.asm
include number.asm

.MODEL LARGE
.386
.STACK 200h

.DATA
@MAXTEXTSIZE equ 31
var1		dd		0.000000
var2		dd		0
svar3		DB		 ?,'$', @MAXTEXTSIZE dup(?)
x		dd		0
y		dd		0
z		dd		0
svar		DB		 ?,'$', @MAXTEXTSIZE dup(?)
var3		dd		0
r		dd		0
@longitud0		dd		0
@aux_asig1		dd		0
@aux_asig2		dd		0.000000
@aux_asig3		dd		0
@aux_asig4		dd		0
@longitud5		dd		0
@aux_asig6		dd		0
@aux_asig7		dd		0
@longitud8		dd		0
@aux_asig9		dd		0
@aux_asig10		dd		0
10		dd		10
100		dd		100
@max11		dd		0
111		dd		111
@aux12		dd		0
@aux13		dd		0
@max14		dd		0
@aux15		dd		0
@max16		dd		0
@aux17		dd		0
@aux18		dd		0
@max19		dd		0
@aux20		dd		0
@max21		dd		0
@max22		dd		0
@exp23		dd		0
@equmax24		DB		 ?,'$', @MAXTEXTSIZE dup(?)
"verdadero"		DB		"verdadero",'$', @MAXTEXTSIZE dup(?)
@aux_asig25		dd		0
@aux_asig26		DB		 ?,'$', @MAXTEXTSIZE dup(?)
@min27		dd		0
@aux28		dd		0
@aux29		dd		0
@max30		dd		0
@aux31		dd		0
@max32		dd		0
@aux33		dd		0
@aux34		dd		0
@max35		dd		0
@aux36		dd		0
@max37		dd		0
@min38		dd		0
@exp39		dd		0
@equmin40		DB		 ?,'$', @MAXTEXTSIZE dup(?)
@aux_asig41		dd		0
@aux_asig42		DB		 ?,'$', @MAXTEXTSIZE dup(?)
"falso"		DB		"falso",'$', @MAXTEXTSIZE dup(?)
@aux_asig43		dd		0
@aux_asig44		DB		 ?,'$', @MAXTEXTSIZE dup(?)
7		dd		7
5		dd		5
0		dd		0
@aux_asig45		dd		0
@aux_asig46		dd		0.000000
30		dd		30
"correcto"		DB		"correcto",'$', @MAXTEXTSIZE dup(?)
@aux_asig47		dd		0
@aux_asig48		DB		 ?,'$', @MAXTEXTSIZE dup(?)
1		dd		1
2		dd		2
3		dd		3
@aux_asig49		dd		0
@aux_asig50		dd		0
4		dd		4
@aux_asig51		dd		0
@aux_asig52		dd		0.000000
@aux_asig53		dd		0
@aux_asig54		dd		0
@aux_asig55		dd		0
@aux_asig56		dd		0.000000
@aux_asig57		dd		0
@aux_asig58		dd		0
@aux_asig59		dd		0
@aux_asig60		dd		0
@aux_asig61		dd		0
@aux_asig62		dd		0.000000
@aux_asig63		dd		0
@aux_asig64		dd		0
@aux_asig65		dd		0
@aux_asig66		dd		0.000000
@aux_asig67		dd		0
@aux_asig68		dd		0.000000
@aux_asig69		dd		0
@aux_asig70		dd		0
@aux_asig71		dd		0
@aux_asig72		dd		0
32767		dd		32767
@aux_asig73		dd		0
@aux_asig74		dd		0.000000
var_numReal1		dd		0.000000
var_numReal2		dd		0.000000
var_numReal3		dd		0.000000
11.11		dd		11.110000
@aux_asig75		dd		0
@aux_asig76		dd		0.000000
09.		dd		9.000000
@aux_asig77		dd		0
@aux_asig78		dd		0.000000
.90		dd		0.900000
@aux_asig79		dd		0
@aux_asig80		dd		0.000000
"ur21v  .3A567@a(-,zjt 1xd%df g"		DB		"ur21v  .3A567@a(-,zjt 1xd%df g",'$', @MAXTEXTSIZE dup(?)
@aux_asig81		dd		0
@aux_asig82		DB		 ?,'$', @MAXTEXTSIZE dup(?)
"ewr"		DB		"ewr",'$', @MAXTEXTSIZE dup(?)
55		dd		55
@aux_asig83		dd		0
@aux_asig84		dd		0.000000
@aux_asig85		dd		0
@aux_asig86		dd		0
@aux_asig87		dd		0
@aux_asig88		dd		0
@aux_asig89		dd		0
8		dd		8
@aux_asig90		dd		0
@aux_asig91		dd		0
@auxAssembler2		dd		0
@auxAssembler1		dd		0
@auxAssembler0		dd		0

.CODE
START:
MOV AX, @DATA
MOV DS, AX
MOV es,ax
FINIT


; REALIZO ASIGNACION:
 mov si, OFFSET @longitud0
 mov di, OFFSET 3
 call copiar

; REALIZO ASIGNACION:
FILD z
 FISTP @aux_asig1

; REALIZO ASIGNACION:
FLD @aux_asig2
 FSTP var1

; REALIZO ASIGNACION:
FILD @aux_asig3
 FISTP var2

; REALIZO ASIGNACION:
FILD @aux_asig4
 FISTP var3

; REALIZO ASIGNACION:
 mov si, OFFSET @longitud5
 mov di, OFFSET 3
 call copiar

; REALIZO ASIGNACION:
FILD z
 FISTP @aux_asig6

; REALIZO ASIGNACION:
FILD @aux_asig7
 FISTP r

; REALIZO ASIGNACION:
 mov si, OFFSET @longitud8
 mov di, OFFSET 3
 call copiar

; REALIZO ASIGNACION:
FILD z
 FISTP @aux_asig9

; REALIZO ASIGNACION:
FILD @aux_asig10
 FISTP r

; REALIZO ASIGNACION:
FILD 100
 FISTP @max11

; REALIZO ASIGNACION:
FILD 111
 FISTP @aux12

FILD @aux13
FILD @max14
fxch 
 fcom
 fstsw ax
 sahf
JNA	@ET_55
; REALIZO ASIGNACION:
FILD @aux15
 FISTP @max16

@ET_55: 
; REALIZO ASIGNACION:
FILD var2
 FISTP @aux17

FILD @aux18
FILD @max19
fxch 
 fcom
 fstsw ax
 sahf
JNA	@ET_66
; REALIZO ASIGNACION:
FILD @aux20
 FISTP @max21

@ET_66: 
FILD @max22
FILD @exp23
fxch 
 fcom
 fstsw ax
 sahf
JNA	@ET_74
; REALIZO ASIGNACION:
 mov si, OFFSET @equmax24
 mov di, OFFSET TRUE
 call copiar

@ET_74: 
; REALIZO ASIGNACION:
 mov si, OFFSET @equmax24
 mov di, OFFSET FALSE
 call copiar

; REALIZO ASIGNACION:
 mov si, OFFSET @aux_asig25
 mov di, OFFSET "verdadero"
 call copiar

; REALIZO ASIGNACION:
 mov si, OFFSET @aux_asig26
 mov di, OFFSET svar3
 call copiar

; REALIZO ASIGNACION:
FILD 100
 FISTP @min27

; REALIZO ASIGNACION:
FILD 111
 FISTP @aux28

FILD @aux29
FILD @max30
fxch 
 fcom
 fstsw ax
 sahf
JNA	@ET_98
; REALIZO ASIGNACION:
FILD @aux31
 FISTP @max32

@ET_98: 
; REALIZO ASIGNACION:
FILD var2
 FISTP @aux33

FILD @aux34
FILD @max35
fxch 
 fcom
 fstsw ax
 sahf
JNA	@ET_109
; REALIZO ASIGNACION:
FILD @aux36
 FISTP @max37

@ET_109: 
FILD @min38
FILD @exp39
fxch 
 fcom
 fstsw ax
 sahf
JAE	@ET_117
; REALIZO ASIGNACION:
 mov si, OFFSET @equmin40
 mov di, OFFSET TRUE
 call copiar

@ET_117: 
; REALIZO ASIGNACION:
 mov si, OFFSET @equmin40
 mov di, OFFSET FALSE
 call copiar

; REALIZO ASIGNACION:
 mov si, OFFSET @aux_asig41
 mov di, OFFSET "verdadero"
 call copiar

; REALIZO ASIGNACION:
 mov si, OFFSET @aux_asig42
 mov di, OFFSET svar3
 call copiar

; REALIZO ASIGNACION:
 mov si, OFFSET @aux_asig43
 mov di, OFFSET "falso"
 call copiar

; REALIZO ASIGNACION:
 mov si, OFFSET @aux_asig44
 mov di, OFFSET svar3
 call copiar

FILD 7
FILD 5
fxch 
 fcom
 fstsw ax
 sahf
JNA	@ET_
; REALIZO ASIGNACION:
FILD 0
 FISTP @aux_asig45

; REALIZO ASIGNACION:
FLD @aux_asig46
 FSTP var1

FILD var2
FILD 30
fxch 
 fcom
 fstsw ax
 sahf
JA	@ET_
; REALIZO ASIGNACION:
 mov si, OFFSET @aux_asig47
 mov di, OFFSET "correcto"
 call copiar

; REALIZO ASIGNACION:
 mov si, OFFSET @aux_asig48
 mov di, OFFSET svar
 call copiar

FILD 1
FILD 2
fxch 
 fcom
 fstsw ax
 sahf
JNA	@ET_
; REALIZO ASIGNACION:
FILD 3
 FISTP @aux_asig49

; REALIZO ASIGNACION:
FILD @aux_asig50
 FISTP var2

FILD 1
FILD 2
fxch 
 fcom
 fstsw ax
 sahf
JNA	@ET_177
; REALIZO ASIGNACION:
FILD 4
 FISTP @aux_asig51

; REALIZO ASIGNACION:
FLD @aux_asig52
 FSTP var1

JMP @ET_183
@ET_177: 
; REALIZO ASIGNACION:
FILD 5
 FISTP @aux_asig53

; REALIZO ASIGNACION:
FILD @aux_asig54
 FISTP var2

@ET_183: 
FILD var2
FILD var2
fxch 
 fcom
 fstsw ax
 sahf
JA	@ET_
; REALIZO ASIGNACION:
FILD 4
 FISTP @aux_asig55

; REALIZO ASIGNACION:
FLD @aux_asig56
 FSTP var1

FILD x
FILD y
fxch 
 fcom
 fstsw ax
 sahf
JNE	@ET_
; REALIZO ASIGNACION:
FILD 3
 FISTP @aux_asig57

; REALIZO ASIGNACION:
FILD @aux_asig58
 FISTP var2

FILD y
FILD z
fxch 
 fcom
 fstsw ax
 sahf
JAE	@ET_
; REALIZO ASIGNACION:
FILD 3
 FISTP @aux_asig59

; REALIZO ASIGNACION:
FILD @aux_asig60
 FISTP var2

FILD var2
FILD z
fxch 
 fcom
 fstsw ax
 sahf
JNA	@ET_
; REALIZO ASIGNACION:
FILD 1
 FISTP @aux_asig61

; REALIZO ASIGNACION:
FLD @aux_asig62
 FSTP var1

FILD x
FILD var2
fxch 
 fcom
 fstsw ax
 sahf
JB	@ET_
; REALIZO ASIGNACION:
FILD 2
 FISTP @aux_asig63

; REALIZO ASIGNACION:
FILD @aux_asig64
 FISTP var2

FILD y
FILD var2
fxch 
 fcom
 fstsw ax
 sahf
JE	@ET_
; REALIZO ASIGNACION:
FILD 5
 FISTP @aux_asig65

; REALIZO ASIGNACION:
FLD @aux_asig66
 FSTP var1

FILD y
FILD var2
fxch 
 fcom
 fstsw ax
 sahf
JNA	@ET_
FILD var3
FILD r
fxch 
 fcom
 fstsw ax
 sahf
JAE	@ET_
; REALIZO ASIGNACION:
FILD 1
 FISTP @aux_asig67

; REALIZO ASIGNACION:
FLD @aux_asig68
 FSTP var1

FILD z
FILD var2
fxch 
 fcom
 fstsw ax
 sahf
JNA	@ET_272
JMP @ET_277
@ET_272: 
FILD var3
FILD r
fxch 
 fcom
 fstsw ax
 sahf
JAE	@ET_
@ET_277: 
; REALIZO ASIGNACION:
FILD 2
 FISTP @aux_asig69

; REALIZO ASIGNACION:
FILD @aux_asig70
 FISTP r

FILD z
FILD var2
fxch 
 fcom
 fstsw ax
 sahf
JA	@ET_
; REALIZO ASIGNACION:
FILD 3
 FISTP @aux_asig71

; REALIZO ASIGNACION:
FILD @aux_asig72
 FISTP r

; REALIZO ASIGNACION:
FILD 32767
 FISTP @aux_asig73

; REALIZO ASIGNACION:
FLD @aux_asig74
 FSTP var1

; REALIZO ASIGNACION:
FILD 11.11
 FISTP @aux_asig75

; REALIZO ASIGNACION:
FLD @aux_asig76
 FSTP var_numReal1

; REALIZO ASIGNACION:
FILD 09.
 FISTP @aux_asig77

; REALIZO ASIGNACION:
FLD @aux_asig78
 FSTP var_numReal2

; REALIZO ASIGNACION:
FILD .90
 FISTP @aux_asig79

; REALIZO ASIGNACION:
FLD @aux_asig80
 FSTP var_numReal3

; REALIZO ASIGNACION:
 mov si, OFFSET @aux_asig81
 mov di, OFFSET "ur21v  .3A567@a(-,zjt 1xd54f g"
 call copiar

; REALIZO ASIGNACION:
 mov si, OFFSET @aux_asig82
 mov di, OFFSET svar3
 call copiar

;Mostrar valor string:
 displayString "ewr"
 newLine 

;Mostrar valor flotante:
DisplayFloat var1 ,2
 newLine 

;Leer un valor flotante:
 getFloat var1
 newLine

;Operacion Matematica
FILD 10
FILD 55
FMUL
FISTP @auxAssembler0

;Operacion Matematica
FILD @auxAssembler0
FILD 2
FADD
FISTP @auxAssembler1

; REALIZO ASIGNACION:
FILD @auxAssembler1
 FISTP @aux_asig83

; REALIZO ASIGNACION:
FLD @aux_asig84
 FSTP var1

; REALIZO ASIGNACION:
FILD @aux_asig85
 FISTP var2

; REALIZO ASIGNACION:
FILD @aux_asig86
 FISTP r

; REALIZO ASIGNACION:
FILD @aux_asig87
 FISTP var3

FILD var2
FILD z
fxch 
 fcom
 fstsw ax
 sahf
JNA	@ET_
FILD var2
FILD 1
fxch 
 fcom
 fstsw ax
 sahf
JNA	@ET_
;Operacion Matematica
FILD var3
FILD 2
FSUB
FISTP @auxAssembler2

; REALIZO ASIGNACION:
FILD @auxAssembler2
 FISTP @aux_asig88

; REALIZO ASIGNACION:
FILD @aux_asig89
 FISTP var2

FILD r
FILD 8
fxch 
 fcom
 fstsw ax
 sahf
JNA	@ET_
; REALIZO ASIGNACION:
FILD var1
 FISTP @aux_asig90

; REALIZO ASIGNACION:
FILD @aux_asig91
 FISTP var2

;INSTRUCCIONES QUE FINALIZAN EL PROGRAMA
MOV AX, 4C00h
INT 21h

strlen proc near
	mov bx, 0
	strl01:
	cmp BYTE PTR [si+bx],'$'
	je strend
	inc bx
	jmp strl01
	strend:
	ret
strlen endp

copiar proc near
	call strlen
	cmp bx , @MAXTEXTSIZE
	jle copiarSizeOk
	mov bx , @MAXTEXTSIZE
	copiarSizeOk:
	mov cx , bx
	cld
	rep movsb
	mov al , '$'
	mov byte ptr[di],al
	ret
copiar endp

END START;
