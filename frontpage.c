#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <string.h>
int flag=0;
void *currentfont;

void setFont(void *font)
{
    currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
    char *c;
    int len = (int) strlen(string);
    int i;
    glRasterPos3f(x,y,z);
    /*for(c=string;*c!='\0';c++)
    {
        glColor3f(0.0,0.0,0.0);
        glutBitmapCharacter(currentfont,*c);
    }*/
    for(i = 0;i<len;i++)
    {
        glColor3f(0.0,0.0,0.0);
        glutBitmapCharacter(currentfont,string[i]);
    }
}

void frontscreen(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0,0,1);
    drawstring(20.0,90.0,0.0,"PESIT SOUTH CAMPUS");
    glColor3f(0.7,0,1);
    drawstring(21,82,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
    glColor3f(1,0.5,0);
    drawstring(38,70,0.0,"A MINI PROJECT ON");
    glColor3f(1,0,0);
    drawstring(40,60,0.0,"R Trees");
    glColor3f(1,0.5,0);
    drawstring(20,50,0.0,"BY:");
    glColor3f(0.5,0,0.5);
    drawstring(10,40,0.0,"RAHUL REDDY NANDYALA      (1PE15CS116)");
    drawstring(10,34,0.0,"RAHUL YEDIDA              (1PE15CS117)");
    glColor3f(1,0.5,0);
    drawstring(68,50,0.0,"GUIDES:");
    glColor3f(0.5,0.2,0.2);
    drawstring(63,40,0.0,"GUIDE NAME FIRST");
    drawstring(63,34,0.0,"GUIDE NAME SECOND");
    glColor3f(1,0.1,1);
    drawstring(32,10,0.0,"PRESS ENTER TO START");
    glutSwapBuffers();
    //glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);//top
    glVertex3f(0.0, 100.0, 0.0);
    glVertex3f(100.0, 100.0, 0.0);
    glVertex3f(100.0, 100.0, 100.0);
    glVertex3f(0.0, 100.0, 100.0);
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);//bottom
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(100.0, 0.0, 0.0);
    glVertex3f(100.0, 0.0, 100.0);
    glVertex3f(0.0, 0.0, 100.0);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);//front
    glVertex3f(0.0, 100.0, 100.0);
    glVertex3f(100.0, 100.0, 100.0);
    glVertex3f(100.0, 0.0, 100.0);
    glVertex3f(0.0, 0.0, 100.0);
    glEnd();

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);//back
    glVertex3f(0.0, 100.0, 0.0);
    glVertex3f(100.0, 100.0, 0.0);
    glVertex3f(100.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glEnd();

    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_POLYGON);//left
    glVertex3f(0.0, 100.0, 100.0);
    glVertex3f(0.0, 100.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 100.0);
    glEnd();

    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_POLYGON);//right
    glVertex3f(100.0, 100.0, 100.0);
    glVertex3f(100.0, 100.0, 0.0);
    glVertex3f(100.0, 0.0, 0.0);
    glVertex3f(100.0, 0.0, 100.0);
    glEnd();

    gluLookAt(1,1,1,0,0,0,0,1,0);

    glFlush();
}

void mydisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	if(flag==0)
		frontscreen();
	if(flag==1)
		display();
}

void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch(key)
    {
        case 13:if(flag==0) //Ascii of 'enter' key is 13
        flag=1;
        break;
    }
    mydisplay();
}

void reshape(int w, int h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, w, h, 0);
  glMatrixMode(GL_MODELVIEW);
}

void myinit()
{
   // glOrtho(-0.0,200.0,-200.0,200.0,-0.0,200.0);
    glClearColor(1.0,1.0,1.0,1.0);
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(750, 750);
    glutCreateWindow("R Trees");
   // glutDisplayFunc(display);
    glutDisplayFunc(mydisplay);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(myKeyboardFunc);
    myinit();
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}
