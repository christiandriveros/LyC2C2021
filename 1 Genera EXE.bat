bison -dyv Sintactico.y
flex Lexico.l
gcc.exe lex.yy.c y.tab.c -o Grupo18.exe