**This program was made to become more familiar with C, and make something in the process**

> This program uses an alternative data stream to hide an encryption key: 
![commandline](https://github.com/sidhys1/encryption/blob/main/res/alternativeDataStream.png?raw=true)


This program can be compiled using gcc 6.3.0, by running [this batch file](compile.bat) or running the commands below:
```
gcc -c log.c
gcc -c key_gen.c
gcc -c key.c
gcc -c main.c
gcc -c encrypt.c
gcc main.o log.o key_gen.o key.o encrypt.o -o Program
Program.exe
```

## Current status:

- [x] Created a logging system
- [x] Created an unique key, based on the C rand() function, bit-loss, and hardware profiles
- [ ] Create an encryption and decryption algorithm 