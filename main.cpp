#include <iostream>
#include <iomanip>
//#include <cassert>
#include "matrix.h"
using namespace std;

void print(matrix, matrix, matrix );
int main()
{
    int data1 [] = {1,2,3,4,5,6,7,8};
    int data2 [] = {13,233,3,4,5,6};
    int data3 [] = {10,100,10,100,10,100,10,100};
    int num;

     matrix mat1(4, 2, data1, mat1);
     matrix mat2(2, 3, data2, mat2);
     matrix mat3(4, 2, data3, mat3);

    print( mat1, mat2, mat3);



    cout <<"matrix1 + matrix3 "<<endl<< mat1 + mat3 <<endl;

    try
    {
        cout <<" matrix3 + matrix2 "<<endl;
        cout<< (mat3 + mat2) << endl;
    }

    catch (const char* except)
    {
        cout<<except<<endl;
    }

    cout <<" matrix3 - matrix3 "<<endl<< (mat3 - mat3) << endl;

    cout <<" matrix3 * matrix1 "<<endl;
    if(mat3.getColumn()==mat1.getRow())
    {
        cout <<mat3 * mat1 << endl;
    }
    else
    {
        cout<<"can't be multiplied as 1st matrix column and 2nd matrix row aren't equal"<<endl;
    }

    cout <<" matrix3 * matrix2 "<<endl<< (mat3 * mat2) << endl;


    cout<<"matrix3 + number "<<endl<<"Enter a number: ";
    cin>>num;
    cout<<endl<<mat3+num;

    cout<<"matrix1 - number "<<endl<<"Enter a number: ";
    cin>>num;
    cout<<endl<<mat1-num;

    cout<<"matrix3 * number "<<endl<<"Enter a number: ";
    cin>>num;
    cout<<endl<<mat3*num;


      cout <<" matrix3 += matrix1 "<<endl<< (mat3 += mat1) << endl;

       cout <<" matrix3 -+ matrix1 "<<endl<< (mat3 -= mat1) << endl;

       cout<<"matrix1 ++"<<endl<<(++mat1 )<<endl;
       cout<<"matrix2 --"<<endl<< --mat2<<endl;

       matrix mat4;
       cin>>mat4;
      cout<<"printing the matrix that we entered"<<endl<<mat4;
    return 0;
    }



void print(matrix mat1, matrix mat2, matrix mat3)
{

    cout<<"MATRIX 1:"<<endl;
    cout << mat1 << endl;
    cout<<"MATRIX 2:"<<endl;
    cout << mat2 << endl;
    cout<<"MATRIX 3:"<<endl;
    cout << mat3 << endl;
}




