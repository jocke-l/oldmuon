CC = gcc
LIBS = -lSDL -lSDL_image

SOURCE = main.c timer.c object.c dynarr.c map.c

default:
	$(CC) -Wall -o muon $(SOURCE) $(LIBS)

