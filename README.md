This is a demonstration for using glibc hooks for malloc et al.

Build simply by running ```./make.sh```
Run ```./a.out```

Notice how we can inject our own hooks to "intrument" the glibc's malloc.

This glibc-only solution. There are alternatives for other platforms including LD_PRELOAD trick and others.

This example is essentially based on in Linux documentations for these facilities.

# What does the test program do:
A simple MyArray class is used and analyzed by intercepting all dynamic memory allocations that it seem to be doing internally.
This is admittedly a toy example but the ```hooks.h``` api and its implementation can be included in any C/C++ projects. I have used these succcessfully in figuring out some memory-errors and also gather memory statistics.

# Backtrace
We also have an optional add-on to print backtrace (again, a linux solution). There are some libraries which handle demangling of C++ symbols and so on, and maybe that is the next enhancement to be added to this illustration.

Enjoy!