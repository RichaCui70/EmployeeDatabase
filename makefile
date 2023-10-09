proFile: mainA3.o helperA3.o recruitEmployee.o printAll.o printOne.o lookOnId.o lookOnFullName.o sortEmployeesId.o countEmployees.o fireAll.o fireOne.o
	gcc -g -Wall -std=c99 mainA3.o helperA3.o recruitEmployee.o printAll.o printOne.o lookOnId.o lookOnFullName.o sortEmployeesId.o countEmployees.o fireAll.o fireOne.o -o bin/proFile
recruitEmployee.o: src/recruitEmployee.c include/headerA3.h
	gcc -g -Wall -std=c99 -c src/recruitEmployee.c
printAll.o: src/printAll.c include/headerA3.h
	gcc -g -Wall -std=c99 -c src/printAll.c 
printOne.o: src/printOne.c include/headerA3.h
	gcc -g -Wall -std=c99 -c src/printOne.c
lookOnId.o: src/lookOnId.c include/headerA3.h
	gcc -g -Wall -std=c99 -c src/lookOnId.c 
lookOnFullName.o: src/lookOnFullName.c include/headerA3.h
	gcc -g -Wall -std=c99 -c src/lookOnFullName.c 
sortEmployeesId.o: src/sortEmployeesId.c include/headerA3.h
	gcc -g -Wall -std=c99 -c src/sortEmployeesId.c 
countEmployees.o: src/countEmployees.c include/headerA3.h
	gcc -g -Wall -std=c99 -c src/countEmployees.c 
fireAll.o: src/fireAll.c include/headerA3.h
	gcc -g -Wall -std=c99 -c src/fireAll.c 
fireOne.o: src/fireOne.c include/headerA3.h
	gcc -g -Wall -std=c99 -c src/fireOne.c 
mainA3.o: src/mainA3.o include/headerA3.h
	gcc -g -Wall -std=c99 -c src/mainA3.c
helperA3.o: src/helperA3.c include/headerA3.h
	gcc -g -Wall -std=c99 -c src/helperA3.c
clean:
	rm *.o bin/proFile