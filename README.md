# Reverse Polish Calculator
## v0.2.2

RepoCalc is an RPN calculator inspired by the [Suckless Philosophy](https://suckless.org/philosophy) that uses an ncurses UI. It is currently under heavy development, as there are
a few more features to implemnt (see [TODO](TODO.md)), but it is fully usable as-is. Note that, until release 1.0.0, the interfaces
used for custom functions may change slightly.

# Installation

RepoCalc *should* build on any \*nix system that has a c compiler, a standard library, ncurses, pkg-config, and make. If
it fails to build on your system, please report the issue on the [Issues](https://github.com/drdonahue/repocalc/issues) page
so it can be fixed. I hope to achieve a fair degree of platform-independence, so I will try and fix compatibility issues as they arise.

The basic installation process:

```bash
git clone https://github.com/drdonahue/repocalc
cd repocalc
make
sudo make install
```
# Configuration

All of the keybindings can be edited in config.h (if it doesn't exist run `make` or `cp config.def.h config.h`).
There are 2 special keybindings that you can change by modifying the define statements: Backspace and Exit.
The bindings for setting precision and changing the display mode are also set with define statements. All other keybindings can
be changed by editing the `Keybind keys[]` initialization list. This is also where new keybindings can be added.

Custom functions can be defined in customfuncs.h and customfuncs.c. They follow this template:
```c 
void <function name> (stk_elem ** stack, double input, unsigned int * cursorpos);
```
Once the function is defined, simple add a line to the `keys[]` initialization list in config.h to map it to a key.
Run `make` to build repocalc with your function.




