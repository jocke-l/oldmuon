#include <stdio.h>

int main(int argc, char **argv) {
	int i, j;
	char c, d, e, f, g;
	if (argc != 2) {
		return -1;
	}
	
	FILE *filep;
	if ((filep = fopen(argv[1], "w+")) == NULL) {
		printf("File could not be opened for write+trunc!\n");
		return -1;
	}
	
	
	while (i != 1) {
		printf("Enter type to add: ");
		scanf("%c", &c);
		if (c != 'Q') {
			printf("X: ");
			scanf("%i", &i);
			printf("Y: ");
			scanf("%i", &j);
			putc(c, filep);
			d = i & 0xFF;
			putc(d, filep);
			i = i & 0xFF00;
			e = i / 0x100;
			putc(e, filep);
			f = j & 0xFF;
			putc(f, filep);
			j = j & 0xFF00;
			g = j / 0x100;
			putc(g, filep);
			scanf("%c", &c);
		} else {
			i = 1;
		}
	}
	c = 0xFF;
	putc(c, filep);
	fclose(filep);
	return 0;
}
