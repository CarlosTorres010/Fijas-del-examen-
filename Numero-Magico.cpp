/* Adivinar el numero magico :v  */
#include <iostream>
#include <ctime>
#include<cstdlib> 
using namespace std; 

int main() {
    
    srand(time(0)); 
    int numeroMagico= rand() % 100+1 ; 
	int intento;

	cout<< "Adivina el numero aleatorio: ";
	while(true){
		cin>>intento;
		if(intento>numeroMagico){
			cout<<"Muy alto.Intente otra vez: ";
		} else if (intento < numeroMagico){
			cout<<"Muy bajo. Intente otra vez: ";
		}else {
			cout<<"Execelente has escogido el numero magico: "<<numeroMagico<< endl;
			break;
		}
	}
    return 0;
}
