# Reverse Polish Calculator
## v1.0.2

RepoCalc is an RPN calculator inspired by the [Suckless Philosophy](https://suckless.org/philosophy) that uses an ncurses UI. 

## Installation
### Arch Linux
RepoCalc is available in the [AUR](https://aur.archlinux.org/packages/repocalc/)

### From Source

RepoCalc *should* build on any \*nix system that has a c compiler, a standard library, ncurses, pkg-config, and make. If
it fails to build or run on your system, please report the issue on the [Issues](https://github.com/drdonahue/repocalc/issues) page
so it can be fixed. I hope to achieve a fair degree of platform-independence, so I will try and fix compatibility issues as they arise.

The basic installation process:

```bash
git clone https://github.com/drdonahue/repocalc
cd repocalc
make
sudo make install
```
## Configuration

All of the keybindings can be edited in config.h (if it doesn't exist run `make` or `cp config.def.h config.h`).
There are 2 special keybindings that you can change by modifying the define statements: Backspace and Exit.
The bindings for setting precision and changing the display mode are also set with define statements. All other keybindings can
be changed by editing the `Keybind keys[]` initialization list. This is also where new keybindings can be added.

Custom functions can be defined in customfuncs.h and customfuncs.c. They follow this template:
```c 
void <function name> (stk_elem ** stack, double input, unsigned int * cursorpos, const Arg * arg);
```
Once the function is defined, simple add a line to the `keys[]` initialization list in config.h to map it to a key.
Run `make` to build repocalc with your function.

If your function requires a constant argument (ie alter behavior depending on which keypress called it), add a field for it to the
Arg struct in structs.h. You can then set the argument in the `keys[]` initializer list.

## Contributing

If you think that RepoCalc is missing important functionality or want to otherwise improve it, feel free to either create an 
[issue](https://github.com/drdonahue/repocalc/issues) with suggestions or create a fork and implement your changes there so they can
be merged in.

