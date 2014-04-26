#include <stdio.h>
#include <stdlib.h>
void gauss(int n,float *in,float b[],float x[]);
int main(int argc,char *argv[]){

	float m,a[3][3]={{8,-3,2},{4,11,-1},{6,3,12}},b[3]={20,33,36},x[3];
	int s,i,j,k;
	int n=3;
	for(k=0;k<2;k++){
	    for(i=k+1;i<3;i++){
				m=a[i][k]/a[k][k];
			for(j=k;j<3;j++){
				a[i][j] =a[i][j] - m*a[k][j];
			}
				b[i] =b[i] - m*b[k];
	    }
	}
	x[2]=b[2]/a[2][2];
	s=0;
	for(k=2;k>=1;k--){
		for(j=k;j<3;j++){
			s+=x[j]*a[k-1][j];
		}
		x[k-1]=(b[k-1]-s)/a[k-1][k-1];
		s=0;
 	}
	gauss(3,a[0],b,x);	
	printf("%.3f,%.3f,%.3f\n",x[0],x[1],x[2]);
	printf("%.3f,%.3f,%.2f,%.2f\n",a[0][0],a[0][1],a[0][2],b[0]);
	printf("%.3f,%.3f,%.2f,%.2f\n",a[1][0],a[1][1],a[1][2],b[1]);
	printf("%.3f,%.3f,%.2f,%.2f\n",a[2][0],a[2][1],a[2][2],b[2]);
	return 0;
}
void gauss(int n,float *in,float b[],float x[]){
	
	int i=0,j=0,s,k;
	float m,o[n][n];

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			o[i][j]=in[n*i+j];

	for(k=0;k<n-1;k++){
		for(i=k+1;i<n;i++){
			m=o[i][k]/o[k][k];

            for(j=k;j<n;j++){
				o[i][j] =o[i][j] - m*o[k][j];
			}
			b[i] =b[i] - m*b[k];
		}
	}

	x[n-1]=b[n-1]/o[n-1][n-1];
	s=0;
	for(k=n-1;k>=1;k--){
        for(j=k;j<n;j++){
            s+=x[j]*o[k-1][j];
		}
		x[k-1]=(b[k-1]-s)/o[k-1][k-1];
		s=0;
	}	
}
