#include "add.h"

void opprog_1(char *host) {
	CLIENT *clnt;
	int  *result;
	numbers  allfArg;

#ifndef	DEBUG
	clnt = clnt_create (host, OpProg, ADD_VERS, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit(1);
	}
#endif	/* DEBUG */

	while (1) {
		printf("\nPlease type your operation:\n");
		scanf("%s", allfArg.op);
		
		printf("\nNumber 1:\n");
		scanf("%d", &allfArg.a);
		printf("\nNumber 2:\n");
		scanf("%d", &allfArg.b);

		if (!strcmp(allfArg.op, "add")) {
			result = addf_1(&allfArg, clnt);
		} else if (!strcmp(allfArg.op, "sub")) {
			result = subf_1(&allfArg, clnt);
		} else if (!strcmp(allfArg.op, "mul")) {
			result = mulf_1(&allfArg, clnt);
		} else if (!strcmp(allfArg.op, "div")) {
			result = divf_1(&allfArg, clnt);
		} else if (!strcmp(allfArg.op, "exit")) {
			printf("Exiting...\n");
			exit(1);
		
		} else {
			printf("Invalid operation. Type any of above!\n");
			continue;
		}
		
		if (result == NULL) {
			clnt_perror (clnt, "call failed");
		}
		printf("Server responded and the result is: %d\n", *result);
		
	}

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int main (int argc, char *argv[]) {

	//myprint();
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	opprog_1 (host);
exit (0);
}
