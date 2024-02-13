Run : Result
	clear && ./program

Result : Date Record TeamRecord IndividualRecord RecordsTable Main
	g++ Objects/Date.o Objects/Record.o Objects/TeamRecord.o Objects/IndividualRecord.o Objects/RecordsTable.o Objects/Main.o -o program

Date : Libs/Date.cpp
	g++ -c Libs/Date.cpp -o Objects/Date.o

Record : Libs/Record.cpp
	g++ -c Libs/Record.cpp -o Objects/Record.o

TeamRecord : Libs/TeamRecord.cpp
	g++ -c Libs/TeamRecord.cpp -o Objects/TeamRecord.o

IndividualRecord : Libs/IndividualRecord.cpp
	g++ -c Libs/IndividualRecord.cpp -o Objects/IndividualRecord.o

RecordsTable : Libs/RecordsTable.cpp
	g++ -c Libs/RecordsTable.cpp -o Objects/RecordsTable.o

Main : Main.cpp
	g++ -c Main.cpp -o Objects/Main.o