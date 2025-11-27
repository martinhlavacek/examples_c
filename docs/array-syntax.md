# C Array Syntax
Arrays in C are declared by specifying a type, a name, and a fixed size inside square brackets. The declaration:

```c
int choices[3] = {1, 2, 3};
```

creates a contiguous block of three integers that can be read or written using indexes from 0 to 2. You access members with `choices[index]`, so `choices[0]` reads or writes the first element. When the program runs, the compiler reserves memory for the full array at once, and you can initialize it with constants or assign values later in the code.
