// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 2
// Program: CS213-2018-A1-T1-P2
// Purpose: Doing matrix operations
// Author1: Mostafa Khaled - 20170288 - G8
// Author2: Ola Sameh - 20170165 - G8
// Date:    3/10/2018
// Version: 1.0

#include <iostream>
#include <iomanip>
#include <valarray>

using namespace std;

// A structure to store a matrix
struct matrix
{
    valarray<int> data;       //valarray that will simulate matrix
    int row, col;
};


void createMatrix (int row, int col, int num[], matrix& mat);  //creat a matrix

matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);   // Multiple by scalar
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	           // Add 1 to each element ++mat
void   operator-- (matrix& mat);    	       // Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat); //takes an istream and a matrix and return the the same istream so it is possible to cascade input
ostream& operator<< (ostream& out, matrix mat); // Print matrix and return ostream to cascade printing
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix  (have the same number of rows and columns)
bool   isSymetric (matrix mat);  // True if square and symmetric (mat1= traspose of mat1) (have the same number of rows and columns)
bool   isIdentity (matrix mat);  // True if square and identity (diagonals are equal 1 and the rest equal zero)
matrix transpose(matrix mat);    // Return new matrix with the transpose


int main()
{
    int data1 [] = {1,2,3,4,5,6,7,8};
    int data2 [] = {13,233,3,4,5,6};
    int data3 [] = {10,100,10,100,10,100,10,100};
    int data4 [] = {1,2,3,4,5,6,7,8,9};
    int data5 [] = {1,2,2,1};
    int data6 [] = {1,2,3,2,5,4,3,4,7};
    int data7 [] = {1,0,0,0,1,0,0,0,1};

    matrix mat1, mat2, mat3, mat4, mat5, mat6, mat7, mat8;
    createMatrix (4, 2, data1, mat1);
    createMatrix (2, 3, data2, mat2);
    createMatrix (4, 2, data3, mat3);
    createMatrix (4, 2, data4, mat4);
    createMatrix (2, 2, data5, mat5);
    createMatrix (3, 3, data6, mat6);
    createMatrix (3, 3, data7, mat7);

    //cout << mat1 + mat3;

    //cout << mat3 - mat1;

    //cout << mat1 * mat2;

    /*int num;
    cout << mat1 + num;
    cout << mat2 - num;
    cout << mat3 * num;*/

    /*mat1 += mat1;
    cout << mat1;*/

    /*mat1 -= mat1;
    cout << mat1;*/

    /*mat1 += num;
    cout << mat1;*/

    /*mat2 -= num;
    cout < <mat2;*/

    /*++mat1;
    cout << mat1;*/

    /*--mat1;
    cout << mat1 */

    /*cin >> mat8;
    cout << mat8;*/

    //cout << (mat1 == mat4);

    //cout << (mat1 != mat2);

    //isIdentity(mat7);

    //isSquare(mat6);

    //cout<<isSymetric(mat7);

    //cout << transpose(mat1);



    return 0;
}


void createMatrix (int row, int col, int num[], matrix& mat)  // Takes an array of data and stores in matrix according to rows and columns
{
    mat.row = row;
    mat.col = col;
    mat.data.resize (row * col);
    for (int i = 0; i < row * col; i++)
        mat.data [i] = num [i];
}

istream& operator>> (istream& in, matrix& mat){  //takes rows and columns and the data of the matrix
    cout<<"Enter numbers of row: ";
    in >> mat.row;
    cout<<"Enter numbers of columns: ";
    in >> mat.col;
    mat.data.resize(mat.row * mat.col);
    cout<<"Enter your matrix: ";
    for(int i = 0; i < mat.row * mat.col; i++){
        int x;
        in >> x;
        mat.data[i] = x;
    }

    return in;
}

ostream& operator<< (ostream& out, matrix mat){  //print the matrix
    int cnt = 0;
    for(int i=0; i < mat.row * mat.col; i++){
        out << mat.data[i] << " ";
        cnt++;
        if(cnt == mat.col){
            out << '\n';
            cnt = 0;
        }
    }
    return out;
}

matrix operator+ (matrix mat1, matrix mat2)   //add two matrix if they have the same dimensions
{
    if(mat1.row != mat2.row || mat1.col != mat2.col)
    {
        cout<< "invalid operation"<<endl;
        matrix nan;
        nan.row = 2;
        nan.col = 2;
        nan.data.resize (nan.row * nan.col);
    for (int i = 0; i < nan.row * nan.col; i++)
        nan.data [i] = 0;
        return nan;
    }

    matrix ret;
    ret.row = mat1.row;
    ret.col = mat1.col;
    ret.data.resize(ret.row * ret.col);

    for(int i=0; i < mat1.row * mat1.col; i++)
    {
        ret.data[i] = mat1.data[i] + mat2.data[i];
    }

    return ret;
}

matrix operator- (matrix mat1, matrix mat2)  //subtract two matrix if they have the same dimensions
{
    if(mat1.row != mat2.row || mat1.col != mat2.col)
    {
        cout<< "invalid operation"<<endl;
        matrix nan;
        nan.row = 2;
        nan.col = 2;
        nan.data.resize (nan.row * nan.col);
    for (int i = 0; i < nan.row * nan.col; i++)
        nan.data [i] = 0;
        return nan;
    }

    matrix ret;
    ret.row = mat1.row;
    ret.col = mat1.col;
    ret.data.resize(ret.row * ret.col);

    for(int i=0; i < mat1.row * mat1.col; i++)
    {
        ret.data[i] = mat1.data[i] - mat2.data[i];
    }
    return ret;
}

matrix operator*  (matrix mat1, matrix mat2)  //multiply two matrix
{
    if(mat1.col != mat2.row)
    {
        cout<< "invalid operation"<<endl;
        matrix nan;
        nan.row = 2;
        nan.col = 2;
        nan.data.resize (nan.row * nan.col);
    for (int i = 0; i < nan.row * nan.col; i++)
        nan.data [i] = 0;
        return nan;
    }
    matrix ret;
    ret.row = mat1.row;
    ret.col = mat2.col;
    ret.data.resize(ret.row * ret.col);
    int sum = 0;
    int cnt = 0;
    for(int l = 0; l < mat1.row; l++){
        for(int j = 0; j < mat2.col; j++){
            int col_ctr = j;
            for(int k = 0; k < mat1.col; k++){
                sum += mat1.data[k + l * mat1.col] * mat2.data[col_ctr];
                col_ctr += mat2.col;
                if(k == mat1.col - 1)
                {
                    ret.data[cnt] = sum;
                    sum = 0;
                    cnt++;
                }
            }
        }
    }
    return ret;
}

matrix operator+  (matrix mat1, int scalar)  //add matrix to a number
{
    int num;
    matrix ret;
    ret.row = mat1.row;
    ret.col = mat1.col;
    ret.data.resize(ret.row * ret.col);
    cout<<"enter a number: ";
    cin>>num;
    for(int i = 0; i < mat1.row * mat1.col; i++)
    {
        ret.data[i] = mat1.data[i] + num;
    }
    return ret;
}

matrix operator-  (matrix mat2, int scalar)  //subtract matrix to a number
{
    int num;
    matrix ret;
    ret.row = mat2.row;
    ret.col = mat2.col;
    ret.data.resize(ret.row * ret.col);
    cout<<"enter a number: ";
    cin>>num;
    for(int i = 0; i < mat2.row * mat2.col; i++)
    {
        ret.data[i] = mat2.data[i] - num;
    }
    return ret;
}

matrix operator*  (matrix mat1, int scalar)  //multiply matrix to a number
{
    int num;
    matrix ret;
    ret.row = mat1.row;
    ret.col = mat1.col;
    ret.data.resize(ret.row * ret.col);
    cout<<"enter a number: ";
    cin>>num;
    for(int i=0; i < mat1.row * mat1.col; i++)
    {
        ret.data[i] = mat1.data[i] * num;
    }
    return ret;
}

matrix operator+= (matrix& mat1, matrix mat2)   //add two matrix if they have the same dimension and return the result in the first matrix
{
    if(mat1.row != mat2.row || mat1.col != mat2.col)
    {
        cout<< "invalid operation"<<endl;
        matrix nan;
        nan.row = 2;
        nan.col = 2;
        nan.data.resize (nan.row * nan.col);
    for (int i = 0; i < nan.row * nan.col; i++)
        nan.data [i] = 0;
        return nan;
    }

    matrix ret;
    ret.row = mat1.row;
    ret.col = mat1.col;
    ret.data.resize(ret.row * ret.col);

    for(int i=0; i < mat1.row * mat1.col; i++)
    {
        ret.data[i] = mat1.data[i] + mat2.data[i];
        mat1.data [i] = ret.data [i];
    }
    return mat1;
}

matrix operator-= (matrix& mat1, matrix mat2) //subtract two matrix if they have the same dimension and return the result in the first matrix
{
    if(mat1.row != mat2.row || mat1.col != mat2.col)
    {
        cout<< "invalid operation"<<endl;
        matrix nan;
        nan.row = 1;
        nan.col = 1;
        nan.data.resize (nan.row * nan.col);
    for (int i = 0; i < 1; i++)
        nan.data [i] = 0;
        return nan;
    }

    matrix ret;
    ret.row = mat1.row;
    ret.col = mat1.col;
    ret.data.resize(ret.row * ret.col);

    for(int i = 0; i < mat1.row * mat1.col; i++)
    {
        ret.data[i] = mat1.data[i] - mat2.data[i];
        mat1.data [i] = ret.data [i];
    }
    return mat1;
}
matrix operator+= (matrix& mat, int scalar) //add matrix to a nember and return the result in the first matrix
{
    int num;
    matrix ret;
    ret.row = mat.row;
    ret.col = mat.col;
    ret.data.resize(ret.row * ret.col);
    cout<<"enter a number: ";
    cin>>num;
    for(int i = 0; i < mat.row * mat.col; i++)
    {
        ret.data[i] = mat.data[i] + num;
        mat.data[i] = ret.data[i];
    }
    return mat;
}
matrix operator-= (matrix& mat, int scalar)  //subtract matrix to a nember and return the result in the first matrix
{
    int num;
    matrix ret;
    ret.row = mat.row;
    ret.col = mat.col;
    ret.data.resize(ret.row * ret.col);
    cout<<"enter a number: ";
    cin>>num;
    for(int i = 0; i < mat.row * mat.col; i++)
    {
        ret.data[i] = mat.data[i] - num;
        mat.data[i] = ret.data[i];
    }
    return mat;
}
void   operator++ (matrix& mat) //add 1 to each number in the matrix
{
    matrix ret;
    ret.row = mat.row;
    ret.col = mat.col;
    ret.data.resize(ret.row * ret.col);
    for(int i = 0; i < mat.row * mat.col; i++)
    {
        ret.data[i] = mat.data[i]+1;
        mat.data[i] = ret.data[i];
    }
}

void   operator-- (matrix& mat)  //subtract 1 to each number in the matrix
{
    matrix ret;
    ret.row = mat.row;
    ret.col = mat.col;
    ret.data.resize(ret.row * ret.col);
    for(int i = 0; i < mat.row * mat.col; i++)
    {
        ret.data[i] = mat.data[i]-1;
        mat.data[i] = ret.data[i];
    }
}

bool   operator== (matrix mat1, matrix mat2)  //check if the two matrix are equal
{
    if (mat1.row == mat2.row && mat1.col == mat2.col)
    {
        for (int i=0 ; i < mat1.row * mat1.col; i++)
        {
            if (mat1.data[i] != mat2.data[i])
            {
                cout<<"Not Equal"<<endl;
                return false;
            }
        }
        cout<<"Equal"<<endl;
        return true;
    }
    cout<<"Not Equal"<<endl;
    return false ;
}

bool   operator!= (matrix mat1, matrix mat2)   //check if the two matrix are not equal
{
    if(mat1.row != mat2.row || mat1.col != mat2.col)
        {cout<<"Not Equal"<<endl;
        return true;}

    else
    {
        for (int i=0 ; i < mat1.row * mat1.col; i++)
        {
            if (mat1.data[i] != mat2.data[i])
            {
                cout<<"Not Equal"<<endl;
                return true;
            }
        }
        cout<<"Equal"<<endl;
        return false ;
    }
}

bool   isSquare(matrix mat)  //check if the matrix have the same number of rows and columns
{
    if (mat.row == mat.col)
    {
        cout<<"square"<<endl;
        return true ;
    }
    cout<<"Not square"<<endl;
    return false;
}

bool   isSymetric(matrix mat)  //check if the matrix symmetric or not
{
    matrix tran = transpose(mat);
    for (int i = 0 ; i < tran.col * tran.col ;i++){
    if(tran.row == mat.row && tran.col == mat.col && tran.data[i]== mat.data[i]) {
        cout<< "symmetric"<<endl;
        return true;
}
else {
    cout<< "Not symmetric"<<endl;
    return false;
    }

}

}

bool   isIdentity (matrix mat)  //check if the matrix identity or not
{
    if (mat.row == mat.col)
    {
        int cnt = 0;
        for (int i = 0 ; i< mat.row * mat.col ; i++)
        {
            if(cnt == mat.col || (i == 0 && mat.data[i] == 1)){
                if(mat.data[i] == 1){
                    cnt = 0;
                    continue;
                }
                else{
                    cout << "Not Identical matrix" << endl;
                    return false;
                }
            }
            else{
                if(mat.data[i] != 0){
                    cout << "Not Identical matrix" << endl;
                    return false;
                }
                else
                    cnt++;
            }
        }
        cout << "Identical matrix" << endl;
        return true;
    }
    else
    {
        cout<<"Not Identity matrix"<<endl;
        return false ;
    }
}

matrix transpose(matrix mat)  //transpose the matrix
{
    matrix ret;
    ret.row = mat.col;
    ret.col = mat.row;
    ret.data.resize(ret.row * ret.col);

    for(int j = 0; j < mat.col; j++){
        int col_cnt = j;
        for(int i = 0; i < ret.col; i++){
            ret.data[i + j * ret.col] = mat.data[col_cnt];
            col_cnt += mat.col;
        }
    }

    return ret;
}
