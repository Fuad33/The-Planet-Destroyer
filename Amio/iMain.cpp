# include "iGraphics.h"
# include "alien.h"

//screen size diclear
#define screenWidth 1350
#define screenHight 700

//play background music 
bool musicOn = true;

//picture
char button[10][30] = { "button\\start.bmp", "button\\option.bmp", "button\\exit.bmp"};

//variable 
//struct hasan
//{
//	int bx;
//	int by;
//}fire[10];

//variable
int x = 0;
int y = 0;
int i = 0;
int j = 0;
int m = 0, n = 0;
int flag = 0;
char name[100];
int length = 0;
int fire[10] = { 0,0,0,0,0,0,0,0,0,0 };
int bx[10], by[10];
int index=0;

//name input
void rectangle()
{
	if (flag == 0)
	{
		iRectangle(580, 400, 300, 80);
		iText(630, 430, "Enter Your Name", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (flag == 1)
	{
		iSetColor(0, 255, 0);
		iRectangle(580, 400, 300, 80);
		iSetColor(255, 100, 0);
		iText(600, 430, name, GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(230, 230, 230);
	}
}

int mposx,  mposy;

//ENEMY START
void firstRound()
{
	for (j = 0; j < 10; j++)
	{	
		enemy[j].x = rand() % (screenWidth-120);
		enemy[j].y = screenHight+rand()%1500;
		//enemy[j].alienIndex = 1;
	}
}

//ENEMY MOVE
void enemyMove(){

	for (j = 0; j < 10; j++)
	enemy[j].y -= 15;
}

//SHOW ENEMY
void showEnemy(){
	for (j = 0; j < 15; j++)
		iShowBMP2(enemy[j].x, enemy[j].y, "enemy\\a.bmp", 0);
		/*	for (int j = 0; j < 15; j++)
		{
			if (fire[i].bx >= enemy[j].x && fire[i].bx<=enemy[j].x + 80 && fire[i].by>=enemy[j].y && fire[i].by<=enemy[j].y + 80)
			{
				enemy[j].alienIndex = 0;
			}
			if (enemy[j].alienIndex==1)
		}*/
}

//ENEMY START
void boom()
{
	for (j = 0; j < 10; j++)
	{
		if (enemy[j].y<=0)
		{
			enemy[j].x = 100 + rand() % screenWidth;
			enemy[j].y = screenHight + rand() % 250;
			//enemy[j].alienIndex = 1;
		}
	}

}
//FIRE MOVE
void fireMove()
{
	for (int i = 0; i < 10;i++)
	by[i] += 50;
}
//START FIRE
void startFire()
{
	for (int i = 0; i < 10;i++)
		iShowBMP2(bx[i], by[i], "enemy\\fire1.bmp", 0);
}
//MENU
void iDraw()
{
	iClear();
	//MAIN MENU
	if (i == 0)
	{
		iShowBMP(0, 0,"image\\d.bmp");
		for (int j = 0; j <= 3; j++)
		{
			iShowBMP2(250, 460, button[0], 0);
			iShowBMP2(250, 330, button[1], 0);
			iShowBMP2(250, 200, button[2], 0);
		}
	}
	//NAME INPUT PAGE
	if (i == 1)
	{	
		iShowBMP(0, 0, "image\\b.bmp");
		iShowBMP2(575, 280, "button\\back.bmp", 0);
		rectangle();
	}
	//OPTION
	if (i == 2)
	{
		iShowBMP(0, 0, "image\\c.bmp");
		iShowBMP2(50, 510, "button\\highscore.bmp", 0);
		iShowBMP2(50, 380, "button\\inst.bmp", 0);
		iShowBMP2(50, 250, "button\\about.bmp", 0);
		iShowBMP2(50, 120, "button\\back.bmp", 0);
		iShowBMP2(750, 370, "button\\soundOff.bmp", 0);
		iShowBMP2(750, 280, "button\\soundOn.bmp", 0);

	}
	//INSTRUCTION
	if (i == 3)
	{
		iShowBMP(0, 0, "image\\instruction.bmp");
		iShowBMP2(850, 520, "button\\back2.bmp", 0);
	}
	//ABOUT
	if (i == 4)
	{
		iShowBMP(0, 0, "image\\ab.bmp");
		iShowBMP2(500, 150, "button\\back.bmp", 0);
	}
	//HIGHSCORE
	if (i == 5)
	{
		iShowBMP(0, 0, "image\\e.bmp");
		iShowBMP2(10, 620, "button\\back2.bmp",0);
		iShowBMP2(400, 520, "button\\name.bmp", 0);
		iShowBMP2(740, 520, "button\\highScore2.bmp", 0);
	}
	//GAME PAGE
	if (i == 6)
	{
		iShowBMP(0, 0, "image\\a.bmp");
		iShowBMP2(10, 620, "button\\back2.bmp",0);
		boom();
		showEnemy();
		iShowBMP2(m + 500, n + 20, "robot\\robot3.bmp", 0);
		for (int i = 0; i < 10;i++)
		if (fire[i] == 1)
		{
			startFire();
		}
		
	}
}
//MOUSE MOVE
void iMouseMove(int mx, int my)
{

}

//MOUSE
void iMouse(int button, int state, int mx, int my)
{
	printf("%d %d\n", mx, my);

	if (i == 0)
	{
		if (mx >= 250 && mx <= 560 && my >= 462 && my <= 537)
		{
			i = 1;
		}
		if (mx >= 250 && mx <= 560 && my >= 331 && my <= 407)
		{
			i = 2;
		}
		if (mx >= 250 && mx <= 560 && my >= 201 && my <= 277)
		{
			exit(0);
		}
		
	}
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (i == 1)
		{
			if (mx >= 574 && mx <= 888 && my >= 282 && my <= 358)
			{
				i = 0;
			}
		}
		if (i == 2)
		{
			if (mx >= 50 && mx <= 362 && my >= 510 && my <= 587)
			{
				i = 5;
			}
			if (mx >= 50 && mx <= 362 && my >= 380 && my <= 455)
			{
				i = 3;
			}
			if (mx >= 50 && mx <= 362 && my >= 251 && my <= 327)
			{
				i = 4;
			}
			if (mx >= 50 && mx <= 362 && my >= 121 && my <= 197)
			{
				i = 0;
			}
			if (mx >= 750 && mx <= 1008 && my >= 370 && my <= 428)
			{
				if (musicOn)
				{
					musicOn = false;
					PlaySound(0, 0, 0);
				}
			}
			if (mx >= 753 && mx <= 307 && my >= 280 && my <= 336)
			{
				if (musicOn==false)
				{
					musicOn = true;
					PlaySound("music\\games.wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}
		}
		if (i == 3)
		{
			if (mx >= 850 && mx <= 1028 && my >= 521 && my <= 581)
			{
				i = 2;
			}
		}
		if (i == 4)
		{
			if (mx >= 501 && mx <= 815 && my >= 152 && my <= 224)
			{
				i = 2;
			}
		}
		if (i == 5)
		{
			if (mx >= 10 && mx <= 190 && my >= 621 && my <= 683)
			{
				i = 2;
			}
		}
		if (i == 6)
		{
			if (mx >= 10 && mx <= 188 && my >= 621 && my <= 681)
			{
				i = 1;
			}
		}
		
		if (mx >= 578 && mx <= 880 && my >= 402 && my <= 482)
		{
			flag = 1;
		}
		else
		{
			flag = 0;
		}
	}

	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}
//PASSIVE MOUSE
void iPassiveMouseMove(int mx,int my)
{

 mposx = mx;
 mposy = my;
 if(mx== 2){}
 else if(my== 2){}

}
//KEYBOARD
void iKeyboard(unsigned char key)
{
	if (flag == 1)
	{
		name[length] = key;
		length++;
	}
	if (key == 'o')
	{
		if (musicOn)
		{
			musicOn = false;
			PlaySound(0, 0, 0);
		}
		else
		{
			musicOn = true;
			PlaySound("music\\games.wav", NULL, SND_LOOP | SND_ASYNC);
		}
	}
	if(key == 'z')
	{
		if (index==9)
		{
			index = 0;
			fire[index] = 1;
			bx[index] = m + 535;
			by[index] = n + 100;
			index++;
		}
		else
		{
			fire[index] = 1;
			bx[index] = m + 535;
			by[index] = n + 100;
			index++;
		}
	}
	if (key == '\r')
	{
		i = 6;
	}
}
//SPECIAL KEYBOARD
void iSpecialKeyboard(unsigned char key)
{
	if (i == 3)
	{
		if (key == GLUT_KEY_HOME)
		{
			i = 2;
		}
	}
	if (i == 1)
	{
		if (key == GLUT_KEY_PAGE_UP)
		{
			i = 6;
		}
	}
	
	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	if (key == GLUT_KEY_RIGHT)
	{
		m += 30;
	}
	if (key == GLUT_KEY_LEFT)
	{
		m-=30;
	}
	if (key == GLUT_KEY_UP)
	{
		n += 20;
	}
	if (key == GLUT_KEY_DOWN)
	{
		n -= 20;
	}
}

int main()
{
	srand(time(NULL));
	if (musicOn)
	{
		PlaySound("music\\games.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	firstRound();
	iSetTimer(200, enemyMove);
	iSetTimer(25, fireMove);
	
	iInitialize(screenWidth, screenHight, "YOU");

	return 0;
}