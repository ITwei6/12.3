#define  _CRT_SECURE_NO_WARNINGS

#include "game.h"

void game()
{
	int ret;
	//���������һ����ά���飻����һ��ʼ�����������ʲô��û�У��ǿհף�Ҫ�Ƚ��г�ʼ����
	char board[ROW][COL];
	Init_board(board, ROW, COL);//��ʼ��
	Print_board(board, ROW, COL);//��ӡ����
	while (1)
	{
		Player_move(board, ROW, COL);//��ҿ�ʼ���壻
		Print_board(board, ROW, COL);//ÿ�����嶼�п��ܻ�Ӣ������Ҫ�ж�һ��
		//�ж���Ӯ��
		ret =is_win(board, ROW, COL);
			if (ret != 'C')
			{
				break;
			}
		Computer_move(board, ROW, COL);//���Կ�ʼ���壻
		Print_board(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret = 'C')
		{
			break;
		}

	}
	if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else if (ret == '*')
		printf("���Ӯ��\n");
	else if (ret == 'Q')
		printf("ƽ��\n");



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
		printf("�����룺");
		scanf("%d", &intput);
		switch(intput)
		{
		case 1:  game();
			break;
		case 0:  printf("�˳���Ϸ\n");
			break;
		default: printf("�������\n");
			break;
		}

	} while (intput);
}
int main()
{
	test();
	return 0;
}