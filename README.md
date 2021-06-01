# MipsSimulator
A simulator for mips coded by c

```
> MipsSimulator.exe <parameter> <files/number> ...
```

**Parameters:**

* `-t`: The file of .text
* `-ta`: The address of .text
* `-d`: The file of .data
* `-da`: The address of .data
* `-m`: The size of memory
* `-sp`: The address of $sp
* `-gp`: The address of $gp

**Examples:**

```
> MipsSimulator.exe -t fib
```

```
> MipsSimulator.exe -t fact -ta 0x1000
```

```
> MipsSimulator.exe -t Helloworld_text -d Helloworld_data
```

