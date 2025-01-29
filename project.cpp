#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define p 0,01
double MSE (double a , double b ,double *x, double*y , int size){
        double s= 0 ;
		double J;
		for (int i; i<size ; i++){
			s+= a * x[i] + b - y[i];}
		J= s / 2*size;
		return J;
	}
	
double  derivee_a (double a , double b ,double *x, double *y , int size){
		double K=0;
		for (int i=0; i<size ; i++){
			K+=x[i]*(a*x[i]+ b -y[i]);}
		K=K/(float)size;
		return K;
		}
	
double  derivee_b (double a , double b ,double *x, double *y , int size){
		double L=0;
		for (int i=0 ; i<size ; i++){
			L+=(a*x[i]+ b -y[i]);}
		L=L/(float)size;
		return L;
		}
    
void gradient (double *x, double *y, int size, double *tab){
	srand (time(NULL));
	double a =rand();
	double b =rand();
	printf("random number %.4lf\n",a);
	printf("random number %.4lf\n",b);
		double K;
		double L;
		K=derivee_a(a,b,x,y,size);
		L=derivee_b(a,b,x,y,size);
		double q=derivee_a(a,b,x,y,size);
		double m=derivee_b(a,b,x,y,size);
		
		while ((q*K)>0 || (m*L)>0){
			a=a-(p*derivee_a(a,b,x,y,size));
			q=derivee_a(a,b,x,y,size);	
			b=b-(p*derivee_b(a,b,x,y,size));
			m=derivee_b(a,b,x,y,size);}

		tab[0]=a;
		tab[1]=b;
		}
int main ()
{
	int size;
    double* x;
    double* y;
	
	printf("ecrire le nombre des exemples ");
	scanf("%d",&size);
	y=(double*) malloc (size * sizeof (double));
	x=(double*) malloc (size * sizeof(double));
	
	for (int i = 0 ; i<size ; i++){
		printf ("donner x ");
		scanf("%lf",x+i);
		}
	

	for(int i = 0 ; i<size ; i++){
		printf("donner y ");
		scanf("%lf",y+i);
		}
    
    
   
	
	double tab [2];
	gradient(x,y,size,tab);
	printf("best a= %lf\n",tab[0]);
	printf("best b= %lf\n",tab[1]);
	free(x);
	free(y);
	return 0;
}
	
	

		
		
		
		
    	
	     
	
	
	
	
	
	
	
	

	

