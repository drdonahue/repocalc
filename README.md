# Reverse Polish Calculator
## v0.1.1

RepoCalc is an RPN calculator inspired by the [Suckless Philosophy](https://suckless.org/philosophy) that uses an ncurses UI. It is currently under heavy development, as there are
several functions to add to the core set (see [TODO](TODO.md)), but it is fully usable as-is. 

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
There are 2 special keybindings that you can change by modifying the define statements. The other keybindings can
be changed by editing the `Keybind keys[]` initialization list. This is also where new keybindings can be added.


