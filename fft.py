import numpy as np
import scipy as sp

def f(x):
    return x**4-3*x**3+2*x**2-np.tan(x*(x-2))
p=3
#A1=[f(i/4.000) for i in np.arange(8)]
#A2=[f(i/4.000) for i in np.arange(8)]
A1=range(1,9)
A2=range(1,9)
w=[]
t=0+1j
t=-np.pi*t
for m in range(4) :
    b=0+1j
    c=np.e**(2*np.pi/(2**p)*m*b)
    w.append(c)


for q in range(1,4):
    if q%2==1 :
        for k in range(2**(p-q)) :
            for j in range(2**(q-1)):
                A2[k*2**q+j]=A1[k*2**(q-1)+j]+A1[k*2**(q-1)+j+2**(p-1)]
                A2[k*2**q+j+2**(q-1)]=(A1[k*2**(q-1)+j]-A1[k*2**(q-1)+j+2**(p-1)])*w[k*2**(q-1)]
    else :
        for k in range(2**(p-q)) :
            for j in range(2**(q-1)) :
                A1[k*2**q+j]=A2[k*2**(q-1)+j]+A2[k*2**(q-1)+j+2**(p-1)]
                A1[k*2**q+j+2**(q-1)]=(A2[k*2**(q-1)+j]-A2[k*2**(q-1)+j+2**(p-1)])*w[k*2**(q-1)]

if p%2==0 :
    for i in range(8) :
        A2[i]=A1[i]

c=[1.0/4*A2[i]*np.e**(t*i) for i in range(5)]
c[0]=c[0]/2
a=[c[i].real for i in range(5)]
b=[c[i].imag for i in range(5)]




