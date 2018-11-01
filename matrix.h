#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;

class matrix
{
    public:

matrix (int row, int col, int num[], matrix& mat);
matrix (int row,int col);
matrix();
friend ostream& operator<< (ostream& out, matrix mat);

matrix operator+  ( matrix mat2); // Add if same dimensions
matrix operator-  ( matrix mat2); // Sub if same dimensions
matrix operator*  ( matrix mat2); // Multi if col1 == row2
matrix operator+  ( int scalar);  // Add a scalar
matrix operator-  (int scalar);  // Subtract a scalar
matrix operator*  ( int scalar);  // Multiple by scalar
int getRow();
int getColumn();
  virtual ~matrix();


matrix operator+= ( matrix mat2); // mat1 changes & return
					    // new matrix with the sum
matrix operator-= ( matrix mat2); // mat1 changes + return new
					     // matrix with difference
matrix operator+= ( int scalar);   // change mat & return new matrix
matrix operator-= ( int scalar);   // change mat & return new matrix
matrix   operator++ ();   	// Add 1 to each element ++mat
matrix  operator-- ();    	// Sub 1 from each element --mat
friend istream& operator>> (istream& in, matrix& mat);


private:

    int* data;       // Pointer to 1-D array that will simulate matrix
    int row, col;
};

#endif // MATRIX_H
