all: compile link

compile:
	g++ -c main.cpp -I"D:\Dokumenty\libraies\SFML-2.6.1\include" -DSFML_STATIC

link:
	g++ main.o -o main -L"D:\Dokumenty\libraies\SFML-2.6.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main

clean:
	del main.exe main.o

