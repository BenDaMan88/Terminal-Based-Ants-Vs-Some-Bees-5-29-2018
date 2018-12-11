compiler = g++
exe = Assignment_4_exe

$(exe): main.o Ant.o Bee.o Bodyguard.o Fire.o Game.o Harvester.o Insect.o Long_Thrower.o Ninja.o Short_Thrower.o Thrower.o Wall.o
	$(compiler) main.o Ant.o Bee.o Bodyguard.o Fire.o Game.o Harvester.o Insect.o Long_Thrower.o Ninja.o Short_Thrower.o Thrower.o Wall.o -o $(exe)
main.o: main.cpp
	$(compiler) -c main.cpp
Ant.o: Ant.cpp Ant.h
	$(compiler) -c Ant.cpp
Bee.o: Bee.cpp Bee.h
	$(compiler) -c Bee.cpp
Bodyguard.o: Bodyguard.cpp Bodyguard.h
	$(compiler) -c Bodyguard.cpp
Fire.o: Fire.cpp Fire.h
	$(compiler) -c Fire.cpp
Game.o: Game.cpp Game.h
	$(compiler) -c Game.cpp
Harvester.o: Harvester.cpp Harvester.h
	$(compiler) -c Harvester.cpp
Insect.o: Insect.cpp Insect.h
	$(compiler) -c Insect.cpp
Long_Thrower.o: Long_Thrower.cpp Long_Thrower.h
	$(compiler) -c Long_Thrower.cpp
Ninja.o: Ninja.cpp Ninja.h
	$(compiler) -c Ninja.cpp
Short_Thrower.o: Short_Thrower.cpp Short_Thrower.h
	$(compiler) -c Short_Thrower.cpp
Thrower.o: Thrower.cpp Thrower.h
	$(compiler) -c Thrower.cpp
Wall.o: Wall.cpp Wall.h
	$(compiler) -c Wall.cpp
clean:
	rm -f *.o *.out $(exe)
