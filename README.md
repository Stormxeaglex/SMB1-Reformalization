#SMB1-Reformalization

This project aims to Reformalize the Super Mario Bros Disassembly into C code that maintains formal parity with the logic of the assembly code
while also being theoretically compilable in a C compiler by meeting the C standard.

This project is an attempt to realize an idea I had: What if you could create C code that represented in its form and structure the original fine logic of the assembly code such that it could theoretically be compiled for the original platform? I am not sure where C compilers are at with the 6502 (or other asm systems like the snes 65c816) but this project makes quirks of the 6502 architecture such as carry flags, and register usage as explicit as possible. This should provide in theory the ability to compile this C source as a modern C program. I am using Super Mario Bros for the NES as the
perfect test to see if this idea can be realized in practice. 

I may need to inline asm depending on how good 6502 compilers are. The C code will be posted along side relevant asm code so this should be easy to do.