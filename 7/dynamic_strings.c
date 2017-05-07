/**
 * @file dynamic_strings.c
 * @author Namir Hassan
 * @date 04/05/2017
 * @brief valgrind used to check if memory leak based on this program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "str.h"

#define MALLOC_FAILED 1000

int main(void)
{
	char *s = "c run, c run unix, run unix run";

	char *t = ", go c, go!";

	char *u;

	size_t len = strlen(s) + strlen(t) + 1; /* 1 for the NULL char */

	/* how many objects times the size of the object */
	u = malloc(len * sizeof(char));

	/* malloc may fail so need to check to make sure it worked  */
	if (u == NULL) {
		printf("malloc failed. goodbye...\n");
		exit(MALLOC_FAILED);
	}

        /* the + 1 makes room for the null terminator */
	strncpy(u, s, strlen(s) + 1);
	printf("u = \"%s\"\n", u);

	strcat(u, t);
	printf("u = \"%s\"\n", u);

	free(u);		/* you allocated it you free it */

	return 0;
}
