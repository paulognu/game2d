TARGET=mario
LD=g++
SFML=$$(pkg-config sfml-all --libs)
OBJS=main.cpp TileMap.cpp Mario.cpp Enemy.cpp

all:
	$(LD) -o $(TARGET) $(OBJS) $(SFML)