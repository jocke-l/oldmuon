CC = gcc
LIBS = -lSDL -lSDL_image

SOURCE = main.c timer.c object.c map.c gfx.c

default:
	$(CC) -Wall -o muon $(SOURCE) $(LIBS)

