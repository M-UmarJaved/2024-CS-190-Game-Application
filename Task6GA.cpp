#include <iostream>
#include<windows.h>
using namespace std;
void printMaze();
void gotoxy(int x, int y);
void playerCircle();
char getCharAtxy(short int x, short int y);

// All Functions of Enemies
int eLX = 30, eLY = 28;
void printLeftEnemy();
void eraseLeftEnemy();

int eRX = 157, eRY = 10;
void printRightEnemy();
void eraseRightEnemy();

void moveEnemies();

// All Functions of Player
int pX = 98, pY = 15;
void printPlayer();
void erasePlayer();
void movePlayerLeft();
void movePlayerRight();
void playerMovementControl();


main()
{
    // coordinates for Maze
    int x = 6, y = 2;
    system("cls");
    printMaze();
    gotoxy(x,y);
    
    playerCircle();
    printRightEnemy();
    printLeftEnemy();
    printPlayer();
    while(true)
    {
        if(GetAsyncKeyState(VK_RIGHT))
        {
            movePlayerRight();
        }
        if(GetAsyncKeyState(VK_LEFT))
        {
            movePlayerLeft();
        }
        moveEnemies();
        Sleep(150);
    } 
    
    //coordinates for last line
    gotoxy(1,60);
}


void printLeftEnemy()
{
    gotoxy(eLX, eLY);
    cout<<"Enemy";

}
void eraseLeftEnemy()
{
    gotoxy(eLX,eLY);
    cout<<"     ";

}
void printRightEnemy()
{
    gotoxy(eRX, eRY);
    cout<<"Enemy";

}
void eraseRightEnemy()
{
    gotoxy(eRX,eRY);
    cout<<"     ";

}

// For Enemy Movement
void moveEnemies()
{
    eraseLeftEnemy(), eraseRightEnemy();
    eLY = eLY - 1, eRY = eRY + 1;
    if(eLY == 10 || eRY == 28)
    {
        while(true)
        {   
            if(GetAsyncKeyState(VK_RIGHT)) // For Player movement when enemies are chaging direction
            {
                movePlayerRight();
            }
            if(GetAsyncKeyState(VK_LEFT))
            {
                movePlayerLeft();
            }
            if(eLY == 28 || eRY == 10)
            {
                break;
            }   
            eraseLeftEnemy(), eraseRightEnemy();
            eLY = eLY + 1, eRY = eRY - 1;
            printLeftEnemy(), printRightEnemy();
            Sleep(150);
            }
    }
    printLeftEnemy(), printRightEnemy();
    
}


void printPlayer()
{
    gotoxy(pX,pY);
    cout<<"P";
}
void erasePlayer()
{
    gotoxy(pX,pY);
    cout<<" ";
}

void movePlayerLeft()
{
    erasePlayer();
    pX = pX - 1;
    printPlayer();
}
void movePlayerRight()
{
    erasePlayer();
    pX = pX + 1;
    printPlayer();
}

void playerCircle()
{
    int x = 90, y = 16;

    gotoxy(x, y + 1);
    cout<< "**************";
    gotoxy(x, y + 2);
    cout<< "**************";    
    gotoxy(x, y + 3);
    cout<< "**************";    
    gotoxy(x, y + 4);
    cout<< "**************";    
    gotoxy(x, y + 5);
    cout<< "**************";    
    gotoxy(x,y + 6);
    cout<< "**************";
}



void printMaze()
{
    system("color 0B");
    cout<<"                                           #############################################################################################################                                        "<< endl;
    cout<<"                                        ##                                                                                                               ##                                    "<< endl;
    cout<<"                                     ##                                                                                                                     ##                                 "<< endl;
    cout<<"                                  ##                                                                                                                           ##                              "<< endl;
    cout<<"                               ##                                                                                                                                 ##                           "<< endl;
    cout<<"                            ##                                                                                                                                       ##                        "<< endl;
    cout<<"                         ##                                                                                                                                             ##                     "<< endl;
    cout<<"                      ##                                                                                                                                                   ##                  "<< endl;
    cout<<"                    ##                                                                                                                                                       ##                "<< endl;
    cout<<"                  ##                                                                                                                                                           ##              "<< endl;
    cout<<"                ##                                                                                                                                                               ##            "<< endl;
    cout<<"              ##                                                                                                                                                                   ##          "<< endl;
    cout<<"            ##                                                                                                                                                                       ##        "<< endl;
    cout<<"          ##                                                                                                                                                                           ##      "<< endl;
    cout<<"         ##                                                                                                                                                                             ##     "<< endl;
    cout<<"        ##                                                                                                                                                                               ##    "<< endl;
    cout<<"       ##                                                                                                                                                                                 ##   "<< endl;
    cout<<"      ##                                                                                                                                                                                   ##  "<< endl;
    cout<<"      ##                                                                                                                                                                                   ##  "<< endl;
    cout<<"      ##                                                                                                                                                                                   ##  "<< endl;
    cout<<"      ##                                                                                                                                                                                   ##  "<< endl;
    cout<<"      ##                                                                                                                                                                                   ##  "<< endl;
    cout<<"       ##                                                                                                                                                                                 ##   "<< endl;
    cout<<"        ##                                                                                                                                                                               ##    "<< endl;
    cout<<"         ##                                                                                                                                                                             ##     "<< endl;
    cout<<"          ##                                                                                                                                                                           ##      "<< endl;
    cout<<"            ##                                                                                                                                                                       ##        "<< endl;
    cout<<"              ##                                                                                                                                                                   ##          "<< endl;
    cout<<"                ##                                                                                                                                                               ##            "<< endl;
    cout<<"                  ##                                                                                                                                                           ##              "<< endl;
    cout<<"                    ##                                                                                                                                                       ##                "<< endl;
    cout<<"                      ##                                                                                                                                                   ##                  "<< endl;
    cout<<"                         ##                                                                                                                                             ##                     "<< endl;
    cout<<"                            ##                                                                                                                                       ##                        "<< endl;
    cout<<"                               ##                                                                                                                                 ##                           "<< endl;
    cout<<"                                  ##                                                                                                                           ##                              "<< endl;
    cout<<"                                     ##                                                                                                                     ##                                 "<< endl;
    cout<<"                                        ##                                                                                                               ##                                    "<< endl;
    cout<<"                                           #############################################################################################################                                       "<< endl;

}
    char getCharAtxy(short int x, short int y)

{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar: ' ';

}


void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

    
