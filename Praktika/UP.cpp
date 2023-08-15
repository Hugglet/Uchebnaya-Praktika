#include<iostream>
#include <locale.h>

using namespace std;
const int RAZ = 100;		        //maximum matrix size
typedef int telem;		            //determining the type of values of array elements
typedef telem tmatr[RAZ][RAZ];	    //determining the type of a two-dimensional array
typedef telem tmas[RAZ * RAZ];	    //defining the type of a one-dimensional array

void input_matr(tmatr a, int& n);
void output_matr(tmatr a, int n);
void sort_vibor_max(tmas& a, int n);
void sort_matr(tmatr& a, int n);
void obnul(tmatr&, int);

int main()
{
    int n;                          //square matrix size (2n)*(2n)
    tmatr a;                        //the original matrix is (2n)*(2n)
    input_matr(a, n);               //entering values and matrix size (2n)*(2n)
    cout << "The original matrix: \n";
    output_matr(a, n);              //output of the original matrix (2n)*(2n)
    sort_matr(a, n);
    obnul(a, n);
    cout << "Matrix after sorting: \n";
    output_matr(a, n);              //output of the received array
    cout << "\n";
    return 0;
}

//input_matr_beg_____________________________________________________________
//Input of initial data
void input_matr(tmatr a, int& n)
{
    cout << "Enter the number n - the size of the square matrix (2n)*(2n): ";
    cin >> n;
    cout << "Enter the elements line by line separated by a space ";
    cout << "size matrices " << 2 * n << "x" << 2 * n << endl;
    cout << "After entering the line, press <Enter>" << endl;
    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            cin >> a[i][j];
        }
    }
    return;
}
//input_matr_end_____________________________________________________________

//output_matr_beg____________________________________________________________
//Matrix output
void output_matr(tmatr a, int n)
{
    cout << endl;
    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            cout.width(4);
            cout << a[i][j];
        }
        cout << endl << endl;
    }
    cout << endl;
    return;
}
//output_matr_end____________________________________________________________

//sort_vibor_max_beg_________________________________________________________
//Sorting array elements in descending order by the maximum selection method
void sort_vibor_max(tmas& a, int n)
{
    int i, k, imax;
    telem z;
    for (i = 0; i < n - 1; i++)
    {
        imax = i;		//search for the next maximum
        for (k = n; k > i; k--)
        {
            if (a[k] > a[imax]) imax = k;
        }
        //rearranging elements
        z = a[i];
        a[i] = a[imax];
        a[imax] = z;
    }
}
//sort_vibor_max_end_________________________________________________________

//sort_matr_beg______________________________________________________________
void sort_matr(tmatr& a, int n)
{
    int c = 0;
    tmas ar;
    for (int j = 0; j < n; j++)          //the left sortable part of the matrix
    {
        for (int i = j; i < 2 * n - j; i++)
        {
            ar[c] = a[i][j];
            c++;
        }
        c++;
        sort_vibor_max(ar, c);
        c = 0;
        for (int i = j; i < 2 * n - j; i++)
        {
            a[i][j] = ar[c];
            c++;
        }
        c = 0;
    }
    for (int j = n; j < 2 * n; j++)     //the right sortable part of the matrix
    {
        c = 0;
        for (int i = 2 * n - j - 1; i < j + 1; i++)
        {
            ar[c] = a[i][j];
            c++;
        }
        c++;
        sort_vibor_max(ar, c);
        c = 0;
        for (int i = 2 * n - j - 1; i < j + 1; i++)
        {
            a[i][j] = ar[c];
            c++;
        }
        c = 0;
    }
}
//sort_matr_end______________________________________________________________

//obnul_beg__________________________________________________________________
void obnul(tmatr& a, int n)
{
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < j; i++)
        {
            a[i][j] = 0;
        }
        for (int i = 2 * n - 1; i > 2 * n - j - 1; i--)
        {
            a[i][j] = 0;
        }
    }
    for (int j = n; j < 2 * n; j++)
    {
        for (int i = 0; i < 2 * n - j - 1; i++)
        {
            a[i][j] = 0;
        }
        for (int i = 2 * n - 1; i > j; i--)
        {
            a[i][j] = 0;
        }
    }
}
//obnul_end__________________________________________________________________
