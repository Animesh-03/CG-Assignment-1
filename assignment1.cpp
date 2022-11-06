#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
using namespace std;

#define WINDOW_X 1000
#define WINDOW_Y 750

void drawCircle(int cx, int cy, int r)
{
    int x = 0;
	int y = r;
	float decision = 5/4 - r;
	glVertex2i(x+cx, y+cy);

	while (y > x)
	{
		if (decision < 0)
		{
			x++; 
			decision += 2*x+1;
		}
		else
		{
			y--;
			x++;
			decision += 2*(x-y)+1;
		}
		glVertex2i(x+cx, y+cy);
		glVertex2i(x+cx, -y+cy);
		glVertex2i(-x+cx, y+cy);
		glVertex2i(-x+cx, -y+cy);
		glVertex2i(y+cx, x+cy);
		glVertex2i(-y+cx, x+cy);
		glVertex2i(y+cx, -x+cy);
		glVertex2i(-y+cx, -x+cy);
	}
}

void drawCircleWithTrail(int cx, int cy, int r)
{
    int x = 0;
	int y = r;
	float decision = 5/4 - r;
	glVertex2i(x+cx, y+cy);

	while (y > x)
	{
		if (decision < 0)
		{
			x++; 
			decision += 2*x+1;
		}
		else
		{
			y--;
			x++;
			decision += 2*(x-y)+1;
		}
        int noise = rand()%30;

		glVertex2i(x+cx, y+cy);
		glVertex2i(x+cx, -y+cy);
        glColor3f(0.992, 0.517, 0.121);
		glVertex2i(-x+cx - noise, y+cy + noise);
		glVertex2i(-x+cx, -y+cy);
		glVertex2i(y+cx, x+cy);
        glColor3f(0.882, 0.301, 0.164);
		glVertex2i(-y+cx - noise, x+cy + noise);
		glVertex2i(y+cx, -x+cy);
		glVertex2i(-y+cx, -x+cy);
	}
}

void DrawEarth()
{
    glPointSize(1.0);
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
	drawCircle(400, 150, 100);
    glEnd();
}

void DrawAsteroid()
{
    glPointSize(1.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
	drawCircleWithTrail(200, 300, 20);
    glEnd();
}

void DrawStars(int n)
{
    glColor3f(1.0, 1.0, 1.0);
    
    while(n--)
    {
        int size = rand()%3 + 1;
        glPointSize(size);

        int x = rand()%WINDOW_X;
        int y = rand()%WINDOW_Y;
        
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
    }
    
}

void DrawNorthAmerica()
{
    glColor3f(0.215, 0.572, 0.215);
    glBegin(GL_POLYGON);

    glVertex2i(330, 220);
    glVertex2i(310, 195);
    glVertex2i(300, 160);
    glVertex2i(315, 140);
    glVertex2i(320, 120);
    glVertex2i(340, 135);
    glVertex2i(350, 140);
    glVertex2i(365, 160);
    glVertex2i(370, 195);
    glVertex2i(360, 215);

    glEnd();
}

void DrawSouthAfrica()
{
    glColor3f(0.415, 0.572, 0.215);
    glBegin(GL_POLYGON);

    glVertex2i(380, 180);
    glVertex2i(420, 165);
    glVertex2i(430, 140);
    glVertex2i(415, 125);
    glVertex2i(425, 115);
    glVertex2i(400, 85);
    glVertex2i(390, 95);
    glVertex2i(385, 110);
    glVertex2i(370, 160);

    glEnd();
}

void DrawAsiaEurope()
{
    glColor3f(0.215, 0.672, 0.215);
    glBegin(GL_POLYGON);

    glVertex2i(445, 190);
    glVertex2i(480, 190);
    glVertex2i(490, 180);
    glVertex2i(480, 170);
    // glColor3f(1.0, 0.0, 0.0);
    glVertex2i(495, 160);
    glVertex2i(485, 150);
    glVertex2i(470, 130);
    glVertex2i(460, 125);
    glVertex2i(465, 135);
    glVertex2i(470, 145);
    glVertex2i(450, 150);
    glVertex2i(440, 170);


    glEnd();
}

void DrawNorthPole()
{
    glColor3f(0.737, 0.807, 0.964);
    glBegin(GL_POLYGON);

    glVertex2i(370, 245);
    glVertex2i(380, 247);
    glVertex2i(390, 249);
    glVertex2i(400, 250);
    glVertex2i(430, 245);
    glVertex2i(450, 235);
    glVertex2i(420, 230);
    glVertex2i(410, 240);
    glVertex2i(390, 235);
    glVertex2i(370, 240);
    glVertex2i(350, 235);
   

    glEnd();
}

void DrawSouthPole()
{
    glColor3f(0.737, 0.807, 0.964);
    glBegin(GL_POLYGON);

    glVertex2i(360, 60);
    glVertex2i(370, 55);
    glVertex2i(390, 52);
    glVertex2i(400, 50);
    glVertex2i(410, 53);
    glVertex2i(425, 56);
    glVertex2i(430, 58);
    glVertex2i(435, 60);

    glEnd();
}

void renderFrame()
{
    glClear (GL_COLOR_BUFFER_BIT);
	glPointSize(1.0);

    DrawStars(500);

    DrawEarth();
    DrawNorthAmerica();
    DrawSouthAfrica();
    DrawAsiaEurope();
    DrawNorthPole();
    DrawSouthPole();

    DrawAsteroid();

	glFlush ();
}

void initOpenGL()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char **argv)
{
    time_t seed = time(NULL);
    srand(seed);
    cout << seed << endl;

    glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (WINDOW_X, WINDOW_Y);
	glutInitWindowPosition (0,0);
    glutCreateWindow ("Frame 1");
    glutDisplayFunc(renderFrame);
    initOpenGL();
    glutMainLoop();
}