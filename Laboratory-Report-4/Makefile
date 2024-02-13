Run : Result
	clear && ./program

Result : Date Record RecordsTable Main
	g++ Objects/Date.o Objects/Record.o Objects/RecordsTable.o Objects/Main.o -o program

Date : Libs/Date.cpp
	g++ -c Libs/Date.cpp -o Objects/Date.o

Record : Libs/Record.cpp
	g++ -c Libs/Record.cpp -o Objects/Record.o

RecordsTable : Libs/RecordsTable.cpp
	g++ -c Libs/RecordsTable.cpp -o Objects/RecordsTable.o

Main : Main.cpp
	g++ -c Main.cpp -o Objects/Main.o