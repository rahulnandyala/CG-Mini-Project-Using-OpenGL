#include <GL/glut.h>

/*
    Description: To draw a building with the co-ordinates of the 			 
    left corner given.
    
    Parameters: 
	height: Floating point value for the heignt of the 				 
		building.
	tx, ty, tz: The tx, ty and tz values for the 					     
		bottom left corner of the building. 
    
    Returns: void
*/

void display(float height, float tx, float ty, float tz)
{   
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.1, 0.1, 0.1);
    
    // Top of the building
    glBegin(GL_POLYGON);
    glVertex3f(tx, height + ty, tz);
    glVertex3f(100 + tx, height + ty, tz);
    glVertex3f(100 + tx, height + ty, 100 + tz);
    glVertex3f(tx, height + ty, 100 + tz);
    glEnd();

    glColor3f(0.1, 0.1, 0.1);
    
    // Bottom of the building
    glBegin(GL_POLYGON);
    glVertex3f(tx, ty, tz);
    glVertex3f(100 + tx, ty, tz);
    glVertex3f(100 + tx, ty, 100 + tz);
    glVertex3f(tx, ty, 100 + tz);
    glEnd();

    glColor3f(0.75, 0.75, 0.75);
    
    // Front of the building
    glBegin(GL_POLYGON);
    glVertex3f(tx, height + ty, 100 + tz);
    glVertex3f(100 + tx, height + ty, 100 + tz);
    glVertex3f(100 + tx, ty, 100 + tz);
    glVertex3f(tx, ty, 100 + tz);
    glEnd();

    glColor3f(0.75, 0.75, 0.75);
    
    // Back of the building
    glBegin(GL_POLYGON);
    glVertex3f(tx, height + ty, tz);
    glVertex3f(100 + tx, height + ty, tz);
    glVertex3f(100 + tx, ty, tz);
    glVertex3f(tx, ty, tz);
    glEnd();

    glColor3f(0.45, 0.45, 0.45);
    
    // Left
    glBegin(GL_POLYGON);
    glVertex3f(tx, height + ty, 100 + tz);
    glVertex3f(tx, height + ty, tz);
    glVertex3f(tx, ty, tz);
    glVertex3f(tx, ty, 100 + tz);
    glEnd();

    glColor3f(0.45, 0.45, 0.45);
    glBegin(GL_POLYGON);//right
    glVertex3f(100 + tx, height + ty, 100 + tz);
    glVertex3f(100 + tx, height + ty, tz);
    glVertex3f(100 + tx, ty, tz);
    glVertex3f(100 + tx, ty, 100 + tz);
    glEnd();

    glFlush();
}
