#include <GL/glut.h>

/*
    Description: To draw a pin with a given center
    
    Parameters: 
		"radius" - Floating point value for the head of the 					pin.
		"c_x, c_y, c_z" - The x, y and z values for the 						  center of the pin's head. 
    
    Returns: void
*/
void draw_pin(GLfloat radius, GLfloat c_x, GLfloat c_y, GLfloat c_z)
{
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0,-3.5*radius,0.0);
    glVertex3f(-(radius/2), 0.0,0.0);
    glVertex3f((radius/2), 0.0,0.0);
    glEnd();
    glColor3f(1,0,0);
    GLUquadric *quad;
    quad = gluNewQuadric();
    gluSphere(quad,radius,100,20);
    glTranslatef(c_x,c_y,c_z);
}

