# automata
Written in C++, using SFML for graphics.
This is an experiment for cellular automata. The 
implementation is painfully inefficient, and will probably
devour one of your cores.

There are five different cells: blank, red, green, blue, and purple. 

## Rules
* Any color can eat a blank cell
* A Red cell will eat a green cell
* A Green cell will eat a blue cell
* A Blue cell will eat a red cell
* A Purple cell will eat any cell, and spawn a random color in it's location

## Building
SMFL is required for building. Once that's installed, this can be
built by typing `make` for a regular build, or `make debug` for a
debug build.
