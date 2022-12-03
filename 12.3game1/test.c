#define  _CRT_SECURE_NO_WARNINGS

#include "game.h"

void game()
{
	int ret;
	//三子棋就是一个二维数组；而且一开始这个数组里面什么都没有，是空白，要先进行初始化；
	char board[ROW][COL];
	Init_board(board, ROW, COL);//初始化
	Print_board(board, ROW, COL);//打印棋盘
	while (1)
	{
		Player_move(board, ROW, COL);//玩家开始下棋；
		Print_board(board, ROW, COL);//每下完棋都有可能会英所以需要判断一下
		//判断输赢；
		ret =is_win(board, ROW, COL);
			if (ret != 'C')
			{
				break;
			}
		Computer_move(board, ROW, COL);//电脑开始下棋；
		Print_board(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret = 'C')
		{
			break;
		}

	}
	if (ret == '#')
	{
		printf("电脑赢了\n");
	}
	else if (ret == '*')
		printf("玩家赢了\n");
	else if (ret == 'Q')
		printf("平局\n");



}
void meun()
{
	printf("************************\n");
	printf("******   1.play   ******\n");
	printf("******   0.exit   ******\n");
	printf("************************\n");
}
void test()
{   
	int intput;
	srand((unsigned int)time(NULL));
	
	do
	{
		meun();
		printf("请输入：");
		scanf("%d", &intput);
		switch(intput)
		{
		case 1:  game();
			break;
		case 0:  printf("退出游戏\n");
			break;
		default: printf("输入错误\n");
			break;
		}

	} while (intput);
}
int main()
{
	test();
	return 0;
}