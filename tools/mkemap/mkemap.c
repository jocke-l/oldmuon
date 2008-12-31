#include <stdio.h>

int main(int argc, char **argv) {
	int i;
	char c;
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
			putc(c, filep);
			
			printf("X: ");
			scanf("%i", &i);
			c = i & 0xFF;
			putc(c, filep);
			i = i & 0xFF00;
			c = i / 0x100;
			putc(c, filep);
			
			printf("Y: ");
			scanf("%i", &i);
			
			
			c = i & 0xFF;
			putc(c, filep);
			i = i & 0xFF00;
			c = i / 0x100;
			putc(c, filep);
			
			printf("Attrib: ");
			scanf("%i", &i);
			c = i & 0xFF;
			putc(c, filep);
			
			scanf("%c", &c);
			i = 0;
		} else {
			i = 1;
		}
	}
	fclose(filep);
	return 0;
}
