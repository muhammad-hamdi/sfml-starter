all: compile link copy_resources run

compile:
	g++ -c src/*.cpp -Iinclude

link:
	g++ *.o -o build/game -Llib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

copy_resources:
	cp -r res build

run:
	cd build && ./game

clean:
	rm -rf *.o build/*.o build/game.exe build/res