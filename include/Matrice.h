#ifndef C_MATRICE
#define C_MATRICE

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

	int nbLin();
	int nbCol();

	double* getLine();
	
	friend Matrice transposee(Matrice a);
	friend Matrice operator+(Matrice a, Matrice b);
	friend Matrice operator-(Matrice a, Matrice b);
	friend Matrice operator-(Matrice a);
	friend Matrice operator<<(Matrice a, Matrice b);
	friend Matrice operator>>(Matrice a, Matrice b);
	friend Matrice operator[](Matrice a, Matrice b);
};

#endif