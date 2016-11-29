#ifndef C_MATRICE
#define C_MATRICE

//#include <iostream>
//#include <ostream>

class Matrice{
	private:
	double **mat;
	int nbCol;
	int nbLin;
	public:
	Matrice();
	Matrice(int nbLin, int nbCol);
	Matrice(Matrice & matrice);
	Matrice& operator=(const Matrice& matrice);
	~Matrice();

	void allocation();
	void deallocation();

	int getNbLin();
	int getNbCol();

	double& getCase(int numLine, int numCol);
	
	friend Matrice transposee(Matrice a);

	friend Matrice operator+(Matrice a, Matrice b);
	friend Matrice operator-(Matrice a, Matrice b);
	friend Matrice operator-(Matrice a);

	/*friend istream& operator<<(istream & istrm, Matrice a);
	friend ostream& operator>>(ostream & ostrm, Matrice a);*/

	double* operator[](int numLine);
};

#endif