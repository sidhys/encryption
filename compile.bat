gcc -c log.c
gcc -c key_gen.c
gcc -c key.c
gcc -c main.c
gcc main.o log.o key_gen.o key.o -o Program
Program.exe

cmd /k
