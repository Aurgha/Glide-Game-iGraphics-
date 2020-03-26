#define _CRT_SECURE_NO_WARNINGS
#include "iGraphics.h"
#include<stdio.h>


#define screenheight  600
#define screenwidth  1000
#define speed 100
#define glide_height 70
#define glide_width 80
#define bird_height 30
#define bird_width 40

int Hscore = 0;
int readscr;
int count = 1;
bool musicOn = true;
int bx = 800;
int by = 300;
int gx = 80;
int gy = 400;
int count1 = 0;
int level = 1;
int point = 0;
int savedPoint = 0;
int count2 = 0;
int life = 3;
int bird_index = 0;

char birdimage[5][20] = { "image\\bird1.bmp", "image\\bird2.bmp","image\\bird1.bmp", "image\\bird3.bmp", "image\\bird1.bmp" };

char backgroundimage[10][20] = {"image\\1.bmp", "image\\2.bmp", "image\\3.bmp", "image\\4.bmp", "image\\5.bmp", "image\\6.bmp", "image\\7.bmp", "image\\8.bmp", "image\\9.bmp", "image\\10.bmp" };


struct background{
	int x;
	int y;
};
background bg[10];
struct bird{
	int bird_x = 900;
	int bird_y = rand() % (screenheight - bird_height);
	int birdspeed = 2;
	int imageheight = 40;
	int imagewidth = 75;
	void setposition(){
		if (bird_x <= 0){
			bird_x = screenwidth - bird_width;
			bird_y = rand() % (screenheight - bird_height);
		}
		else
			bird_x -= birdspeed;
	}
		void clash()
		{
			if (gy <= bird_y + bird_height && gy >= bird_y - glide_height)
			{
				if (gx + glide_width >= bird_x && gx + glide_width <= bird_x + bird_width + glide_width)
				{
					count1++;
					point -= 10;
					life -= 1;
					bird_x = screenwidth;
						bird_y = rand() % (screenheight - bird_height);

				}
			}		
	}
}bird1, bird2, bird3,bird4,bird5;

void GameOn()
{
	iShowBMP(0, 200, "image\\sky.bmp");
	for (int i = 0; i < 10; i++){
		iShowBMP2(bg[i].x, bg[i].y, backgroundimage[i],0);

	}
	iShowBMP2(gx, gy, "image\\glide.bmp",0);
	gy -= 2;
	bird1.setposition();
	bird2.setposition();
	bird3.setposition();
	bird4.setposition();
	bird5.setposition();
	iShowBMP2(bird1.bird_x, bird1.bird_y, birdimage[bird_index], 0);
	iShowBMP2(bird2.bird_x, bird2.bird_y, birdimage[bird_index], 0);
	iShowBMP2(bird3.bird_x, bird3.bird_y, birdimage[bird_index], 0);
	iShowBMP2(bird4.bird_x, bird4.bird_y, birdimage[bird_index], 0);
	iShowBMP2(bird5.bird_x, bird5.bird_y, birdimage[bird_index], 0);
	bird1.clash();
	bird2.clash();
	bird3.clash();
	bird4.clash();
	bird5.clash();
	if (gy <= 0 || gy >= (screenheight - glide_height))
		count2 = 1;


}

void GameOver()
{
	iShowBMP(0, 0, "image\\gameover.bmp");
	iShowBMP2(40, 420, "image\\pressA.bmp", 0);
	FILE *fread, *fwrite;
	fread = fopen("score.txt", "r");
	fscanf(fread, "%d", &Hscore);
	fclose(fread);
	if (Hscore < point)
	{	
		fwrite = fopen("score.txt", "w");
		fprintf(fwrite,"%d",point);
		fclose(fwrite);
	}
}

void reset()
{
	 gx = 80;
	 gy = 450;
	 bird1.bird_x = 850;
	 bird2.bird_x = 850;
	 bird3.bird_x = 850;
	 bird4.bird_x = 850;
	 bird5.bird_x = 850;
	bird1.birdspeed = 4;
	 bird2.birdspeed = 3;
	 bird3.birdspeed = 5;
	 bird4.birdspeed = 4;
	 point = 0;
	 life = 3;
	 level = 1;
}
void level2()
{
	bird1.birdspeed = 5;
		bird2.birdspeed = 7;
		bird3.birdspeed = 10;
		bird4.birdspeed = 8;
		bird5.birdspeed = 5;
}
void level3()
{
	bird1.birdspeed = 10;
	bird2.birdspeed = 7;
	bird3.birdspeed = 8;
	bird4.birdspeed = 11;
	bird5.birdspeed = 9;
}

void sidebar()
{
	iSetColor(255, 255, 255);
	iRectangle(1010, 400, 180, 150);
	iText(1020, 520, "LIFE:", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255, 255, 255);
	iRectangle(1010, 250, 180, 150);
	iText(1020, 370, "SCORE :", GLUT_BITMAP_TIMES_ROMAN_24);
	iRectangle(1010, 50, 180, 150);
	iText(1020, 170, "LEVEL", GLUT_BITMAP_TIMES_ROMAN_24);
	if (life == 3)
	{
		iSetColor(255, 0, 0);
		iFilledCircle(1030, 490, 10, 100);
		iFilledCircle(1060, 490, 10, 100);
		iFilledCircle(1090, 490, 10, 100);
	}
	if (life==2)
	{
		iSetColor(255, 0, 0);
		iFilledCircle(1030, 490, 10, 100);
		iFilledCircle(1060, 490, 10, 100);
		iSetColor(0, 0, 0);
		iFilledCircle(1090, 490, 10, 100);
	}
	if (life==1)
	{
		iSetColor(255, 0, 0);
		iFilledCircle(1030, 490, 10, 100);
		iSetColor(0, 0, 0);
		iFilledCircle(1060, 490, 10, 100);
		iFilledCircle(1090, 490, 10, 100);
	}
}
void menu(){
	iShowBMP(0,0,"image\\menu.bmp");
	iSetColor(23, 179, 206);
	iFilledRectangle(30, 100, 195, 40);
	iFilledRectangle(30, 180, 195, 40);
	iFilledRectangle(30, 260, 195, 40);
	iFilledRectangle(30, 340, 195, 40);
	iSetColor(0, 0, 0);
	iText(100, 112, "EXIT",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(60, 190, "HIGH SCORE", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(40, 270, "INSTRUCTIONS", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(89, 350, "START", GLUT_BITMAP_TIMES_ROMAN_24);
	

}

void instruction(){
	iShowBMP(0, 0, "image\\instruction.bmp");
	iSetColor(23, 179, 215);
	iFilledRectangle(490, 50, 180, 40);
	iSetColor(0,0,0);
	iText(538, 63, "BACK",GLUT_BITMAP_TIMES_ROMAN_24);
}
void highscore()
{
	FILE *readscore;
	readscore = fopen("score.txt", "r");
	fscanf(readscore, "%d", &readscr);
	fclose(readscore);
	iShowBMP(0, 0, "image\\highscore.bmp");
	iSetColor(23, 179, 215);
	iFilledRectangle(490, 50, 160, 40);
	iSetColor(0, 0, 0);
	iText(538, 63, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);
	char str2[30];
	sprintf_s(str2, 10, "%d", readscr);
	iText(650, 350, str2,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(450, 350, "HIGHSCORE: ", GLUT_BITMAP_TIMES_ROMAN_24);

}
void bird_position_change()
{
	bird_index++;
	if (bird_index >= 5)
		bird_index = 0;
}
void score_change()
{
	if (count==2)
		point += 5;
}
void saveGame()
{
	FILE *w;
	w = fopen("savedlevel.txt","w");
	fprintf(w,"%d",point);
	fclose(w);
	

}

void resume()
{
	FILE *r;
	r = fopen("savedlevel.txt", "r");
	fprintf(r, "%d", &savedPoint);
	fclose(r);
	point = savedPoint;
}
void iDraw()
{
	iClear();
	glutSetCursor(GLUT_CURSOR_CROSSHAIR);
	if( (count1==0 || count1==1|| count1==2) && count2==0)
		{
			if (count == 1)
			{
				menu();
			}
			else if (count == 3)
			{
				instruction();
			}
			else if (count == 4)
				highscore();
			else 
			{
				GameOn();
				if (point == 45)
				{
					level = 2;
					level2();
				}
				if (point == 90)
				{
					level = 3;
					level3();
				}
				sidebar();
				char str[40];
				iSetColor(255, 255, 255);
				sprintf_s(str, 10, "%d", point);
				iText(1020, 270, str, GLUT_BITMAP_HELVETICA_18);
				char str1[40];
				iSetColor(255, 255, 255);
				sprintf_s(str1, 10, "%d", level);
				iText(1020, 60, str1, GLUT_BITMAP_HELVETICA_18);
			}
		}
		else 
		{
			GameOver();
			reset();
		}
	}

void iMouseMove(int mx, int my)
{
	
}


void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (mx > 30 && mx < 190 && my>340 && my < 380)
			count = 2;
		else if (mx > 30 && mx < 190 && my>260 && my < 300)
			count = 3;
		else if (mx>30 && mx < 190 && my>180 && my < 220)
			count = 4;
		else if (mx>30 && mx < 190 && my>100 && my < 140)
			exit(0);
		if (mx > 490 && mx < 650 && my>50 && my< 90)
			count = 1;
	}
	
}


void iKeyboard(unsigned char key)
{

	if (key == 'a' || key == 'A')
    {
	count =1;
	count1 = 0;
	count2 = 0;
	}
	if (key == 's' || key == 'S')
	{
		saveGame();
	}
	if (key == 'r' || key == 'R')
	{
		resume();
	}

}


void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{ 
		exit(0);
	}
	if (key == GLUT_KEY_UP)
	{
		gy += 30;
	}
} 
void setAll(){
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
	bg[i].y = 0;
	bg[i].x = sum;
		sum += 100;
	}
}
void change(){
	for (int i = 0; i < 10; i++){
		bg[i].x -= speed;
		if (bg[i].x < 0)

		{
			bg[i].x = screenwidth - 100;
			bx -= 3;
		}
	}
}


int main()
{ 
	srand((unsigned)time(NULL));
	setAll();
	bird1.birdspeed = 4;
	bird2.birdspeed = 3;
	bird3.birdspeed = 5;
	bird4.birdspeed = 4;
	iSetTimer(200, change);
	iSetTimer(2000, score_change);
	iSetTimer(250, bird_position_change);

	if (musicOn)
		PlaySound("demo.wav", NULL, SND_LOOP | SND_ASYNC);

	iInitialize(screenwidth+200,screenheight, "glide");
	return 0;
}