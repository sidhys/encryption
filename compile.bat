gcc -c main.c
gcc -c log.c
gcc -c UniqueIdentifier.c
gcc log.o main.o UniqueIdentifier.o -o Program
Program.exe

cmd /k
