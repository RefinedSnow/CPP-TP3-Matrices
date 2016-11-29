#include <iostream>
#include <ostream>
#include "Matrice.h"

Matrice::Matrice(){
	nbCol = 0;
	nbLin = 0;
	std::cout << "+++Matrice() @" << this << std::endl;
}

Matrice::Matrice(int nbLin, int nbCol){
	this->nbLin = nbLin;
	this->nbCol = nbCol;
	allocation();
	std::cout << "+++Matrice(" << nbLin <<","<< nbCol << ") @" << this << std::endl;
}

Matrice::Matrice(Matrice & matrice){
	this->nbLin = matrice.nbLin;
	this->nbCol = matrice.nbCol;
	allocation();
	memcpy(mat[0], matrice.mat[0], nbLin * nbCol * sizeof mat[0][0]);
	std::cout << "rrrMatrice(" << nbLin <<","<< nbCol << ") @" << this << std::endl;
}
Matrice::~Matrice(){
	deallocation();
	std::cout << "---Matrice(" << nbLin <<","<< nbCol << ") @" << this << std::endl;
}
int Matrice::nbLin(){
	return nbLin;
}
int Matrice::nbCol(){
	return nbCol;
}

double* Matrice::getLine(){
	//TODO
	return 0;
}
Matrice::Matrice& operator=(const Matrice& matrice){
	//desalouer
	deallocation();
	//realouer
	nbLin = matrice.nbLin;
	nbCol = matrice.nbCol;
	allocation();
	//memcpy
	memcpy(mat[0], matrice.mat[0], nbLin * nbCol * sizeof mat[0][0]);
	std::cout << "affect : Matrice(" << nbLin <<","<< nbCol << ") @" << this << std::endl;
}
void Matrice::allocation(){
	mat = new double*[nbLin];
	for(int i = 0; i < nbLin; ++i){
    	mat[i] = new double[nbCol];
	}
	std::cout << "alloc : Matrice[" << nbLin <<","<< nbCol << "] @" << this << std::endl;
}
void Matrice::deallocation(){
	for(int i = 0; i < nbLin; ++i){
    	delete [] mat[i];
	}
	delete [] mat[];
	std::cout << "dealloc : Matrice[" << nbLin <<","<< nbCol << "] @" << this << std::endl;
}