#include <string.h>
#include <GL/glut.h>

void *font = GLUT_BITMAP_TIMES_ROMAN_24;
void *fonts[] =
{
  GLUT_BITMAP_9_BY_15,
  GLUT_BITMAP_8_BY_13,
  GLUT_BITMAP_TIMES_ROMAN_10,
  GLUT_BITMAP_TIMES_ROMAN_24,
  GLUT_BITMAP_HELVETICA_10,
  GLUT_BITMAP_HELVETICA_12,
  GLUT_BITMAP_HELVETICA_18
};
char defaultMessage[] = "This is interactive OpenGL Fonts Program";
char *message = defaultMessage;

void
selectFont(int newfont)
{
  font = fonts[newfont];
  /*switch (newfont) {
 case 1: font =GLUT_BITMAP_9_BY_15;
    break;
  case 2: font = GLUT_BITMAP_8_BY_13;
    break; 
 case 3: font = GLUT_BITMAP_TIMES_ROMAN_10;
    break;
  case 4: font = GLUT_BITMAP_TIMES_ROMAN_24;
    break;
 case 5: font = GLUT_BITMAP_HELVETICA_10;
    break;
 case 6: font = GLUT_BITMAP_HELVETICA_12; 
    break;
 case 7: font = GLUT_BITMAP_HELVETICA_18;
    break;

	}*/
  glutPostRedisplay();
}

void
selectMessage(int msg)
{
  switch (msg) {
  case 1:
    message = "i am small caps message";
    break;
  case 2:
    message = "I AM IN CAPITAL LETTERS";
    break;
  }
}

void
selectColor(int color)
{
  switch (color) {
  case 1:
    glColor3f(0.0, 1.0, 0.0);
    break;
  case 2:
    glColor3f(1.0, 0.0, 0.0);
    break;
 case 3:
    glColor3f(0.0, 0.0, 1.0);
    break;
  case 4:
    glColor3f(1.0, 1.0, 1.0);
    break;
  }
  glutPostRedisplay();
}

void
tick(void)
{
  glutPostRedisplay();
}

void
output(int x, int y, char *string)
{
  int len, i;

  glRasterPos2f(x, y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, string[i]);
  }
}

void
display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  output(0, 24, "This is written in a GLUT bitmap font.");
  output(78, 78, message);
  output(50, 145, "(positioned in pixels with upper-left origin)");
  glutSwapBuffers();
}

void
reshape(int w, int h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, w, h, 0);
  glMatrixMode(GL_MODELVIEW);
}

int
main(int argc, char **argv)
{
  int i, msg_submenu, color_submenu; //font_submenu;

  glutInit(&argc, argv);
  for (i = 1; i < argc; i++) {
    if (!strcmp(argv[i], "-mono")) {
      font = GLUT_BITMAP_9_BY_15;
    }
  }
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 150);
  glutCreateWindow("Intractive Font Program");
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(tick);
  msg_submenu = glutCreateMenu(selectMessage);
  glutAddMenuEntry("abc", 1);
  glutAddMenuEntry("ABC", 2);
  color_submenu = glutCreateMenu(selectColor);
  glutAddMenuEntry("Green", 1);
  glutAddMenuEntry("Red", 2);
  glutAddMenuEntry("Blue", 3);
  glutAddMenuEntry("White", 4);
  //font_submenu=glutCreateMenu(selectFont);
  glutCreateMenu(selectFont);
  glutAddMenuEntry("9 by 15", 1);
  glutAddMenuEntry("8 BY 13", 2);
  glutAddMenuEntry("Times Roman 10", 3);
  glutAddMenuEntry("Times Roman 24", 4);
  glutAddMenuEntry("Helvetica 10", 5);
  glutAddMenuEntry("Helvetica 12", 6);
  glutAddMenuEntry("Helvetica 18", 7);
  glutAddSubMenu("Messages", msg_submenu);
  glutAddSubMenu("Color", color_submenu);
  //glutAddSubMenu("Font", font_submenu);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  glutMainLoop();
  return 0;             /* ANSI C requires main to return int. */
}
