#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void randData(double *,int,int);

void findColSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,result,N,M); 
	showData(result,1,M);
}

//Write definition of randData(), showData() and findColSum()

void randData(double *data, int N, int M){
	for(int i = 0; i < N*M; i++){
		*(data+i) = (rand()%100/100.00);
	}
}

void showData(double *data, int N, int M){
	for (int i = 0; i < N*M; i++){
		cout << *(data+i) << "\t";
		if(i%M == M-1){
			cout << "\n";
		}
	}
}

void findColSum(const double *data, double *sum, int N, int M){
	for(int i = 0; i < N*M; i++){
		*(sum+(i%M)) += *(data+i);
	}
}