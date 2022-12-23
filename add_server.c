#include "add.h"

int * addf_1_svc(numbers *argp, struct svc_req *rqstp) {
	static int  result;

	printf("addf_1_svc is called!\n");
	result = argp->a + argp->b;

	return &result;
}

int * subf_1_svc(numbers *argp, struct svc_req *rqstp) {
	static int  result;

	printf("subf_1_svc is called!\n");
	result = argp->a - argp->b;

	return &result;
}

int * mulf_1_svc(numbers *argp, struct svc_req *rqstp) {
	static int  result;

	printf("mulf_1_svc is called!\n");
	result = argp->a * argp->b;

	return &result;
}

int * divf_1_svc(numbers *argp, struct svc_req *rqstp) {
	static int  result;

	printf("divf_1_svc is called!\n");
	if (argp->b == 0) {
		printf("invalid divider\n");
		return NULL;
	}
	result = argp->a / argp->b;

	return &result;
}
