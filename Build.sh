#!bin/bash 
COMPILER="g++"
MAIN="main.cpp"
OUTPUTFILE="pong"
LINKER="-lSDL2"
# Compling Compile Compile 
$COMPILER $MAIN -o $OUTPUTFILE $LINKER -I./src ./src/pug1.h ./src/pong.h ./src/pug2.h 
# g++ main.cpp -o pong -lSDL2 -I./src ./src/pug1.h ./src/pong.h ./src/pug2.h  
