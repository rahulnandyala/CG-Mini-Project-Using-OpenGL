#include <GL/freeglut.h>

/*
	Draws a road given the corner coordinates.
	
	Args:
		x1, y1: The first corner coordinates.
		x2, y2: The opposite corner coordinates.
	
	Returns: void
*/
void draw_road(size_t x1, size_t y1, size_t x2, size_t y2)
{
    glColor3d(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2d(x1, y1);
    glVertex2d(x1, y2);
    glVertex2d(x2, y1);
    glVertex2d(x2, y2);
    glEnd();
    
    glColor3d(1, 1, 1);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);
    
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(x1, (y1 + y2) / 2);
    glVertex2f(x2, (y1 + y2) / 2);
    glEnd();
    glLineWidth(1);
    
    glDisable(GL_LINE_STIPPLE);
}
