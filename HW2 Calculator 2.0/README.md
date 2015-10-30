Build Instructions
------------------

Run CMake on this directory, then run make.  You can use the bin directory as the target if you wish, that is what I have been doing for testing.

Execution Instructions
----------------------

The program's name is *calc* and it evaluates a combination of boolean and integer expressions.  After the program is built you can run it and then enter your expression like so:
````
./calc
(4 + 5 > 3) || false
true
````
My programs run in quiet mode so you can also input like so: 
````
echo "(4 + 5 > 3) || false" | ./calc
true
````

Testing Instructions
--------------------

There is no testing suite for my programs.  To test expressions you can simply run expressions as noted above and verify that you are receiving expected outputs.
