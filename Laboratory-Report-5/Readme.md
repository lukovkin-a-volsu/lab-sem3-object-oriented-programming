# Compilation

g++ -c Libs/Date.cpp -o Objects/Date.o && g++ -c Libs/Record.cpp -o Objects/Record.o && g++ -c Libs/RecordsTable.cpp -o Objects/RecordsTable.o && g++ -c Main.cpp -o Objects/Main.o && g++ Objects/Date.o Objects/Record.o Objects/RecordsTable.o Objects/Main.o