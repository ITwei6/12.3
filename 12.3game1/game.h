#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3//3行
#define COL 3//3列
void Init_board(char board[ROW][COL], int cow,int col);//函数声明
void Print_board(char board[ROW][COL], int cow, int col);
void Player_move(char board[ROW][COL], int cow, int col);
void Computer_move(char board[ROW][COL], int cow, int col);
char is_win(char board[ROW][COL], int cow, int col);