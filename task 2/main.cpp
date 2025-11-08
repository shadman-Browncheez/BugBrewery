#include <GL/glut.h>
#include <math.h>

// Function to draw a circle (for the sun)
void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

// Function to draw a mountain
void drawMountain(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

// Function to draw a tree (triangle + trunk)
void drawTree(float x, float y, float size) {
    // Tree leaves
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y + size);
    glVertex2f(x - size / 2, y);
    glVertex2f(x + size / 2, y);
    glEnd();

    // Tree trunk
    glBegin(GL_QUADS);
    glVertex2f(x - size / 10, y);
    glVertex2f(x + size / 10, y);
    glVertex2f(x + size / 10, y - size / 3);
    glVertex2f(x - size / 10, y - size / 3);
    glEnd();
}

// Function to draw curved ground
void drawGround() {
    glBegin(GL_LINE_STRIP);
    for (float x = -1.0; x <= 1.0; x += 0.01) {
        float y = -0.5 + 0.1 * sin(3 * x);
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0); // black color

    // Draw mountains
    drawMountain(-0.9, -0.3, -0.4, 0.5, 0.1, -0.3);
    drawMountain(-0.3, -0.3, 0.2, 0.6, 0.7, -0.3);
    drawMountain(0.1, -0.3, 0.5, 0.5, 0.9, -0.3);

    // Draw trees
    drawTree(-0.6, -0.35, 0.1);
    drawTree(-0.4, -0.35, 0.1);
    drawTree(-0.2, -0.35, 0.1);
    drawTree(0.0, -0.35, 0.1);
    drawTree(0.2, -0.35, 0.1);
    drawTree(0.4, -0.35, 0.1);

    // Draw sun
    drawCircle(0.6f, 0.6f, 0.1f, 50);

    // Draw curved ground
    drawGround();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // white background
    glColor3f(0.0, 0.0, 0.0);         // draw color black
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mountain Landscape");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
