#include<iostream>
#include <locale.h>

using namespace std;
const int RAZ = 100;		        //������������ ������ �������
typedef int telem;		            //����������� ���� �������� ��������� �������
typedef telem tmatr[RAZ][RAZ];	    //����������� ���� ���������� �������
typedef telem tmas[RAZ * RAZ];	    //����������� ���� ����������� �������

void input_matr(tmatr a, int& n);
void output_matr(tmatr a, int n);
void sort_vibor_max(tmas& a, int n);
void sort_matr(tmatr& a, int n);
void obnul(tmatr&, int);

int main()
{
    setlocale(LC_ALL, "Rus");
    int n;                          //������ ���������� ������� (2n)*(2n)
    tmatr a;                        //�������� ������� (2n)*(2n)
    input_matr(a, n);               //���� �������� � ������� ������� (2n)*(2n)
    cout << "�������� �������: \n";
    output_matr(a, n);              //����� �������� ������� (2n)*(2n)
    sort_matr(a, n);
    obnul(a, n);
    cout << "������� ����� ����������: \n";
    output_matr(a, n);              //����� ����������� �������
    cout << "\n";
    return 0;
}

//input_matr_beg_____________________________________________________________
//���� �������� ������
void input_matr(tmatr a, int& n)
{
    cout << "������� ����� n - ������ ���������� ������� (2n)*(2n): ";
    cin >> n;
    cout << "������� ��������� ����� ������ �������� ";
    cout << "������� ������� " << 2 * n << "x" << 2 * n << endl;
    cout << "����� ����� ������ ��������� <Enter>" << endl;
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
//����� �������
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
//���������� ��������� ������� �� �������� ������� ������ ���������
void sort_vibor_max(tmas& a, int n)
{
    int i, k, imax;
    telem z;
    for (i = 0; i < n - 1; i++)
    {
        imax = i;		//����� ���������� ���������
        for (k = n; k > i; k--)
        {
            if (a[k] > a[imax]) imax = k;
        }
        //������������ ���������
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
    for (int j = 0; j < n; j++)          //����� ����������� ����� �������
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
    for (int j = n; j < 2 * n; j++)     //������ ����������� ����� �������
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