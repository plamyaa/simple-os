# simple-os

It is an operating system with monolithic arhitecture.
OS has:
- Boot from scratch, without GRUB
- Entering 32-bit mode
- Interrupt handling
- Screen output and keyboard input
- A tiny, basic libc

## Run (mac)

```
git clone https://github.com/plamyaa/simple-os.git
cd simple-os
brew install qemu nasm binutils x86_64-elf-gcc i386-elf-gdb
make run
```

## Sources

https://github.com/cfenollosa/os-tutorial
https://wiki.osdev.org/Expanded_Main_Page
https://web.archive.org/web/20160412174753/http://www.jamesmolloy.co.uk/tutorial_html/index.html
