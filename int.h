#include <math.h>
float int_rect_1(float a,float b,float (*fun)(float),int n);

float int_trap_1(float a,float b,float (*fun)(float),int n);

float int_sim_1(float a,float b,float (*fun)(float),int n);

float int_lon_1(float a,float b,float (*fun)(float),int n,int m);

float fun(float x);
float trapezoid(float (*fun)(float x),float a,float b,int n);
