# Object code

## Without folder
g++ -c main.cpp Date.cpp Record.cpp

## With folder
g++ -c main.cpp -o Objects/main.o && g++ -c Libs/Date.cpp -o Objects/Date.o && g++ -c Libs/Record.cpp -o Objects/Record.o
# Compile

## Without folder
g++ main.o Date.o Record.o -o a

## With folder
g++ Objects/main.o Objects/Date.o Objects/Record.o -o a

# Run
./a

# All

## Without folder
g++ -c main.cpp Date.cpp Record.cpp && g++ main.o Date.o Record.o -o a && ./a

## With folder
g++ -c main.cpp -o Objects/main.o && g++ -c Libs/Date.cpp -o Objects/Date.o && g++ -c Libs/Record.cpp -o Objects/Record.o && g++ Objects/main.o Objects/Date.o Objects/Record.o -o a

## NO WORDS
g++ Libs/Date.cpp Libs/Record.cpp main.cpp && ./a.out