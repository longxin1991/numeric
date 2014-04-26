#include <stdio.h>
#include "lapacke.h"
int main (int argc,char *argv[])
{	

	lapack_int info,n=3,nrhs=3,ldb=3,lda=3;
	lapack_int ipiv[3];
	float a[9]={8,-3,2,4,11,-1,6,3,12};
	float b[3]={20,33,26};

	info = LAPACKE_sgesv(LAPACK_ROW_MAJOR,n,nrhs,a,lda,ipiv,b,ldb);

	printf("result:%.0f %.0f %.0f\n",b[0],b[1],b[2]);

	return 0;
}
