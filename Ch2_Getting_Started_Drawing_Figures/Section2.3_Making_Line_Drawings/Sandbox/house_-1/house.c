

#include <stdio.h>
#include <math.h>

#include "GL/glut.h"



typedef struct GLintPoint {
    GLint x;
    GLint y;
} GLintPoint;


void house(GLintPoint, GLint, GLint, GLintPoint[], GLintPoint, GLint, GLint);


GLintPoint original_peak = {
    250,
    400
};

GLint original_width = 420 - 80;
GLint original_height = 400 - 100;


GLintPoint original_coordinates[12] = {
    // From Ground
    {120, 100},
    {380, 100},

    // To Right Wall
    {380, 250},

    // To Right Cieling
    {420, 250},

    // To Peak
    {240, 400},

    // To Chimney
    {175, 333},
    {175, 400},
    {145, 400},
    {145, 307},

    // To Left Ceiling
    {80, 250},
    {120, 250},

    // To Left Wall
    {120, 100}
};



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


    GLintPoint h1 = {250, 250};
    GLintPoint h2 = {100, 400};
    GLintPoint h3 = {400, 100};

    house(h1, 150, 150, original_coordinates, original_peak, original_width, original_height);
    house(h2, 50, 50, original_coordinates, original_peak, original_width, original_height);
    house(h3, 50, -50, original_coordinates, original_peak, original_width, original_height);


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



void house(GLintPoint peak, GLint width, GLint height, GLintPoint old_coordinates[], GLintPoint old_peak, GLint old_width, GLint old_height) {
    GLintPoint *newCoordinates = old_coordinates;
    GLint new_x;
    GLint new_y;

    glBegin(GL_LINE_STRIP);
        for(int i = 0; i < 12; i++) {
            new_x = (width * newCoordinates[i].x) / old_width + peak.x - (width * old_peak.x) / old_width;
            new_y = (height * newCoordinates[i].y) / old_height + peak.y - (height * old_peak.y) / old_height;

            glVertex2i(new_x, new_y);
        }
    glEnd();
}
