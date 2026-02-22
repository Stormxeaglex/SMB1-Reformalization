#SMB1-Reformalization

This project aims to Reformalize the Super Mario Bros Disassembly into C code that maintains formal parity with the logic of the assembly code
while also being theoretically compilable in a C compiler by meeting the C standard.

This project is an attempt to realize an idea I had: What if you could create C code that represented in its form and structure the original
fine logic of the assembly code such that a custom compiler had all the information it needed to recreate the original binary file on the
original platform, while also having the ability to become compiled as a modern C program. I am using Super Mario Bros for the NES as the
perfect test to see if this idea can be realized in practice. There will probably be a couple of phases with this project and a lot of trial
and error.

The first phase is going to be pre compiler. I will by using a "thought decompiler" in my head to try and figure out what the reformalized
C code should look like such that it is a strong model of the asm logic. This will let me iron out the kinks and metabolize errors until
I reach a point where I feel confident writing a compiler targetting the NES 6502 that can realize my formalizations into proper assembly.
