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

void display(float height, float lenght, float width, float tx, float ty, float tz)
{   
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.1, 0.1, 0.1);
    
    // Top of the building
    glBegin(GL_POLYGON);
    glVertex3f(0.0+tx, height+ty, 0.0+tz);
    glVertex3f(width+tx, height+ty, 0.0+tz);
    glVertex3f(width+tx, height+ty, length+tz);
    glVertex3f(0.0+tx, height+ty, length+tz);
    glEnd();

    glColor3f(0.1, 0.1, 0.1);
    
    // Bottom of the building
    glBegin(GL_POLYGON);
    glVertex3f(0.0 +tx, 0.0+ty, 0.0+tz);
    glVertex3f(width+tx, 0.0+ty, 0.0+tz);
    glVertex3f(width+tx, 0.0+ty, length+tz);
    glVertex3f(0.0 +tx, 0.0+ty, length+tz);
    glEnd();

    glColor3f(0.75, 0.75, 0.75);
    
    // Front of the building
    glBegin(GL_POLYGON);
    glVertex3f(0.0 +tx, height+ty, length+tz);
    glVertex3f(width+tx, height+ty, length+tz);
    glVertex3f(width+tx, 0.0+ty, length+tz);
    glVertex3f(0.0 +tx, 0.0+ty, length+tz);
    glEnd();

    glColor3f(0.75, 0.75, 0.75);
    
    // Back of the building
    glBegin(GL_POLYGON);
    glVertex3f(0.0 +tx, height+ty, 0.0+tz);
    glVertex3f(width+tx, height+ty, 0.0+tz);
    glVertex3f(width+tx, 0.0+ty, 0.0+tz);
    glVertex3f(0.0 +tx, 0.0+ty, 0.0+tz);
    glEnd();

    glColor3f(0.45, 0.45, 0.45);
    
    // Left
    glBegin(GL_POLYGON);
    glVertex3f(0.0 +tx, height+ty, length+tz);
    glVertex3f(0.0 +tx, height+ty, 0.0+tz);
    glVertex3f(0.0 +tx, 0.0+ty, 0.0+tz);
    glVertex3f(0.0 +tx, 0.0+ty, length+tz);
    glEnd();

    glColor3f(0.45, 0.45, 0.45);
    glBegin(GL_POLYGON);//right
    glVertex3f(width+tx, height+ty, length+tz);
    glVertex3f(width+tx, height+ty, 0.0+tz);
    glVertex3f(width+tx, 0.0+ty, 0.0+tz);
    glVertex3f(width+tx, 0.0+ty, length+tz);
    glEnd();

    glFlush();
}
