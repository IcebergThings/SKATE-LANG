#include "compiler.hpp"

void loop_parse(char* buf, int length) {

}

/* Ugly temp main */
int main(int argc, char** argv) {
	if (argc < 2) return 1;
	char* filename = argv[1];
	FILE* f = fopen(filename, "rb");

	fseek(f, 0, SEEK_END);
	int size = ftell(f);
	rewind (f);

	char* buf = (char*) malloc(sizeof(char) * size);
	fread(buf, 1, size, f);
	loop_parse(buf, size);

	fclose(f);
	return 0;
}
