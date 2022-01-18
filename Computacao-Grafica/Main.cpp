/*Aluno: Rodrigo Santos da Silva - 5º Período
* Y = aumenta velocidade
*/

#include <GL/glut.h>
#include <iostream>

using namespace std;

int year = 0, day = 0;

void scheduleUpdate(int value)
{
    glutTimerFunc(10, scheduleUpdate, 1);
    day++, year++;
    glutPostRedisplay();
}

void init()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0, 0, 0, 0);

    glEnable(GL_LIGHT0);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
    glShadeModel(GL_SMOOTH);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) 
    {
        case 'y':
            glutTimerFunc(10, scheduleUpdate, 1);
            break;
        case 'Y':
            glutTimerFunc(10, scheduleUpdate, 1);
            break;
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(60, (double)w / h, 1, 20);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}

void drawSolarSystem()
{
    //light position
    GLfloat position[] = { 0.0f, 0.0f, 0.0f, 1.0f };

    //positioning and creating light
    glLightfv(GL_LIGHT0, GL_POSITION,  position);

    //Adding shigniness to the planets
    GLfloat color_1[] = { 0.8f, 0.8f, 0.8f, 1.0f };//White
    GLfloat color_2[] = { 0.9f, 0.8f, 0.8f, 1.0f };//cyan

    glMaterialfv(GL_FRONT, GL_DIFFUSE, color_2);
    glMaterialfv(GL_FRONT, GL_SPECULAR, color_1);

    GLfloat shininess[] = { 100 };
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

    //Sun
    glPushMatrix();
        glColor3ub(255, 127, 80);
        glRotatef(year, 1, 0, 0);
        glRotatef(day, 0, 0, 1);
        glDisable(GL_LIGHTING);
        glutSolidSphere(0.5, 100, 100);
        glEnable(GL_LIGHTING);
    glPopMatrix();

    // Planet 1
    glPushMatrix();
        glColor3ub(255, 255, 0);
        glRotatef(year, 0, 1, 0);
        glTranslatef(2, 0, 0);
        glPushMatrix();
            glRotatef(day, 0, 1, 0);
            glutSolidSphere(0.1, 100, 100); // Planet 1
        glPopMatrix();

        glPushMatrix();
            glColor3ub(0, 255, 0);
            glRotatef(1.5 * day, 1, 0, 0);
            glTranslatef(0.4, 0, 0);
            glutSolidSphere(0.025, 100, 100); // Moon 1
        glPopMatrix();

        glPushMatrix();
            glColor3ub(0, 0, 255);
            glRotatef(1.75 * day, 1, 1, 0);
            glTranslatef(0.3, 0, 0);
            glutSolidSphere(0.025, 100, 100); // Moon 2
        glPopMatrix();
    glPopMatrix();

    //Planet 2
    glPushMatrix();
        glColor3ub(0, 255, 255);
        glRotatef(-2.5 * year, 0, -1, 0);
        glTranslatef(1, 0, 0);
        glutSolidSphere(0.1, 100, 100); // Planet 2
    glPopMatrix();

    //Planet 3
    glPushMatrix();
        glColor3ub(125, 255, 0);
        glRotatef(0.5 * year, 0, 1, 1);
        glTranslatef(2, 0, 0);
        glutSolidSphere(0.05, 10, 8); // Planet 3
    glPopMatrix();

    //Planet 4
    glPushMatrix();
        glColor3ub(255, 0, 125);
        glRotatef(-0.8 * year, 0, 0, 1);
        glTranslatef(2.5, 0, 0);
        glutSolidSphere(0.15, 100, 100); // Planet 4
    glPopMatrix();

    //Planet 5
    glPushMatrix();
        glColor3ub(255, 255, 255);
        glRotatef(0.4 * year, 0, 0, 1);
        glTranslatef(3, 0, 0);
        glutSolidSphere(0.2, 100, 100); // Planet 5
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        drawSolarSystem();
    glPopMatrix();


    glutSwapBuffers();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Planetas");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;

}