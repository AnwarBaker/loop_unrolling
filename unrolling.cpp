

#include <immintrin.h>  // portable to all x86 compilers
#include <stdio.h>
#include <time.h>

#define DATA float

const int SIZE = 1024;

DATA A[SIZE] ;
DATA B[SIZE] ;


double seconds()
{

  struct timespec now;
  clock_gettime(CLOCK_MONOTONIC, &now);
  return now.tv_sec + now.tv_nsec / 1000000000.0;
}

void initialize_array(DATA a[], int size)
{
	for (int i = 0 ;  i < size ; i++)
	{
		a[i] = rand()%2;
	}
}

void normal(DATA a[],int size) 
{
    for (int i = 0 ; i < size ; i++)
    {
        a[i] = a[i] + 5;
    }
}



int main()
{


	DATA r;
    double x,y,z,w;
	double before,after;

	initialize_array(A,SIZE);
	
	before = seconds();

	normal(A,SIZE);

	after = seconds();

    x = after - before;
	printf("normal Time:%f\n",x);



    return 0;
}