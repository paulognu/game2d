TARGET=ryu
LD=g++
SFML=$$(pkg-config sfml-all --libs)
OBJS=main.cpp project.cpp

all:
	$(LD) -o $(TARGET) $(OBJS) $(SFML)

run:
	$(LD) -o $(TARGET) $(OBJS) $(SFML) && ./$(TARGET)	