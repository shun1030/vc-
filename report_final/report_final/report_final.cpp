// report_final.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
#include "stdafx.h"
#include "string.h"
#include "Setting.h"
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


#define BUFFSIZE 1024

void display();
bool isHit(int MinoX, int MinoY, int MinoType, int MinoAngle);
void resetMino();
int gameClear();


int main()
{

//フィールド(左右の壁)
	for (int i = 0; i < FIELD_HEIGHT; i++)
	{
		field[i][0] = 1; //右の壁
		field[i][FIELD_WIDTH - 1] = 1; // 左の壁
	}
//フィールド(下の壁)
	for (int i = 0; i < FIELD_WIDTH; ++i)
	{
		field[FIELD_HEIGHT - 1][i] = 1; //下の壁
	}

	resetMino();

	time_t t = time(NULL);
	while (1)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 0x50: //↓キーでミノを下に1マス動かす
				if (!isHit(mino.x, mino.y + 1, mino.type, mino.angle))
				{
					mino.y++;
				}
				break;

			case 0x4B: //←キーでミノを1マス左に動かす
				if (!isHit(mino.x - 1, mino.y, mino.type, mino.angle))
				{
					mino.x--;
				}
				break;

			case 0x4D: //→キーでミノを1マス右に動かす
				if (!isHit(mino.x + 1, mino.y, mino.type, mino.angle))
				{
					mino.x++;
				}
				break;

			case 0x20: //スぺースキーでミノを90度回転させる
				if (!isHit(mino.x, mino.y, mino.type, (mino.angle + 1) % MINO_ANGLE_MAX))
				{
					mino.angle = (mino.angle + 1) % MINO_ANGLE_MAX;
				}
				break;
			}
			display();
		}
//1秒ごとにミノを1マス下に動かす
		if (time(NULL) != t)
		{
			t = time(NULL);

			if (isHit(mino.x, mino.y + 1, mino.type, mino.angle))
			{
				for (int i = 0; i < MINO_HEIGHT; ++i)
				{
					for (int j = 0; j < MINO_WIDTH; ++j)
					{
						field[mino.y + i][mino.x + j] |= minoShape[mino.type][mino.angle][i][j];
					}
				}

//1列埋まったらその列を削除し、1列ずらす
				int cnt = 0;
				for (int i = 0; i < FIELD_HEIGHT - 1; ++i)
				{
					bool isLineFilled = true;
					for (int j = 1; j < FIELD_WIDTH - 1; ++j)
					{
						if (field[i][j] != 1)
						{
							isLineFilled = false;
						}
					}

					if (isLineFilled == true ) 
					{
						for (int j = i; j > 0; --j)
						{
							memcpy(field[j], field[j - 1], FIELD_WIDTH); //空いた1列を埋めるために1マスずらす
						}
						cnt += 1;
					}
				}
				//カウントが2になったらゲームクリア
				if (cnt == 2) {
					gameClear();
				}

				resetMino();
			}
			else
			{
				mino.y++;
			}

			display();
		}
	}

	_getch();
	return 0;
}

void display()
{
	memcpy(displayBuffer, field, sizeof(field));

	for (int i = 0; i < MINO_HEIGHT; ++i)
	{
		for (int j = 0; j < MINO_WIDTH; ++j)
		{
			displayBuffer[mino.y + i][mino.x + j] |= minoShape[mino.type][mino.angle][i][j];
		}
	}

	system("cls");
	//描画
	for (int i = 0; i < FIELD_HEIGHT; ++i){
		for (int j = 0; j < FIELD_WIDTH; ++j){
			if (displayBuffer[i][j] == 1){
				printf("■");
			}
			else
			{
			printf("　");
			}
		}
		printf("\n");
	}
}

//壁を識別するための関数
bool isHit(int MinoX, int MinoY, int MinoType, int MinoAngle)
{
	for (int i = 0; i < MINO_HEIGHT; ++i)
	{
		for (int j = 0; j < MINO_WIDTH; ++j)
		{
			if (minoShape[MinoType][MinoAngle][i][j] && field[MinoY + i][MinoX + j])
			{
				return true;
			}
		}
	}
	return false;
}

void resetMino() {

	mino.x = 5;
	mino.y = 0;
	mino.type = rand() % MINO_TYPE_MAX;
	mino.angle = rand() % MINO_ANGLE_MAX;
}

int gameClear() {

	display();
	printf("あと1ライン!\a");
	_getch();

	//ファイルオープン
	FILE* fp;
	errno_t error = fopen_s(&fp, "result.txt", "w");
	if (error != 0)  
		return false;

	//ファイル書き込み
	char s_buf[BUFFSIZE];
	sprintf_s(s_buf, "2ライン消すことに成功しました！");
	fputs(s_buf, fp);

	//ファイルクローズ
	fclose(fp);
	exit(0);
}


