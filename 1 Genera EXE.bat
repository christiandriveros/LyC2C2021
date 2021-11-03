bison -dyv Sintactico.y
flex Lexico.l
gcc.exe lex.yy.c y.tab.c -o Tercera.exe