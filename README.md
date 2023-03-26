# vcb-riscv

Virtual Circuit Board (VCB) RISC-V CPU.

## Virtual Circuit Board

This project is for use with Virtual Circuit Board (vcb).

Buy it on Steam: https://store.steampowered.com/app/1885690/Virtual_Circuit_Board/

## Components

There is a VCB file for various common components - `components.vcb`.

It includes labels for everything and should be relatively straight-forward to understand.

## CPU

There is a VCB file for a RISC-V CPU. (In the future, multiple versions.)

See [CPU-V0_1](CPU-V0_1.md) for more details. 

## Programs

There is a basic setup to compile C code into RISC-V machine code (including .vcbmem files for VCB).

This is all within the `programs` folder with a `Makefile` for easy usage.

### Setup

#### gcc

You need to have a gcc toolchain for RISC-V set up on your system.

There's a bash script for setting up the toolchain on Ubuntu - `programs/setup/ubuntu-riscv-gnu-toolchain.sh`

It uses the [riscv-gnu-toolchain](https://github.com/riscv-collab/riscv-gnu-toolchain) project.
Specifically, the Newlib-based cross-compiler.
Refer to its docs for more details.

### Usage

Using the `Makefile` is simple:
```
cd ./programs
make
```

This will compile the C code in the `src` folder.
Creating a series of files in the `build` folder:
* `.elf` - ELF executable file
* `.elf.d` - RISC-V assembly (from the ELF executable)
* `.s` - RISC-V assembly (from the compiler)
  * This includes comments with C code (that the assembly corresponds to).
  * However, this is missing assembly generated by the loader script.
    View the `.elf.d` file for the exact assembly used for the `.vcbmem`.
* `.vcbmem` - VCB VMEM file
  * This is based on the ELF executable:
    * ELF headers are stripped (to run without a kernel).
    * Using big-endian words for VCB VMEM.

Note: The `Makefile` assumes the C standard library is not used.
Using it should be possible with some tweaks though.

### Code

Currently, there is just a simple `fibonacci.c` example program.

## Contributing

Feel free to open issues and pull requests for improvements :)

## Library

There used to be a VCB circuit library in this repository.
I have put this piece on hold for now.

### Blueprint images

The `vcb_riscv` Python module is for generating images of blueprints.
This uses the [vcbb](https://github.com/chrjen/vcbb) project internally.

(Though the repository makes no use of this for now.)
