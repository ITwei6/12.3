#include "game.h"
#include <stdio.h>
void Init_board(char board[ROW][COL], int row, int col)
{
	int i;
	for (i = 0;i < row;i++)
	{
		int j;
		for (j = 0;j < col;j++)
		{
			board[i][j] = ' ';
		}
	}
}
void Print_board(char board[ROW][COL], int cow, int col)
{
	int i;
	for (i = 0;i < cow;i++)
	{
		int j;
		for (j = 0;j < col;j++)
		{
			printf(" %c ",board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < cow - 1)
		{
			for (j = 0;j < col;j++)
			{

				printf("___");
				if (j < col - 1)
				{
					printf("|");
				}

			}
		}
		printf("\n");
	}
}
void Player_move(char board[ROW][COL], int row, int col)//玩家先开始下棋；
{
	while (1)
	{
		//首先要判断下棋是否合法；范围在哪？
		printf("玩家下棋\n");
		int x, y;
		scanf("%d%d", &x, &y);

		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//还要判断下棋的地方有没有地方可以下。
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("该坐标已被占用请重新输入\n");
		}
		else
			printf("坐标非法\n");

    }

}
void Computer_move(char board[ROW][COL], int cow, int col)//电脑下棋，也要判断合法性；
{
	while (1)
	{
		printf("电脑下棋\n");
		int x, y;
		x = rand() % cow;//x只能是0 1 2 
		y = rand() % col;//y也只能是0 1 2；
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
	

}
char is_full(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char is_win(char board[ROW][COL], int cow, int col)
{
	int i;
	for (i = 0;i < cow;i++)
	{//判断三行是否相同；
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}

	}
	//判断三列是否相同；
	int j;
	for (j = 0;j < col;j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	//再判断对角线是否相同；
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (is_full(board, ROW, COL) == 1)
	{
		return 'Q';
	}
	return 'C';
}


