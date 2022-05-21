#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <time.h>
#include <stack>
#include <algorithm>// min, max
#include <thread>
#include <chrono>

#define Size 56
using namespace sf;
using namespace std;


typedef struct Piece
{
    Sprite s;
    int index, cost;
};

class GameManager
{
public:
    Piece f[33]; //mang luu cac quan co
    Vector2f positiveMove[32];//vi tri cac nuoc co the di chuyen
    int positiveCount;// so nuoc co the di chuyen
    stack<Vector2f> posS;//luu tru vi tri cac nuoc di
    stack<int> nS;//luu tru index cua quan di
    stack<int> nBiS; // luu tru index cua quan bi an

    void move(int n, Vector2f oldPos, Vector2f newPos);//ham danh co
    void Undo();//ham quay lai
    void Create();
    void Play(RenderWindow& window);// choi: moi thao tac o day

    void PositiveRook(int n, int x, int y, int grid[9][9]);//tim cac nuoc co the di cua Quan Xe
    void PositiveBishop(int n, int x, int y, int grid[9][9]);
    void PositiveKnight(int n, int x, int y, int grid[9][9]);
    void PositiveKing(int n, int x, int y, int grid[9][9]);
    void PositivePawn(int n, int x, int y, int grid[9][9]);

    // Hau = Xe + tuong => ko c� func tim positive hau

    void IncreasePositive(int i, int j);//tang so nuoc co the di
    void PositiveMoving(int n);//tim cac nuoc co the di ung voi index n
    //AI
    int CostMove();//gia tri diem cua toan bo ban co ung voi gia tri moi quan
    //int Minimax(int depth,bool luot);// Chien luoc Minimax
    int Alpha_Beta(int depth, bool luot, int alpha, int beta);//cat tia alpha beta
    Vector2f getNextMove(bool luot);// tra ve nuoc di tot nhat theo chien luoc phia tren
};