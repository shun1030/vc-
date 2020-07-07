#pragma once

struct Mino {
	int x, y;
	int type, angle;
}mino;


#define FIELD_WIDTH 12
#define FIELD_HEIGHT 22
#define MINO_WIDTH 4
#define MINO_HEIGHT 4


//ミノの形
enum {
		MINO_I,
		MINO_O,
		MINO_S,
		MINO_Z,
		MINO_J,
		MINO_L,
		MINO_T,
		MINO_TYPE_MAX
	};

//ミノの向き
enum {
		MINO_ANGLE_0,
		MINO_ANGLE90,
		MINO_ANGLE_180,
		MINO_ANGLE_270,
		MINO_ANGLE_MAX
	};

char minoShape[MINO_TYPE_MAX][MINO_ANGLE_MAX][MINO_HEIGHT][MINO_WIDTH] = {

		//MINO_I
		{
			//MINO_ANGLE_0,
			{
				0, 1, 0, 0,
				0, 1, 0, 0,
				0, 1, 0, 0,
				0, 1, 0, 0
			},
		//MINO_ANGLE90
			{
				0, 0, 0, 0,
				0, 0, 0, 0,
				1, 1, 1, 1,
				0, 0, 0, 0
			},

		//MINO_ANGLE_180,
			{
				0, 0, 1, 0,
				0, 0, 1, 0,
				0, 0, 1, 0,
				0, 0, 1, 0
			},
		//MINO_ANGLE_270
			{
				0, 0, 0, 0,
				1, 1, 1, 1,
				0, 0, 0, 0,
				0, 0, 0, 0
			},
		},

		//MINO_O
		{
			//MINO_ANGLE_0,
			{
				0, 0, 0, 0,
				0, 1, 1, 0,
				0, 1, 1, 0,
				0, 0, 0, 0
			},
		//MINO_ANGLE90
			{
				0, 0, 0, 0,
				0, 0, 0, 0,
				0, 0, 0, 0,
				0, 0, 0, 0
			},

		//MINO_ANGLE_180,
			{
				0, 0, 0, 0,
				0, 1, 1, 0,
				0, 1, 1, 0,
				0, 0, 0, 0
			},
		//MINO_ANGLE_270
			{
				0, 0, 0, 0,
				0, 1, 1, 0,
				0, 1, 1, 0,
				0, 0, 0, 0
			},
		},

		//MINO_S
		{
			//MINO_ANGLE_0,
			{
				0, 0, 0, 0,
				0, 1, 1, 0,
				1, 1, 0, 0,
				0, 0, 0, 0
			},
		//MINO_ANGLE90
			{
				0, 0, 0, 0,
				0, 1, 0, 0,
				0, 1, 1, 0,
				0, 0, 1, 0
			},

		//MINO_ANGLE_180,
			{
				0, 0, 0, 0,
				0, 0, 1, 1,
				0, 1, 1, 0,
				0, 0, 0, 0
			},
		//MINO_ANGLE_270
			{
				0, 1, 0, 0,
				0, 1, 1, 0,
				0, 0, 1, 0,
				0, 0, 0, 0
			},
		},
		//MINO_Z
		{
			//MINO_ANGLE_0,
			{
				0, 0, 0, 0,
				1, 1, 0, 0,
				0, 1, 1, 0,
				0, 0, 0, 0
			},
		//MINO_ANGLE90
			{
				0, 0, 0, 0,
				0, 0, 1, 0,
				0, 1, 1, 0,
				0, 1, 0, 0
			},

		//MINO_ANGLE_180,
			{
				0, 0, 0, 0,
				0, 1, 1, 0,
				0, 0, 1, 1,
				0, 0, 0, 0
			},
		//MINO_ANGLE_270
			{
				0, 0, 1, 0,
				0, 1, 1, 0,
				0, 1, 0, 0,
				0, 0, 0, 0
			},
		},
		//MINO_J
		{
			//MINO_ANGLE_0,
			{
				0, 0, 0, 0,
				0, 0, 1, 0,
				0, 0, 1, 0,
				0, 1, 1, 0
			},
		//MINO_ANGLE90
			{
				0, 0, 0, 0,
				0, 1, 1, 1,
				0, 0, 0, 1,
				0, 0, 0, 0
			},

		//MINO_ANGLE_180,
			{
				0, 1, 1, 0,
				0, 1, 0, 0,
				0, 1, 0, 0,
				0, 0, 0, 0
			},
		//MINO_ANGLE_270
			{
				0, 0, 0, 0,
				1, 0, 0, 0,
				1, 1, 1, 0,
				0, 0, 0, 0
			},
		},
		//MINO_L
		{
			//MINO_ANGLE_0,
			{
				0, 0, 0, 0,
				0, 1, 0, 0,
				0, 1, 0, 0,
				0, 1, 1, 0
			},
		//MINO_ANGLE90
			{
				0, 0, 0, 0,
				0, 0, 0, 1,
				0, 1, 1, 1,
				0, 0, 0, 0
			},

		//MINO_ANGLE_180,
			{
				0, 1, 1, 0,
				0, 0, 1, 0,
				0, 0, 1, 0,
				0, 0, 0, 0
			},

		//MINO_ANGLE_270
			{
				0, 0, 0, 0,
				1, 1, 1, 0,
				1, 0, 0, 0,
				0, 0, 0, 0
			},
		},
		//MINO_T
		{

			//MINO_ANGLE_0,
			{
				1, 1, 1, 0,
				0, 1, 0, 0,
				0, 0, 0, 0,
				0, 0, 0, 0
			},
		//MINO_ANGLE90
			{
				0, 0, 0, 0,
				1, 0, 0, 0,
				1, 1, 0, 0,
				1, 0, 0, 0
			},

		//MINO_ANGLE_180,
			{
				0, 0, 0, 0,
				0, 0, 0, 0,
				0, 0, 1, 0,
				0, 1, 1, 1
			},
		//MINO_ANGLE_270
			{
				0, 0, 0, 1,
				0, 0, 1, 1,
				0, 0, 0, 1,
				0, 0, 0, 0
			}
		}
	};

	char field[FIELD_HEIGHT][FIELD_WIDTH];
	char displayBuffer[FIELD_HEIGHT][FIELD_WIDTH];


