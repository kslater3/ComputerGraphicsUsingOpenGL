
#include "GL/glut.h"



void myInit(void) {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    glColor3f(0.9f, 0.9f, 0.9f);

    glPointSize(4.0);

    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}



void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);


    // House Sillouhette
    glBegin(GL_LINE_STRIP);
        // From Ground
    	glVertex2i(120, 100);
        glVertex2i(380, 100);

        // To Right Wall
        glVertex2i(380, 250);

        // To Right Cieling
        glVertex2i(420, 250);

        // To Peak
        glVertex2i(250, 400);

        // To Chimney
        glVertex2i(175, 333);
        glVertex2i(175, 400);
        glVertex2i(145, 400);
        glVertex2i(145, 307);

        // To Left Ceiling
        glVertex2i(80, 250);
        glVertex2i(120, 250);

        // To Left Wall
        glVertex2i(120, 100);
    glEnd();


    glFlush();
}



int main(int argc, char **argv) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 150);

	glutInit(&argc, argv);


	glutCreateWindow("Primitives");

	glutDisplayFunc(myDisplay);


    myInit();

	glutMainLoop();


	return 0;
}
