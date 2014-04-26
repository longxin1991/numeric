#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <complex.h>
#include <math.h>
#include <time.h>
#define PI 3.141592653
#define N 32768
void dft(int n,float data[],complex out[])
{
	int r=0,k=0;
	float w=2.0*PI/n;
	for (r=0;r<n;r++)
	{
		for (k=0;k<n;k++)
			out[r] += cexp(-r*k*w*I)*data[k];
	}
}
void idft(int n,complex data[],complex out[])
{
	int k=0,r=0;
	float w=2.0*PI/n;
	for (k=0;k<n;k++)
	{
		for (r=0;r<n;r++)
			out[k] += cexp(r*k*w*I)*data[r]/n;
	}
}

void fft(int n,float data[],complex out[])
{
	complex A1[n],A2[n],w[n/2];
	int p;
	frexp(n,&p);
	p=p-1;
	float W=2.0*PI/n;
	for (int i=0;i<n;i++)
	{
		A1[i]=data[i];
		A2[i]=data[i];
	}
	for (int m=0;m<(n/2);m++)
	{
		w[m] = cexp(-m*W*I);
	}	
	for (int q=1;q<=p;q++)
	{
		if (q%2==1)
		{
			for (int k=0;k<(1<<(p-q));k++)
			{
				for (int j=0;j<(1<<(q-1));j++)
				{
					A2[k*(int)pow(2,q)+j]=A1[k*(int)pow(2,(q-1))+j]+A1[k*(int)pow(2,(q-1))+j+(int)pow(2,(p-1))];
					A2[k*(int)pow(2,q)+j+(int)pow(2,(q-1))]=(A1[k*(int)pow(2,(q-1))+j]-A1[k*(int)pow(2,(q-1))+j+(int)pow(2,(p-1))])*w[k*(int)pow(2,(q-1))];
				}
			}
		}
		else
		{
			for (int k=0;k<(1<<(p-q));k++)
			{
				for (int j=0;j<(1<<(q-1));j++)
				{
					A1[k*(int)pow(2,q)+j]=A2[k*(int)pow(2,(q-1))+j]+A2[k*(int)pow(2,(q-1))+j+(int)pow(2,(p-1))];
					A1[k*(int)pow(2,q)+j+(int)pow(2,(q-1))]=(A2[k*(int)pow(2,(q-1))+j]-A2[k*(int)pow(2,(q-1))+j+(int)pow(2,(p-1))])*w[k*(int)pow(2,(q-1))];
				}
			}
		}
	}
	if (p%2==0)
	{
		for (int i=0;i<n;i++)
			A2[i]=A1[i];
	}

	mempcpy(out,A2,n*16);
}

void ifft(int n,float data[],complex out[])
{

}

void dft2(int n,int m,float in[],complex out[])
{

	for (int t=0;t<n;t++)
		for ( int s=0;s<m;s++)
			for (int k=0;k<n;k++)
				for (int l=0;l<m;l++)
					out[t*m+s] += in[k*m+l]*cexp(-2*PI*(1.0*t*k/n+1.0*s*l/m)*I);

}

void idft2(int m,int n,complex in[],complex out[])
{

}


int main()
{
	float data[3]={3,2,3};
	float in[N];
	int beg[2];
	int end[2];
	complex out[N];
	complex iout[3];
	complex fout[N];
	FILE *fp,*fp1;
	fp = fopen("data.txt","r");
	fp1 = fopen("fftout.txt","w");
	for (int i=0;i<32768;i++)
		fscanf(fp,"%f",&in[i]);
	beg[0] = clock();
	dft(N,in,out);
	end[0] = clock();
	idft(3,out,iout);
	beg[1] = clock();
	fft(N,in,fout);
	end[1] = clock();
	printf("*************dft result******************\n");
	for (int i=0;i<3;i++)
	{
		printf("%.3f,%.3f\n",creal(out[i]),cimag(out[i]));
	}

	printf("*************idft result******************\n");

	for (int i=0;i<3;i++)
		printf("%.3f,%.3f\n",creal(iout[i]),cimag(iout[i]));

	printf("*************fft result******************\n");
	
	for (int i=0;i<N;i++)
		fprintf(fp1,"%.3f,%.3f\n",creal(fout[i]),cimag(fout[i]));
	printf("the fft cost %f sec\n",(end[1]-beg[1])/1000000.0);
	printf("the dft cost %f sec\n",(end[0]-beg[0])/1000000.0);
	fclose(fp);
	fclose(fp1);
	return 0;
}
