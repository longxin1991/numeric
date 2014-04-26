void lu_d(int n,float *a,float *b)
{
	int i,j,k;
	float t1=0,t2=0;
	float y[n];
	for(i=1;i<n;i++)
	{
		a[i*n]=a[i*n]/a[0];
	}
	/* LU decomposition */
	for(i=1;i<n;i++)
		for(j=i;j<n;j++)
		{
			for(k=0;k<i;k++)
			{
				t1 += a[i*n+k]*a[k*n+j];
				t2 += a[(j+1)*n+k]*a[k*n+i];
			}
			a[i*n+j]=a[i*n+j]-t1;
			a[(j+1)*n+i]=(a[(j+1)*n+i]-t2)/a[i*n+i];
			t1=0.0;
			t2=0.0;
		}
	t1=0.0;
	t2=0.0;

	/* calculate y */
	for(i=1;i<n;i++)
	{
		for(k=0;k<i;k++)
			t1 += a[i*n+k]*b[k];
		b[i] = b[i] - t1;
		t1 = 0.0;
	}
	/* calculate x*/
	b[n-1] = b[n-1]/a[n*n-1];
	for(i=n-2;i>=0;i--)
	{
		for(k=i+1;k<n;k++)
			t2 += a[i*n+k]*b[k];
		b[i] = (b[i] - t2)/a[i*n+i];
		t2 = 0.0;
	}
}

void tridiagonal_solver(int n,float *a,float *b,float *c,float *x)
{
	int i;
	float beta[n-1];
	beta[0]=c[0]/b[0];

	/* calculate beta,from beta[0] to beta[n-1] */
	for(i=1;i<n-1;i++)
		beta[i] = c[i]/(b[i] - a[i-1]*beta[i-1]);

	x[0]=x[0]/b[0];

	/* calculate y */
	for(i=1;i<n;i++)
		x[i] = (x[i] - a[i-1]*x[i-1])/(b[i]-a[i-1]*beta[i-1]);
	/* calculate x */
	for(i=n-2;i>=0;i--)
		x[i] = x[i] - beta[i]*x[i+1];

}
