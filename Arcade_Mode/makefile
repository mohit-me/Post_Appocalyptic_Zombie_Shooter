CC=g++

LFLAGS= -lSDL -lSDL_image -lSDL_ttf  -lSDL_mixer

all: AIHandler.o background.o CollisionManager.o control.o credit.o DrawEngine.o Game.o GarbageCollector.o InputEngine.o main.o Map.o menu.o MovableObject.o music.o Projectile.o start.o Text.o util.o WorldObject.o HeadEater.o SpawnHandler.o Zombie.o 
	$(CC) $(LFLAGS) -o Menu  AIHandler.o background.o CollisionManager.o control.o credit.o DrawEngine.o Game.o GarbageCollector.o InputEngine.o main.o Map.o menu.o MovableObject.o music.o Projectile.o start.o Text.o  util.o WorldObject.o HeadEater.o SpawnHandler.o Zombie.o 

AIHandler.o: ./src/AIHandler.cpp ./src/AIHandler.h
	$(CC) -c ./src/AIHandler.cpp

background.o: ./src/background.cpp ./src/background.h
	$(CC) -c ./src/background.cpp

CollisionManager.o: ./src/CollisionManager.cpp ./src/CollisionManager.h
	$(CC) -c ./src/CollisionManager.cpp

control.o: ./src/control.cpp ./src/simple.h
	$(CC) -c ./src/control.cpp

credit.o: ./src/credit.cpp ./src/simple.h
	$(CC) -c ./src/credit.cpp

DrawEngine.o: ./src/DrawEngine.cpp ./src/DrawEngine.h
	$(CC) -c ./src/DrawEngine.cpp

Game.o: ./src/Game.cpp ./src/Game.h
	$(CC) -c ./src/Game.cpp

GarbageCollector.o: ./src/GarbageCollector.cpp ./src/GarbageCollector.h
	$(CC) -c ./src/GarbageCollector.cpp

InputEngine.o: ./src/InputEngine.cpp ./src/InputEngine.h
	$(CC) -c ./src/InputEngine.cpp 

Map.o: ./src/Map.cpp ./src/Map.h
	$(CC) -c ./src/Map.cpp

menu.o: ./src/menu.cpp ./src/menu.h
	$(CC) -c ./src/menu.cpp

music.o: ./src/music.cpp ./src/music.h
	$(CC) -c ./src/music.cpp

main.o: ./src/main.cpp 
	$(CC) -c ./src/main.cpp

MovableObject.o: ./src/MovableObject.cpp ./src/MovableObject.h
	$(CC) -c ./src/MovableObject.cpp

Projectile.o: ./src/Projectile.cpp ./src/Projectile.h
	$(CC) -c ./src/Projectile.cpp


start.o: ./src/start.cpp ./src/simple.h
	$(CC) -c ./src/start.cpp

Text.o: ./src/Text.cpp ./src/Text.h
	$(CC) -c ./src/Text.cpp

Timer.o: ./src/Timer.cpp ./src/Timer.h
	$(CC) -c ./src/Timer.cpp

WorldObject.o: ./src/WorldObject.cpp ./src/WorldObject.h
	$(CC) -c ./src/WorldObject.cpp

HeadEater.o: ./src/enemies/HeadEater.cpp ./src/enemies/HeadEater.h
	$(CC) -c ./src/enemies/HeadEater.cpp

SpawnHandler.o: ./src/enemies/SpawnHandler.cpp ./src/enemies/SpawnHandler.h
	$(CC) -c ./src/enemies/SpawnHandler.cpp 

Zombie.o: ./src/enemies/Zombie.cpp ./src/enemies/Zombie.h
	$(CC) -c ./src/enemies/Zombie.cpp

util.o: ./src/util.cpp ./src/config.h
	$(CC) -c ./src/util.cpp

clean:
	rm -rf *.o *.gch 
