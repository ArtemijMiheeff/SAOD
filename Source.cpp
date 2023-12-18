/*11. Имеется произвольный текст, сбалансированный по круглым скобкам. Требуется для каждой 
пары соответствующих открывающей и закрывающей скобок определить номера их позиций в тек-
сте, упорядочив пары в порядке возрастания номеров позиций открывающих скобок. Кроме того, 
должна проверяться сбалансированность скобок с указанием, какие скобки не имеют пары. Например, для текста ((a + b)  c – d  min (f, g))h результат будет выглядеть следующим образом: (1, 20), 
(2, 6), (15, 19);
*/
/*
1. Дана произвольная последовательность чисел. За один просмотр этой последовательности
сформировать новую последовательность в следующем порядке: сначала – все числа, меньшие a,
затем – все числа из отрезка [a, b], и наконец – все остальные числа, сохраняя исходный
взаимный порядок в каждой из этих трех групп чисел (a и b – заданные числа, a < b).
*/

#include <iostream>
using namespace std;


int const siz = 50;
int last = 0;
char temp = 0;
bool proof;
char x = 0;

void VivS(char S[siz]);
void Push(char S[siz], char x);

char Pop(char S[siz]);

bool Empty(char S[siz]);

char StackTop(char S[siz]);

int firstq = 0;
int lastq = 0;

void InsQueue(char Q[siz], char x);
void DelQueue(char Q[siz]);

bool EmptyQueue(char Q[siz]);

int last1 = 0;
int last2 = 0;


void Push1(char S[siz], char x);
void Push2(char S[siz], char x);

char Pop1(char S[siz]);
char Pop2(char S[siz]);

bool Empty1(char S[siz]);
bool Empty2(char S[siz]);


void ClearTemp(char S[siz]);
///////////////////////////////////////////////////////////////////////////////////////////////////
void Block1();
void Block2();

int lastq1 = 5, firstq1 = 0, lastq2 = 5, firstq2 = 0;

bool EmptyQueue1(int Q[siz]);
bool EmptyQueue2(int Q[siz]);

void InsQueue1(int Q[siz], int x);
void DelQueue1(int Q[siz]);

void InsQueue2(int Q[siz], int x);
void DelQueue2(int Q[siz]);

void RigQ1(int Q[siz]);
void RigQ2(int Q[siz]);
///////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    setlocale(LC_ALL, "Russian");
   // Block1();
    Block2();
}
///////////////////////////////////////////////////////////////////////////////////////////////////
bool EmptyQueue1(int Q[siz])
{
    if (lastq1 == firstq1)
        return false;
    else
        return true;
}
bool EmptyQueue2(int Q[siz])
{
    if (lastq2 == firstq2)
        return false;
    else
        return true;
}





void InsQueue1(int Q[siz], int x)
{
    Q[lastq1] = x;
    lastq1 += 1;
}
void DelQueue1(int Q[siz])
{
    x = Q[firstq1];
    Q[firstq1] = 0;
    firstq1++;
}

void InsQueue2(int Q[siz], int x)
{
    Q[lastq2] = x;
    lastq2 += 1;
}
void DelQueue2(int Q[siz])
{
    x = Q[firstq2];
    Q[firstq2] = 0;
    firstq2++;
}

void RigQ1(int Q[siz])
{
    while (firstq1 > 0)
    {
        for (int i = firstq1; i < lastq1; i++)
        {
            Q[i - 1] = Q[i];
        }
        firstq1--;
        lastq1--;
        Q[lastq1 + 1] = NULL;
    }
}
void RigQ2(int Q[siz])
{
    while (firstq2 > 0)
    {
        for (int i = firstq2; i < lastq2; i++)
        {
            Q[i - 1] = Q[i];
        }
        firstq2--;
        lastq2--;
        Q[lastq2 + 1] = NULL;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void Block2()
{ 
    int fir[10], sec[10], tempb2;
    for (int i = 0; i < 5; i++)    // вводим значения карт
    {
        cout << "fir " << i << ' ';
        cin >> fir[i];
        cout << endl;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "sec " << i << ' ';
        cin >> sec[i];
        cout << endl;
    }
    // Начало игры
    
    while ((EmptyQueue1(fir) && EmptyQueue2(sec)))            // Команды:     EmptyQueue     InsQueue    DelQueue    RigQ
    {
        cout << "fir" << endl;
        for (int i = firstq1; i < lastq1; i++)
        {
            cout << fir[i] << " ";
        }
        cout << endl;

        cout << "sec" << endl;
        for (int i = firstq2; i < lastq2; i++)
        {
            cout << sec[i] << " ";
        }
        cout << endl;
        cout << endl;
        cout << endl;

        if (fir[0] == 0 && sec[0] == 9)
        {
            DelQueue1(fir);
            InsQueue1(fir, x);
            DelQueue2(sec);
            InsQueue1(fir, x);
            RigQ1(fir);
            RigQ2(sec);
        }
        else
        {
            if (fir[0] == 9 && sec[0] == 0)
            {
                DelQueue2(sec);
                InsQueue2(sec, x);
                DelQueue1(fir);
                InsQueue2(sec, x);
                RigQ1(fir);
                RigQ2(sec);
            }
            else
            {
                if (fir[0] > sec[0])
                {
                    DelQueue1(fir);
                    InsQueue1(fir, x);
                    DelQueue2(sec);
                    InsQueue1(fir, x);
                    RigQ1(fir);
                    RigQ2(sec);
                }
                else
                {
                    DelQueue2(sec);
                    InsQueue2(sec, x);
                    DelQueue1(fir);
                    InsQueue2(sec, x);
                    RigQ1(fir);
                    RigQ2(sec);
                }
            }
        }
        cout << "fir" << endl;
        for (int i = firstq1; i < lastq1; i++)
        {
            cout << fir[i] << " ";
        }
        cout << endl;

        cout << "sec" << endl;
        for (int i = firstq2; i < lastq2; i++)
        {
            cout << sec[i] << " ";
        }
        cout << endl;
        cout << endl;
        cout << endl;
        
    }


}
///////////////////////////////////////////////////////////////////////////////////////////////////
/* 

*/


///////////////////////////////////////////////////////////////////////////////////////////////////
void Block1()
{
    char first[50] = {}, temp1[10] = {}, temp2[10] = {}, firstend[40] = {};

    cout << "Блок 1:" << endl;
    cout << "11. Положение скобок ((a+b)*c-d*min(f,g))*h" << endl; //  ((a+b)*c-d*min(f,g))*h

    cout << "Введите выражение со скобками: ";
    cin >> first;
    cout << endl;
    cout << first << endl;
    int i = 0, j = 0, k = 0, h = 0, te1 = 0, te2 = 0, choise = 0, tem = 0, tempnum[15] = {}, ti = 0;
    int po[11][2];

    ///*
    while (k < 50)
    {
        if (first[k] == '(')
        {
            temp1[i] = first[k];
            tempnum[i] = k;
            i++;
        }
        if (first[k] == ')')
        {
            temp1[i] = first[k];
            tempnum[i] = k;
            i++;
        }
        k++;
    }
    ////cout << endl << temp1 << endl;
    i;
    ti = i;
    j = 0;
    //cout << i << endl << temp1 << endl << endl;
    while (i > 0)
    {
        k = 0;
        choise = 0;
        while (k < 11)
        {
            if (temp1[k] == '(' && temp1[k + 1] == ')')
            {
                po[j][0] = tempnum[k];
                po[j][1] = tempnum[k + 1];
                //cout << "po " << tempnum[k] << " " << tempnum[k + 1] << endl;
                while (k < ti)
                {
                    temp1[k] = temp1[k + 2];
                    tempnum[k] = tempnum[k + 2];
                    k++;
                }
                i = i - 2;
                choise = 1;
                j++;
                break;
            }
            k++;
        }
        if (!choise)
        {
            if (temp1[i - 1] == '(')
            {
                po[j][1] = -1;
                po[j][0] = tempnum[i - 1];
                /*
                cout << "po " << tempnum[i - 1] << " " << tempnum[i] << endl;
                cout << "po2 " << po[j][0] << " " << po[j][1] << endl;
                cout << i - 1 << " "  << temp1 << " " << j << endl;
                */
                j++;
                temp1[i - 1] = temp1[i];
                tempnum[i - 1] = tempnum[i];
            }
            if (temp1[i - 1] == ')')
            {
                po[j][0] = -1;
                po[j][1] = tempnum[i - 1];
                temp1[i - 1] = temp1[i];
                tempnum[i - 1] = tempnum[i];
                j++;
            }
            i--;

        }
    }
    j--;
    h = 0;
    choise = 0;

    // Сортировка 
    int tj = j, tej = 0, tempm;
    choise = 1;
    while (choise)
    {
        choise = 0;
        tej = 0;
        while (tej < tj)
        {
            if (po[tej][0] < po[tej + 1][0])
            {
                tempm = po[tej][0];
                po[tej][0] = po[tej + 1][0];
                po[tej + 1][0] = tempm;
                tempm = po[tej][1];
                po[tej][1] = po[tej + 1][1];
                po[tej + 1][1] = tempm;
                choise = 1;
            }
            tej++;
        }
    }
    cout << endl;

    choise = 0;

    while (j >= 0)
    {
        if (!choise)
        {
            if (po[j][0] == -1)
            {
                cout << "(" << '*' << ",";
            }
            else
            {
                cout << "(" << po[j][0] + 1 << ",";
            }
        }
        else
        {
            if (po[j][0] == -1)
            {
                cout << ",(" << '*' << ",";
            }
            else
            {
                cout << ",(" << po[j][0] + 1 << ",";
            }
        }
        if (po[j][1] == -1)
        {
            cout << '*' << ")";
        }
        else
        {
            cout << po[j][1] + 1 << ")";
        }

        //cout << j << endl;
        j--;
        choise = 1;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void ClearTemp(char S[siz])
{
    for (int i = 0; i < 10; i++)
    {
        S[i] = 0;
    }
}

// 1.

void VivS(char S[siz])
{
    for (int i = last - 1; i >= 0; i--)
    {
        cout << S[i] << " ";
    }
    cout << endl;
}
void Push(char S[siz], char x)
{
    S[last] = x;
    last += 1;
}

char Pop(char S[siz])
{
    if (Empty(S))
    {
        x = S[last];
        S[last] = 0;
        last -= 1;
        return x;
    }
    else
    {
        return 0;
    }
}

bool Empty(char S[siz])
{
    if (last == 0 && S[last] == 0)
    {
        return false;
    }
    return true;
}

char StackTop(char S[siz])
{
    return S[last];
}

void InsQueue(char Q[siz], char x)
{
    Q[lastq] = x;
    lastq += 1;
}
void DelQueue(char Q[siz])
{
    x = Q[lastq];
    Q[lastq] = 0;
    lastq--;
}

bool EmptyQueue(char Q[siz])
{
    if (lastq == firstq && Q[firstq] == 0)
        return false;
    return true;
}

// 2.

void Push1(char S[siz], char x)
{
    S[last1 + 1] = x;
    last1 += 1;
}
void Push2(char S[siz], char x)
{
    S[last2 - 1] = x;
    last2 -= 1;
}

char Pop1(char S[siz])
{
    if (Empty(S))
    {
        x = S[last1];
        S[last1] = 0;
        last1 -= 1;
        return x;
    }
    else
    {
        return 0;
    }
}
char Pop2(char S[siz])
{
    if (Empty(S))
    {
        x = S[last2];
        S[last2] = 0;
        last2 += 1;
        return x;
    }
    else
    {
        return 0;
    }
}

bool Empty1(char S[siz])
{
    if (last1 == 0 && S[last1] == 0)
    {
        return false;
    }
    return true;
}
bool Empty2(char S[siz])
{
    if (last2 == 0 && S[last2] == 0)
    {
        return false;
    }
    return true;
}

// 3.



// 4.




// 5.

