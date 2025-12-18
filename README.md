# Simple C Compiler

> This is a modular compiler designed for educational purposes.

**Folder Structure**
```

├── bin/                 
├── src/                 
│   ├── lexer.c          
│   ├── parser.c          
│   ├── codegen.c        
│   └── main.c          
├── include/             
│   ├── lexer.h           
│   └── parser.h 
    └── codegen.h        
├── tests/               
│   └── input.txt
├── Makefile             
└── README.md           
```


**How to Compile**

- Run the makefile:

        make


**How to Run**

- Pass the input file as an argument:

        ./bin/compiler tests/input.txt


**Output**

> The compiler will print "Assembly-like" instructions to the console.