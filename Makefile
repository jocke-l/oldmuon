CC = gcc
LIBS = -lglfw -lGL -lGLU -lX11 -lXrandr

SOURCE = main.c timer.c gfx.c map.c object.c player.c camera.c

default:
	$(CC) -Wall -o muon $(SOURCE) $(LIBS)

