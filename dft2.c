#include <stdio.h>
#include <complex.h>
#define PI 3.141592653


void dft2(int n,int m,float in[],complex out[])
{
	
	for (int t=0;t<n;t++)
		for ( int s=0;s<m;s++)
			for (int k=0;k<n;k++)
				for (int l=0;l<m;l++)
					out[t*m+s] += in[k*m+l]*cexp(-2*PI*(1.0*t*k/n+1.0*s*l/m)*I);

}


void main()
{
	float in[3][3]={1,3,4,3,5,3,2,9,7};
	complex out[3][3];
	dft2(3,3,in[0],out[0]);

}
