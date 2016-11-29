#include <iostream>
#include <ostream>
#include "Matrice.h"

Matrice::Matrice()
{
    nbCol = 0;
    nbLin = 0;
    std::cout << "+++Matrice() @" << this << std::endl;
}

Matrice::Matrice(int nbLin, int nbCol)
{
    this->nbLin = nbLin;
    this->nbCol = nbCol;
    allocation();
    std::cout << "+++Matrice(" << nbLin << "," << nbCol << ") @" << this << std::endl;
}

Matrice::Matrice(Matrice &matrice)
{
    this->nbLin = matrice.nbLin;
    this->nbCol = matrice.nbCol;
    allocation();
    memcpy(mat[0], matrice.mat[0], nbLin * nbCol * sizeof mat[0][0]);
    std::cout << "rrrMatrice(" << nbLin << "," << nbCol << ") @" << this << std::endl;
}
Matrice::~Matrice()
{
    deallocation();
    std::cout << "---Matrice(" << nbLin << "," << nbCol << ") @" << this << std::endl;
}

Matrice& Matrice::operator=(const Matrice &matrice)
{
    //desalouer
    deallocation();
    //realouer
    nbLin = matrice.nbLin;
    nbCol = matrice.nbCol;
    allocation();
    //memcpy
    memcpy(mat[0], matrice.mat[0], nbLin * nbCol * sizeof mat[0][0]);
    std::cout << "affect : Matrice(" << nbLin << "," << nbCol << ") @" << this << std::endl;
	return *this;
}

double* Matrice::operator[](int numLine)
{
    if (numLine < 0 || numLine >= nbLin + 1)
    {
		throw "Debordement d'indices' : < 0 ou >= " + nbLin;
    }
    return mat[numLine];
}

int Matrice::getNbLin()
{
    return nbLin;
}
int Matrice::getNbCol()
{
    return nbCol;
}

void Matrice::allocation()
{
    mat = new double *[nbLin];
    for (int i = 0; i < nbLin; ++i)
    {
		mat[i] = new double[nbCol];
    }
    std::cout << "alloc : Matrice[" << nbLin << "," << nbCol << "] @" << this << std::endl;
}
void Matrice::deallocation()
{
    for (int i = 0; i < nbLin; ++i)
    {
		delete[] mat[i];
    }
    delete[] mat;
    std::cout << "dealloc : Matrice[" << nbLin << "," << nbCol << "] @" << this << std::endl;
}

double& Matrice::getCase(int numLine, int numCol)
{
    if (numLine <= 0 || numCol <= 0)
    {
		throw "Debordement de taille : les indices commencent à 1";
    }
    else if (numLine >= nbLin + 1 || numCol >= nbCol + 1)
    {
		throw "Debordement  : les indices dépassent la taille de la matrice : > " + nbCol;
    }
    std::cout << "getCase : Matrice[" << numLine << "][" << numCol << "] = " << mat[numLine - 1][numCol - 1] << std::endl;
    return mat[numLine - 1][numCol - 1];
}

/*Matrice transposee(Matrice a)
{
}*/

Matrice operator+(Matrice a, Matrice b)
{
    Matrice sum(a);
    for (int i = 0; i < a.getNbLin(); ++i)
    {
		for (int j = 0; j < a.getNbCol(); ++j)
		{
			sum[i][j] += b[i][j];
		}
    }
	return sum;
}
Matrice operator-(Matrice a, Matrice b)
{
	Matrice diff(a);
    for (int i = 0; i < a.getNbLin(); ++i)
    {
		for (int j = 0; j < a.getNbCol(); ++j)
		{
			diff[i][j] -= b[i][j];
		}
    }
	return diff;
}
Matrice operator-(Matrice a)
{
	Matrice opp(a);
    for (int i = 0; i < a.getNbLin(); ++i)
    {
		for (int j = 0; j < a.getNbCol(); ++j)
		{
			opp[i][j] *= -1;
		}
    }
	return opp;
}
//Remplissage de la matrice
/*istream & operator>>(istream &istrm, Matrice a)
{
	cout << endl << "Entrer les coefficients de la matrice " << endl;
    for(i = 0; i < a.getNbLin(); ++i)
       for(j = 0; j < a.getNbCol(); ++j)
       {
           cout << "Entrer le coefficient a[" << i + 1 << "][" << j + 1 << "] : ";
           istrm >> a.getCase(i,j);
       }
	return istrm;
}
//Affichage de la matrice
ostream & operator<<(ostream &ostrm, const Matrice a)
{
	ostrm << endl << "Affichage de la matrice: " << endl;
    for(i = 1; i < a.getNbLin() + 1; ++i)
	{
        for(j = 1; j < a.getNbCol() + 1; ++j)
        {
            ostrm << a.getCase(i,j) << ",  ";
            if(j == a.getNbCol())
			{
                ostrm << endl;
			}
        }
	}
	return ostrm;
}*/