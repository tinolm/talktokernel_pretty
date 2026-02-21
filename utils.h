#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/utsname.h>


// Check for a flag val
// return -1 for invalid or missing val
static int getFlagVal(const char *arg, char **args, uint maxArgs) {
	for (int i = 0; i < maxArgs; i++) {
		if ( !strcmp(arg, args[i]) ) {
			if (i < maxArgs-1) return atoi(args[i+1]);
			else return 1;
		}
	}
	return -1;
}

static void printKernelAuthor() {
	struct utsname kernelNameBuffer;
	if (uname(&kernelNameBuffer)) {
		perror("uname");
		exit(EXIT_FAILURE);
	}
	printf("\n\n-- %s, %s\n", kernelNameBuffer.release, kernelNameBuffer.sysname);
}

#endif
