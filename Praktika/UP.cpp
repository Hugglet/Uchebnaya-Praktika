#include<iostream>
#include <locale.h>

using namespace std;
const int RAZ = 100;		        //ìàêñèìàëüíûé ðàçìåð ìàòðèöû
typedef int telem;		            //îïðåäåëåíèå òèïà çíà÷åíèé ýëåìåíòîâ ìàññèâà
typedef telem tmatr[RAZ][RAZ];	    //îïðåäåëåíèå òèïà äâóìåðíîãî ìàññèâà
typedef telem tmas[RAZ * RAZ];	    //îïðåäåëåíèå òèïà îäíîìåðíîãî ìàññèâà

void input_matr(tmatr a, int& n);
void output_matr(tmatr a, int n);
void sort_vibor_max(tmas& a, int n);
void sort_matr(tmatr& a, int n);
void obnul(tmatr&, int);

int main()
{
    system("chcp 1251");
    setlocale(LC_ALL, "Rus");
    int n;                          //ðàçìåð êâàäðàòíîé ìàòðèöû (2n)*(2n)
    tmatr a;                        //èñõîäíàÿ ìàòðèöà (2n)*(2n)
    input_matr(a, n);               //ââîä çíà÷åíèé è ðàçìåðà ìàòðèöû (2n)*(2n)
    cout << "Èñõîäíàÿ ìàòðèöà: \n";
    output_matr(a, n);              //âûâîä èñõîäíîé ìàòðèöû (2n)*(2n)
    sort_matr(a, n);
    obnul(a, n);
    cout << "Ìàòðèöà ïîñëå ñîðòèðîâêè: \n";
    output_matr(a, n);              //âûâîä ïîëó÷åííîãî ìàññèâà
    cout << "\n";
    return 0;
}

//input_matr_beg_____________________________________________________________
//Ââîä èñõîäíûõ äàííûõ
void input_matr(tmatr a, int& n)
{
    cout << "Ââåäèòå ÷èñëî n - ðàçìåð êâàäðàòíîé ìàòðèöû (2n)*(2n): ";
    cin >> n;
    cout << "Ââåäèòå ïîñòðî÷íî ÷åðåç ïðîáåë ýëåìåíòû ";
    cout << "ìàòðèöû ðàçìåðà " << 2 * n << "x" << 2 * n << endl;
    cout << "Ïîñëå ââîäà ñòðîêè íàæèìàéòå <Enter>" << endl;
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
//Âûâîä ìàòðèöû
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
//Ñîðòèðîâêà ýëåìåíòîâ ìàññèâà ïî óáûâàíèþ ìåòîäîì âûáîðà ìàêñèìóìà
void sort_vibor_max(tmas& a, int n)
{
    int i, k, imax;
    telem z;
    for (i = 0; i < n - 1; i++)
    {
        imax = i;		//ïîèñê î÷åðåäíîãî ìàêñèìóìà
        for (k = n; k > i; k--)
        {
            if (a[k] > a[imax]) imax = k;
        }
        //ïåðåñòàíîâêà ýëåìåíòîâ
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
    for (int j = 0; j < n; j++)          //ëåâàÿ ñîðòèðóåìàÿ ÷àñòü ìàòðèöû
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
    for (int j = n; j < 2 * n; j++)     //ïðàâàÿ ñîðòèðóåìàÿ ÷àñòü ìàòðèöû
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
