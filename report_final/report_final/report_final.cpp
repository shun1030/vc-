// report_final.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
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

//�t�B�[���h(���E�̕�)
	for (int i = 0; i < FIELD_HEIGHT; i++)
	{
		field[i][0] = 1; //�E�̕�
		field[i][FIELD_WIDTH - 1] = 1; // ���̕�
	}
//�t�B�[���h(���̕�)
	for (int i = 0; i < FIELD_WIDTH; ++i)
	{
		field[FIELD_HEIGHT - 1][i] = 1; //���̕�
	}

	resetMino();

	time_t t = time(NULL);
	while (1)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 0x50: //���L�[�Ń~�m������1�}�X������
				if (!isHit(mino.x, mino.y + 1, mino.type, mino.angle))
				{
					mino.y++;
				}
				break;

			case 0x4B: //���L�[�Ń~�m��1�}�X���ɓ�����
				if (!isHit(mino.x - 1, mino.y, mino.type, mino.angle))
				{
					mino.x--;
				}
				break;

			case 0x4D: //���L�[�Ń~�m��1�}�X�E�ɓ�����
				if (!isHit(mino.x + 1, mino.y, mino.type, mino.angle))
				{
					mino.x++;
				}
				break;

			case 0x20: //�X�؁[�X�L�[�Ń~�m��90�x��]������
				if (!isHit(mino.x, mino.y, mino.type, (mino.angle + 1) % MINO_ANGLE_MAX))
				{
					mino.angle = (mino.angle + 1) % MINO_ANGLE_MAX;
				}
				break;
			}
			display();
		}
//1�b���ƂɃ~�m��1�}�X���ɓ�����
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

//1�񖄂܂����炻�̗���폜���A1�񂸂炷
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
							memcpy(field[j], field[j - 1], FIELD_WIDTH); //�󂢂�1��𖄂߂邽�߂�1�}�X���炷
						}
						cnt += 1;
					}
				}
				//�J�E���g��2�ɂȂ�����Q�[���N���A
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
	//�`��
	for (int i = 0; i < FIELD_HEIGHT; ++i){
		for (int j = 0; j < FIELD_WIDTH; ++j){
			if (displayBuffer[i][j] == 1){
				printf("��");
			}
			else
			{
			printf("�@");
			}
		}
		printf("\n");
	}
}

//�ǂ����ʂ��邽�߂̊֐�
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
	printf("����1���C��!\a");
	_getch();

	//�t�@�C���I�[�v��
	FILE* fp;
	errno_t error = fopen_s(&fp, "result.txt", "w");
	if (error != 0)  
		return false;

	//�t�@�C����������
	char s_buf[BUFFSIZE];
	sprintf_s(s_buf, "2���C���������Ƃɐ������܂����I");
	fputs(s_buf, fp);

	//�t�@�C���N���[�Y
	fclose(fp);
	exit(0);
}


