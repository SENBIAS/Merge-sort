#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

//How_Many_Inversions
using namespace std;
long long int inv=0;
int A[1000005];

void Merge (int A[], int p, int q, int r)
{
	long long int i,j,k,n1,n2;
	n1=q-p+1;
	n2=r-q;
	int L[n1+1];
	int R[n2+2];
	for(i=1;i<=n1;i++){
		L[i]=A[p+i-1];
	}
	for(j=1;j<=n2;j++){
		R[j]=A[q+j];
	}
	L[n1+1]=2147483000;
	R[n2+1]=2147483000;
	i=1;
	j=1;
	for(k=p;k<=r;k++){
		if(L[i]<=R[j]){
			A[k]=L[i];
			i++;
		}
		else{
			A[k]=R[j];
			j++;
			inv = inv+n1-i+1;
		}
	}
}
void MergeSort(int A[], int p, int r)
{
	int q;
	if(p < r)
	{
		q = (p + r)>>1;
		MergeSort(A, p, q);
		MergeSort(A, q+1, r);
		Merge (A,p,q,r);
	}
}
