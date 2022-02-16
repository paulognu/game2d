TARGET=aula05
LD=g++
OBJS=main.cpp carro.cpp input.cpp
SFML=$$(pkg-config sfml-all --libs)

all:
	$(LD) -o $(TARGET) $(OBJS) $(SFML)