/*determinante de una matriz
*/
#include<iostream>

using namespace std;

double determinante(double** matriz, int n){
	if(n==1){
		return matriz[0][0];
	}
	if(n==2){
		return matriz[0][0]*matriz[1][1]-matriz[0][1]*matriz[1][0];
	}
	double det= 0;
	double** submatriz = new double*[n-1];
	for(int i=0; i<n-1; i++){
		submatriz[i]= new double[n-1];
	}
	for(int k=0; k<n-1; ++k){
		for(int i=1; i<n-1; ++i){
			int subcolumna=0;
			for (int j=0; j<n-1; ++j){
				if(j!=k){
					submatriz[i-1][subcolumna++]=matriz[i][j];
				}
			}
		}
		double subdeterminante = determinante(submatriz, n-1);
		det += ( k%2==0 ? 1: -1 )* matriz[0][k] * subdeterminante;
	}
	for (int i=0; i<n-1; ++i){
		delete[] submatriz[i];
	}	
	delete[] submatriz; 
	return det;
}

int main(){
	int n;
	cout<<"Ingrese el tamanio de la matriz: ";
	cin>>n;
	
	double**matriz= new double*[n];
	for(int i=0; i<n; i++){
		matriz[i]= new double[n];
	}
	cout<<"Ingrese los elementos de la matriz: ";
	cout<<" \t";
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin>> matriz[i][j];
		}
	}
	double det= determinante(matriz, n);
	cout<< "El determinante de la matriz es: "<< det<< endl;
	
	for( int i=0; i<n; ++i){
		delete[] matriz[i];
	}
	delete[] matriz;
	
	
	return 0;
}
