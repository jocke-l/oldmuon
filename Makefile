CC = gcc
LIBS = -lglfw -lGL -lGLU -lX11 -lXrandr

SOURCE = main.c timer.c

default:
	$(CC) -Wall -o muon $(SOURCE) $(LIBS)

