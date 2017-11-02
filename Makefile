all: main.cpp 
	g++ main.cpp -o ./dist/main.exe

clean: 
	$(RM) ./dist/main.exe

run: 
	./dist/main.exe