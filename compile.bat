gcc -c log.c
gcc -c key.c
gcc -c encrypt.c
gcc -c main.c
gcc main.o log.o key.o encrypt.o -o Program
Program.exe

cmd /k
