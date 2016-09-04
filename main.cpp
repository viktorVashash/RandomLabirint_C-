#include<iostream>

using namespace std;

#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void gotoxy(int xpos, int ypos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos; scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);
}


void main()
{
    char t = '1';
    while (t == '1')
    {
        srand(time(NULL));
        system("cls");

        char mas[24][39];
        int vhid = rand() % 36 + 1; //  для места входа
        int vuhid = rand() % 36 + 1; //  для места выхода


        for (int i = 0; i < 24; i++)
        {
            for (int j = 0; j < 39; j++)
            {
                if (rand() % 4 == 0)
                    mas[i][j] = static_cast<char>(176);
                else
                    mas[i][j] = ' ';

                mas[i][0] = static_cast<char>(176);//------------------------
                mas[i][37] = static_cast<char>(176); // выводит по периметру
                mas[0][j] = static_cast<char>(176);//
                mas[22][j] = static_cast<char>(176);//-----------------------
            }
        }

        mas[1][vhid] = ' ';	  //пустое место перед входом
        mas[21][vuhid] = ' '; //пустое место перед выходом
        mas[22][vuhid] = ' '; //выход

        for (int i = 0; i < 23; i++)
        {
            for (int j = 0; j < 38; j++)
            {
                cout << mas[i][j];
            }
            cout << endl;
        }

        int x = vhid, y = 0, stepX = 0, stepY = 0;//вход
        do{
            do
            {
                gotoxy(x, y);
                cout << " ";
                x = x + stepX;
                y = y + stepY;
                gotoxy(x, y);
                cout << "O";
                Sleep(200);
                break;

            } while (!_kbhit());

            _getch();
            int c = (_getch());
            switch (c)
            {
            case 72:
                if (mas[y - 1][x] != static_cast<char>(176)) //проверка стенки сверху
                {
                    stepY = -1;
                    stepX = 0;
                    break;
                }
                else
                {
                    stepX = 0;
                    stepY = 0;
                    break;
                }
            case 77:
                if (mas[y][x + 1] != static_cast<char>(176))//проверка стенки справа
                {
                    stepY = 0;
                    stepX = 1;
                    break;
                }
                else
                {
                    stepX = 0;
                    stepY = 0;
                    break;
                }
            case 80:
                if (mas[y + 1][x] != static_cast<char>(176))//проверка стенки снизу
                {
                    stepY = 1;
                    stepX = 0;
                    break;
                }
                else
                {
                    stepX = 0;
                    stepY = 0;
                    break;
                }
            case 75:
                if (mas[y][x - 1] != static_cast<char>(176))//проверка стенки слева
                {
                    stepY = 0;
                    stepX = -1;
                    break;
                }
                else
                {
                    stepX = 0;
                    stepY = 0;
                    break;
                }
            case 27:return;
            }
        } while (y != 22);
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tVu vugralu!\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\tZigratu she raz, natusnitj - 1!\n\n\n\n\n\n\n\n\n\n";
        cin >> t;
    }

    system("pause");
}


