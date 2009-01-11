CC = gcc
CFLAGS = -Wall -L/usr/X11R6/lib
LIBS = -lglfw -lGL -lGLU -lX11 -lpthread -lXrandr -lm

SOURCE = main.c timer.c gfx.c map.c object.c player.c camera.c ui.c

default:
	$(CC) $(CFLAGS) -o muon $(SOURCE) $(LIBS)

