all: main.cpp 
	g++ main.cpp -o ./dist/main.exe -std=c++11

clean: 
	$(RM) ./dist/main.exe

run: 
	./dist/main.exe
