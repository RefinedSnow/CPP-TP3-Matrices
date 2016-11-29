#include <iostream>
#include <ostream>
#include "Matrice.h"

int main(){
	int l=0, c=0;
	std::cout << std::endl << "Entrer le nombre de lignes de la matrice " << std::endl;
	std::cin >> l;
	std::cout << std::endl << "Entrer le nombre de colonnes de la matrice " << std::endl;
	std::cin >> c;
	Matrice a(l,c);
	//std::cin >> a;
	//std::cout << a;
	return 0;
}