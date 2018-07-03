#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#define dmax 20
#define kmax 500
#define epsilon 0.000001
#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288
#endif

double complex q(double complex *z, int n, int j){
  double complex hold = 1;
  for(int i = 0; i < n; i++) if(i != j) hold *= z[j] - z[i];
  return hold;
}

double complex f(double complex *c, double complex *z, int n, int j){
  double complex hold = c[n];
  for(int i = n-1; i >= 0; i--) hold = z[j] * hold + c[i];
  return hold;
}

void dk(double complex *c, double complex *z, double complex *zd, int n){
  for(int k = 1; k <= kmax; k++){
    double zdmax = 0;
    printf("iter: %d\n", k);
    for(int j = 0; j < n; j++)
      printf("z[%d] = %.10f + %.10f i\n", j, creal(z[j]), cimag(z[j]));
    for(int j = 0; j < n; j++){
      zd[j] = -f(c, z, n, j)/q(z, n, j);
      if(cabs(zd[j]) > zdmax) zdmax = cabs(zd[j]);
    }
    for(int j = 0; j < n; j++) z[j] = z[j] + zd[j];
    if(zdmax <= epsilon) break;
  }
}

void init(double complex *z, int n, double R){
  for(int j = 0; j < n; j++)
    z[j] = (cos(j*((2*M_PI)/n)) + I*sin(j*((2*M_PI)/n)))*R;
}

double radius(double complex *c, int n){
  double hold = 0;
  for(int j = 0; j < n; j++) if(cabs(c[j]) > hold) hold = cabs(c[j]);
  return 1+hold;
}

int scan(double complex *c){
  int i, in1, in2, check;
  for(i = 0; i < dmax; i++){
    check = scanf("%d %d", &in1, &in2);
    if(check != 2) break;
    c[i] = in1 + in2*I;
  }
  c[i] = 1;
  return i;
}

int main(){
  double complex *c = malloc(dmax*sizeof(double complex));
  int n = scan(c);
  double complex *chold = realloc(c, (n+1)*sizeof(double complex));
  if(chold != NULL){c = chold; chold = NULL;}
  else{fprintf(stderr, "memerror\n"); free(c); exit(-1);}
  double complex *z = malloc(n*sizeof(double complex));
  double complex *zd = malloc(n*sizeof(double complex));
  double R = radius(c, n);
  init(z, n, R);
  dk(c, z, zd, n);
  free(c);
  free(z);
  free(zd);
}
