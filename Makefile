all: Objects exec

Objects: login employee admin

login: login.h login.cpp
	g++ -c login.cpp
	
employee: employee.h employee.cpp
	g++ -c employee.cpp

admin: admin.h admin.cpp
	g++ -c admin.cpp

exec: login.h login.cpp employee.h employee.cpp app.cpp
	g++ -o app app.cpp login.o employee.o admin.o

clean:
	rm -f *.o app