#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

/* GLUT callback Handlers */
static void resize(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5, 7, -5, 5, -1, 1); // 2D orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3d(1, 0, 0); // Red color



    // Insert Line
    glBegin(GL_LINES);
        glVertex2f(-10, 0);
        glVertex2f(10, 0);
    glEnd();

        // Insert Line
    glBegin(GL_LINES);
        glVertex2f(0, 10);
        glVertex2f(0, -10);
    glEnd();

    // Polygon 1: (-3,3), (-1,3), (-1,1), (-3,1)
    glBegin(GL_POLYGON);
        glVertex2f(-3, 3);
        glVertex2f(-1, 3);
        glVertex2f(-1, 1);
        glVertex2f(-3, 1);
    glEnd();

    glColor3d(0, 1, 0); // Green color
    // Polygon 2: (1,2.5), (4,2.5), (4,1.5), (1,1.5)
    glBegin(GL_POLYGON);
        glVertex2f(1, 2.5);
        glVertex2f(4, 2.5);
        glVertex2f(4, 1.5);
        glVertex2f(1, 1.5);
    glEnd();

    // Polygon 3: (4,3), (6,2), (4,1)
    glBegin(GL_POLYGON);
        glVertex2f(4, 3);
        glVertex2f(6, 2);
        glVertex2f(4, 1);
    glEnd();

    glColor3d(0.501, 0, 0.501); // Violet color
    // Polygon 4: (-3,-3), (-1,-2), (-1,-4)
    glBegin(GL_POLYGON);
        glVertex2f(-3, -3);
        glVertex2f(-1, -2);
        glVertex2f(-1, -4);
    glEnd();

    glColor3d(1, 1, 0); // Yellow color
    // Polygon 5: (1,-4), (3,-4), (2,-2)
    glBegin(GL_POLYGON);
        glVertex2f(1, -4);
        glVertex2f(3, -4);
        glVertex2f(2, -2);
    glEnd();

    glutSwapBuffers();
}

static void key(unsigned char key, int x, int y)
{
    if (key == 27 || key == 'q') // ESC or 'q' to exit
    {
        exit(0);
    }
}

static void idle(void)
{
    glutPostRedisplay();
}

/* Program entry point */
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutCreateWindow("2D Polygons with OpenGL");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(0, 0, 0, 1); // Black background

    glutMainLoop();

    return EXIT_SUCCESS;
}
