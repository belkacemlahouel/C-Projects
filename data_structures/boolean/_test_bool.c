#include "bool.h"
#include <stdlib.h>
#include <stdio.h>

void bIsWhat(Boolean);

int main(int argc, char** argv) {
	Boolean b;
	
	printf("Hello World!\n");

	bIsWhat(b);
	b = TRUE;
	bIsWhat(b);
	b = FALSE;
	bIsWhat(b);

	printf("Bye World!\n");

	return EXIT_SUCCESS;
}

void bIsWhat(Boolean b) {
	printf("B is ");

	if (b == TRUE)
		printf("TRUE");
	else if (b == FALSE)
		printf("FALSE");
	else
		printf("UNDEFINED");

	printf("\n");
}

