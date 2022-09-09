#define MainNumber 1

#if MainNumber == 1
#include "Matrix.h"
#include <conio.h>

void PrintResult(Matrix& A, Matrix& B, Matrix& sum, char symbol);
void PrintMatrix(Matrix& matrix, int x, int y, string name);

int main()
{
    Matrix A, B;
    A.Init();
    B.Init();

    Matrix sum;
    char cmd;
    while (true)
    {
        system("cls");
        {
            gotoxy(0, 0);
            cout << "A";
            A.print(0, 1);
        }
        {
            gotoxy(A.matrix_X + 2, 0);
            cout << "B";
            B.print(A.matrix_X + 2, 1);
        }
        gotoxy(0, A.matrix_Y + 3);
        cout << "a : 행렬의 덧셈" << endl;
        cout << "d : 행렬의 뺄셈" << endl;
        cout << "m : 행렬의 곳셈" << endl;
        cout << "r : 행렬식의 값" << endl;
        cout << "t : 전치행렬 " << endl;
        cout << "h : 행렬 크기 재 설정" << endl;
        cout << "s : 행렬값 랜덤 재설정" << endl;
        cout << "q : 프로그램 종료" << endl;

        cmd = _getch();

        if (cmd == 'a' || cmd == 'A') // 더하기
        {
            sum.ReSize(A.matrix_X, A.matrix_Y);
            sum.matrix_Index = A.Plus(B);
            PrintResult(A, B, sum, '+');

            gotoxy(0, A.matrix_Y + 5);
            cout << "아무키나 누르면 전 화면으로 되돌아 옵니다." << endl;
            system("pause");
        }
        else if (cmd == 'd' || cmd == 'D')
        {
            sum.ReSize(A.matrix_X, A.matrix_Y);
            sum.matrix_Index = A.Minus(B);
            PrintResult(A, B, sum, '-');

            gotoxy(0, A.matrix_Y + 5);
            cout << "아무키나 누르면 전 화면으로 되돌아 옵니다." << endl;
            system("pause");
        }
        else if (cmd == 'm' || cmd == 'M')
        {
            sum.ReSize(A.matrix_X, A.matrix_Y);
            sum.matrix_Index = A.Multiplication(B);
            PrintResult(A, B, sum, '*');

            gotoxy(0, A.matrix_Y + 5);
            cout << "아무키나 누르면 전 화면으로 되돌아 옵니다." << endl;
            system("pause");
        }
        else if (cmd == 'r' || cmd == 'R')
        {
            system("cls");
            PrintMatrix(A, 0, 0, "A");
            gotoxy(A.matrix_X + 1, A.matrix_Y / 2 + 1);
            cout << "= " << A.determinant(A.matrix_Index, A.matrix_X);

            PrintMatrix(B, A.matrix_X + B.matrix_X + 2, 0, "B");
            gotoxy(A.matrix_X + B.matrix_X + 5, B.matrix_Y / 2 + 1);
            cout << "= " << B.determinant(B.matrix_Index, B.matrix_X);

            gotoxy(0, A.matrix_Y + B.matrix_Y + 5);
            cout << "아무키나 누르면 전 화면으로 되돌아 옵니다." << endl;
            system("pause");
        }
        else if (cmd == 't' || cmd == 'T')
        {
            system("cls");

            PrintMatrix(A, 0, 0, "A");
            A.Transposed();
            PrintMatrix(A, A.matrix_X + 1, 0, "A(T)");
            gotoxy(A.matrix_X * 2 + 1, A.matrix_Y / 2 + 1);
            cout << "= " << A.determinant(A.matrix_Index, A.matrix_X);

            PrintMatrix(B, 0, A.matrix_Y + 2, "B");
            B.Transposed();
            PrintMatrix(B, B.matrix_X + 1, A.matrix_Y + 2, "B(T)");
            gotoxy(A.matrix_X * 2 + 1, A.matrix_Y / 2 + 3);
            cout << "= " << B.determinant(B.matrix_Index, B.matrix_X);

            gotoxy(0, A.matrix_Y + B.matrix_Y + 5);
            cout << "아무키나 누르면 전 화면으로 되돌아 옵니다." << endl;
            system("pause");
        }
        else if (cmd == 'h' || cmd == 'H')
        {
            system("cls");
            int sizeX, sizeY;
            char matrix_Name;
            cout << "바꿀 size를 적어주시오" << endl;
            cout << "가로 : ";
            cin >> sizeX;
            cout << "세로 : ";
            cin >> sizeY;
            cout << endl;
            cout << "바꿀 Matrix를 정해주시오" << endl;
            cout << "A, B 외에 다른 키 입력시 A,B 다 사이즈 재조정" << endl;
            cin >> matrix_Name;
            if (matrix_Name == 'a' || matrix_Name == 'A')
                A.ReSize(sizeX, sizeY);
            else if (matrix_Name == 'b' || matrix_Name == 'B')
                B.ReSize(sizeX, sizeY);
            else
            {
                A.ReSize(sizeX, sizeY);
                B.ReSize(sizeX, sizeY);
            }

            system("pause");
        }
        else if (cmd == 's' || cmd == 'S')
        {
            system("cls");
            cout << "값을 재 설정할 Matrix를 골라주시오" << endl;
            cout << "A, B 외에 다른 키 입력시 A,B 다 값 재조정" << endl;

            char matrix_Name;
            cin >> matrix_Name;
            if (matrix_Name == 'a' || matrix_Name == 'A')
                A.Init();
            else if (matrix_Name == 'b' || matrix_Name == 'B')
                B.Init();
            else
            {
                A.Init();
                B.Init();
            }
            system("pause");
        }
        
        if (cmd == 'q' || cmd == 'Q')
            break;
    }
}

void PrintMatrix(Matrix& matrix, int x, int y, string name)
{
    gotoxy(x, y);
    cout << name;
    matrix.print(x, y + 1);
}

void PrintResult(Matrix& A, Matrix& B, Matrix& sum, char symbol)
{
    system("cls");
    PrintMatrix(A, 0, 0, "A");

    gotoxy(A.matrix_X + 1, A.matrix_Y/2 + 1);
    cout << symbol;

    PrintMatrix(B, A.matrix_X + 2, 0, "B");

    gotoxy(A.matrix_X + B.matrix_X + 3, B.matrix_Y / 2 + 1);
    cout << "=";

    PrintMatrix(sum, A.matrix_X + B.matrix_X + 4, 0, "sum");
}



#endif // 0