
all: clean librdt server client tests

clean:
	-rm librdt
	-rm librdt.a
	-rm server
	-rm client
	-rm tests

librdt: rdt.cpp
	gcc -lstdc++ -fPIC -c -o librdt rdt.cpp
	ar rcs librdt.a librdt

#build the server
server: server.cpp
	gcc -lstdc++ -o server server.cpp -pthread librdt.a -I/

#build the client
client: client.cpp
	gcc -lstdc++ -o client client.cpp -pthread -lrt -lpthread librdt.a -I/

#build tests
tests: tests.cpp
	gcc -lstdc++ -o tests tests.cpp

#build the "make clear ls make"
clear_ls_make: clear_ls_make.cpp
	gcc -lstdc++ -o clear_ls_make clear_ls_make.cpp
