#include "int.h"


float int_rect_1(float a,float b,float (*fun)(float),int n)
{
	float h=(b-a)/n;
	float s=0.0;
	int i=0;
	for(i;i<n;i++)
	{
		s += fun(a+h*i)*h;
	}
	return s;
}

/* trapezoid intergal */
float int_trap_1(float a,float b,float (*fun)(float),int n)
{
	float h=(b-a)/n;
	float s=0;
	int i=0;
	for(i;i<n;i++)
	{
		s += (fun(a+h*i)+fun(a+h*(i+1.0)))*h/2.0;
	}
	return s;
}

/* simpson */
float int_sim_1(float a,float b,float (*fun)(float),int n)
{
	float h=(b-a)/n;
	float s=0;
	int i=0;
	for(i;i<n;i++)
	{
		s += 4*fun(a+(i+0.5)*h) + 2*fun(a+(i+1.0)*h);
	}

	s = (s+fun(a)+fun(b))*h/6;
	return s;
}

/* lonbeger */
float int_lon_1(float a,float b,float (*fun)(float),int n,int m)
{
	float h=b-a;
	float T=(fun(a)+fun(b))*h/2;
	int i=1,j;
	float s=0;
	if(m==0)
	{
	for(i;i<=n;i++)
	{
		for(j=0;j<(1<<(i-1));j++)
		{
			s += fun(a+(j+0.5)*h*pow(0.5,i-1));
		}
		s = s*h*pow(0.5,i);

		T = 0.5*T +s;
		s=0;
	}
	return T;
	}
	else
	{
		T = pow(4,m)/(pow(4,m)-1)*int_lon_1(a,b,fun,n,m-1) - 1/(pow(4,m)-1)*int_lon_1(a,b,fun,n-1,m-1); /* recursion */
		return T;
	}
}

float fun(float x)
{
	return x;
}

float trapezoid(float (*fun)(float x),float a,float b,int n)
{
	float dx;
	int   i;

	float ret;
	
	dx=(b-a)/(n*1.0);
	ret=0.0;
	for (i=1;i<n;i++)
	{
		ret+=fun(a+dx*i);
	}
	ret+=(fun(a)+fun(b))*0.5;
	ret*=dx;

	return ret;
}
