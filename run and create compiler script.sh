bison -dyv Sintactico.y
flex Lexico.l
gcc.exe lex.yy.c y.tab. -o Primera.exe
Primera.exe prueba.txt