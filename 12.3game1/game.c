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
void Player_move(char board[ROW][COL], int row, int col)//����ȿ�ʼ���壻
{
	while (1)
	{
		//����Ҫ�ж������Ƿ�Ϸ�����Χ���ģ�
		printf("�������\n");
		int x, y;
		scanf("%d%d", &x, &y);

		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//��Ҫ�ж�����ĵط���û�еط������¡�
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("�������ѱ�ռ������������\n");
		}
		else
			printf("����Ƿ�\n");

    }

}
void Computer_move(char board[ROW][COL], int cow, int col)//�������壬ҲҪ�жϺϷ��ԣ�
{
	while (1)
	{
		printf("��������\n");
		int x, y;
		x = rand() % cow;//xֻ����0 1 2 
		y = rand() % col;//yҲֻ����0 1 2��
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
	{//�ж������Ƿ���ͬ��
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}

	}
	//�ж������Ƿ���ͬ��
	int j;
	for (j = 0;j < col;j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	//���ж϶Խ����Ƿ���ͬ��
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


