#include <stdio.h>
#include <sys/random.h>
#include <stdlib.h>
#include "../words.h"
#include "../utils.h"

/*add support for making sure getrandom works always with ssize_t or something*/
#define uint unsigned int

int main (int argc, char* argv[]) {
	const uint len1 = sizeof(words) / sizeof(words[0]);
	const uint len2 = sizeof(marks) / sizeof(marks[0]);
	const uint len3 = sizeof(basic) / sizeof(basic[0]);

	uint r1 = 0; /* random value for words */
	uint r2 = 0; /* random value for marks */
	uint r3 = 0; /* random value for basics */

	uint seed = 0; /* seed edited in for loop */
	uint num = 10;

	if (argc == 2) num = atoi(argv[1]);
	if (num < 1) {
		printf("Invalid token count requested.\n");
		return 1;
	}

	if (getFlagVal("--many", argv, argc) > 0) num = -1;

	system("clear");
	for (int i = 0; i < num; i++) {
		getrandom(&seed, sizeof(seed), 0);
		srand(seed);
		r1 = rand() % len1; /* words */
		r2 = rand() % len2; /* marks */
		r3 = rand() % len3; /* basics */

		printf("%s%s %s", (i == 0) ? "" : " " , words[r1], basic[r3]); /* word printing */

		if (rand() % 5 == 0) { /* mark printing */
			printf("%s ", marks[r2]);
		}
	}
	printKernelAuthor();
	system("date +%d.%m.%y");
	return 0;
}
