#include <GL/glut.h>

/*
    Description: To draw a building with the co-ordinates of the 			 left corner given.
    
    Parameters: 
		"height" - Floating point value for the heignt of the 				 building.
		"tx, ty, tz" - The tx, ty and tz values for the 					     bottom left corner of the building. 
    
    Returns: void
*/

GLfloat height = 500;
GLfloat tx = 0, ty = 0, tz = 0;

void display()
{   
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);//top
    glVertex3f(0.0+tx, height+ty, 0.0+tz);
    glVertex3f(100.0+tx, height+ty, 0.0+tz);
    glVertex3f(100.0+tx, height+ty, 100.0+tz);
    glVertex3f(0.0+tx, height+ty, 100.0+tz);
    glEnd();

    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);//bottom
    glVertex3f(0.0 +tx, 0.0+ty, 0.0+tz);
    glVertex3f(100.0 +tx, 0.0+ty, 0.0+tz);
    glVertex3f(100.0 +tx, 0.0+ty, 100.0+tz);
    glVertex3f(0.0 +tx, 0.0+ty, 100.0+tz);
    glEnd();

    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);//front
    glVertex3f(0.0 +tx, height+ty, 100.0+tz);
    glVertex3f(100.0 +tx, height+ty, 100.0+tz);
    glVertex3f(100.0 +tx, 0.0+ty, 100.0+tz);
    glVertex3f(0.0 +tx, 0.0+ty, 100.0+tz);
    glEnd();

    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);//back
    glVertex3f(0.0 +tx, height+ty, 0.0+tz);
    glVertex3f(100.0 +tx, height+ty, 0.0+tz);
    glVertex3f(100.0 +tx, 0.0+ty, 0.0+tz);
    glVertex3f(0.0 +tx, 0.0+ty, 0.0+tz);
    glEnd();

    glColor3f(0.45, 0.45, 0.45);
    glBegin(GL_POLYGON);//left
    glVertex3f(0.0 +tx, height+ty, 100.0+tz);
    glVertex3f(0.0 +tx, height+ty, 0.0+tz);
    glVertex3f(0.0 +tx, 0.0+ty, 0.0+tz);
    glVertex3f(0.0 +tx, 0.0+ty, 100.0+tz);
    glEnd();

    glColor3f(0.45, 0.45, 0.45);
    glBegin(GL_POLYGON);//right
    glVertex3f(100.0 +tx, height+ty, 100.0+tz);
    glVertex3f(100.0 +tx, height+ty, 0.0+tz);
    glVertex3f(100.0 +tx, 0.0+ty, 0.0+tz);
    glVertex3f(100.0 +tx, 0.0+ty, 100.0+tz);
    glEnd();

    gluLookAt(1,1,1,0,0,0,0,1,0);

    glFlush();
}
