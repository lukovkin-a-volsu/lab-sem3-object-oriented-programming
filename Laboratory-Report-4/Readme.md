# Компиляция

g++ -c Libs/Date.cpp -o Objects/Date.o && g++ -c Libs/Record.cpp -o Objects/Record.o && g++ -c Libs/RecordsTable.cpp -o Objects/RecordsTable.o && g++ -c Main.cpp -o Objects/Main.o && g++ Objects/Date.o Objects/Record.o Objects/RecordsTable.o Objects/Main.o

# Интересненько

Примечание: Обратите внимание, что метод clear() не освобождает память, выделенную под вектор. Он только удаляет все элементы из вектора, но емкость вектора остается неизменной. Если вам нужно освободить память, выделенную под вектор, используйте метод swap().