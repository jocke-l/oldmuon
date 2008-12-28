CC = gcc
LIBS = -lSDl -lSDL_image

SOURCE = main.c timer.c

default:
	$(CC) -o muon $(SOURCE) $(LIBS)