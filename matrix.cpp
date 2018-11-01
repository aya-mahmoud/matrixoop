#include "matrix.h"

int matrix::getColumn(){
return col;
}

int matrix::getRow(){
return row;}

matrix::matrix (int row, int col, int num[], matrix& mat)
{
    mat.row = row;
    mat.col = col;
    mat.data = new int [row * col];
    for (int i = 0; i < row * col; i++)
        mat.data [i] = num [i];
}
//copy constructor
matrix::matrix(int row,int col)
{

    this->row=row;
    this->col=col;
    data=new int[row*col];

}

matrix::matrix(){

}
matrix::~matrix()
{
    //dtor
    data=nullptr;
    delete data;
}
matrix matrix::operator+  ( matrix mat2)
{
    if (row==mat2.row  && col==mat2.col)
    {
        matrix mat(mat2.row,mat2.col);

        for(int i=0; i<row*col; i++)
        {

            mat.data[i]=data[i]+mat2.data[i];


        }

        return mat;
    }
    else
    {
        throw "can't be added as the dimensions aren't the same";
    }

}

// subtract a matrix from another and return new one
matrix matrix::operator-  ( matrix mat2)
{
    matrix mat(mat2.row,mat2.col);
    if (row==mat2.row  && col==mat2.col)
    {

   for(int i=0; i<row*col; i++)
        {


            mat.data[i]=data[i]-mat2.data[i];
        }
        return mat;
    }
    else
    {
        cout<< "can't be subtracted as the dimensions aren't the same";
    }
    //return mat;
}

//multiplying two matrices and returning new matrix
matrix matrix::operator*  (matrix mat2)
{
    int sum;
    matrix mat3;
    mat3.row=row;
    mat3.col=mat2.col;
    mat3.data=new int[mat3.row*mat3.col];
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<mat2.col; j++)
        {

            sum=0;
            for(int k=0; k<col; k++)
            {

                sum+=data[i*col+k]*mat2.data[k*mat2.col+j];
            }
            mat3.data[i*mat3.col+j]=sum;
        }

    }

    return mat3;
}

//add a number to matrix returning a new matrix
matrix matrix::operator+  ( int scalar)
{
    matrix mat( row,col);
    for(int i=0; i<row*col; i++)
    {
        mat.data[i]=data[i]+scalar;

    }
    return mat;
}

//subtract a number form matrix returning new matrix
matrix matrix::operator-  (int scalar)
{
    matrix mat( row,col);
    for(int i=0; i<row*col; i++)
    {
        mat.data[i]=data[i]-scalar;

    }
    return mat;
}


//multiply matrix by number returning a new matrix
matrix matrix::operator*  ( int scalar)
{
    matrix mat(row,col);
    for(int i=0; i<row*col; i++)
    {
        mat.data[i]=data[i]*scalar;

    }
    return mat;
}


ostream& operator<< (ostream& out, matrix mat)
{
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0; j<mat.col; j++)
        {
            out<<mat.data[i*mat.col+j]<<" ";

        }
        out<< endl;

    }
    return out;
}
matrix matrix:: operator+= ( matrix mat2){
    matrix mat(mat2.row,mat2.col);
    mat=*this;
    for (int i=0;i<mat.row * mat.col; i++){
        mat.data[i] = mat.data[i] + mat2.data[i];
        }
        return mat;
}



matrix matrix:: operator-= ( matrix mat2){
    matrix mat(mat2.row,mat2.col);
    mat=*this;
    for (int i=0;i< mat.row * mat.col; i++){
        mat.data[i] = mat.data[i] - mat2.data[i];
        }
        return mat;
}





matrix matrix::   operator++ (){
     matrix mat(row,col);
     mat=*this;
    for (int i=0;i<row * col; i++){
        data[i] = data[i] + 1 ;
        }
return mat;
}



matrix matrix::  operator-- (){
        matrix mat(row,col);
        mat=*this;
        for (int i=0;i<row * col; i++){
        data[i] = data[i] - 1 ;
        }
return mat;
}

istream& operator>> (istream& in, matrix& mat){
    int row , col ;
    cout << "Enter number of rows : " ;
    cin >> row;
    cout << "\nEnter number of columns : " ;
    cin >> col ;
    cout << "\nEnter data : " ;
    int num [row * col];
    for (int i=0;i<row*col;i++){
        cin >> num[i];
    }


}
