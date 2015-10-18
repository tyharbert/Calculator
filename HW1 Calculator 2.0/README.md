Build Instructions
------------------

Run CMake on this directory, then run make.

Execution Instructions
----------------------

The programs names are *calc* (for evaluating the expression), *calc2sexpr* (for an s-expression) and *calc2post* (for post fix notation).  After the programs are built you can run them with and then enter your expression like so:
````
./calc
4 + 5 - 2
7
````
My programs run in quiet mode so you can also input like so: 
````
echo "4 + 5 - 2" | ./calc
7
````

Testing Instructions
--------------------

There is no testing suite for my programs.  To test expressions you can simply run expressions as noted above and verify that you are receiving expected outputs.
