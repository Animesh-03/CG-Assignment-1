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
    glColor3f(0.0, 1.0, 0.0);
}

void renderFrame()
{
    glClear (GL_COLOR_BUFFER_BIT);
	glPointSize(1.0);

    DrawStars(500);
    DrawEarth();
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