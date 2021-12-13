/*Aluno: Rodrigo Santos da Silva - 5º Período
Para rodar o projeto, basta clicar a tecla a para realizar a movimentação da ola*/

#include <GL/glut.h>

bool controll_orientation = false;

static GLfloat s[16] = {
        0, 2,
        0, 2,
        0, 2,
        0, 2,
        0, 2,
        0, 2
};

void displaySquares()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(3, s[0]); // coordenadas
    glVertex2f(2, s[0]);
    glVertex2f(2, s[1]);
    glVertex2f(3, s[1]);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(1, s[2]); // coordenadas
    glVertex2f(0, s[2]);
    glVertex2f(0, s[3]);
    glVertex2f(1, s[3]);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-1, s[4]); // coordenadas
    glVertex2f(-2, s[4]);
    glVertex2f(-2, s[5]);
    glVertex2f(-1, s[5]);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-3, s[6]); // coordenadas
    glVertex2f(-4, s[6]);
    glVertex2f(-4, s[7]);
    glVertex2f(-3, s[7]);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
    glVertex2f(-5, s[8]); // coordenadas
    glVertex2f(-6, s[8]);
    glVertex2f(-6, s[9]);
    glVertex2f(-5, s[9]);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(-7, s[10]); // coordenadas
    glVertex2f(-8, s[10]);
    glVertex2f(-8, s[11]);
    glVertex2f(-7, s[11]);
    glEnd();

    glFlush();
}

void verifyDiferenceSquares()
{
    for (int i = 0; i < 12; i += 2) {
        //Verifica a diferença entre o i-ésimo quadrado e o i-ésimo + 1. Caso seja mais alto, alinha os quadrados
        //de acordo com a orientação atual da Ola
        if ((s[i] - s[i + 2] == 2 && s[i + 1] - s[i + 3] == 2) || (s[i] - s[i + 2] == -2 && s[i + 1] - s[i + 3] == -2)) {
            if (controll_orientation) {
                s[i + 2] += 2;
                s[i + 3] += 2;
                break;
            }
            else {
                s[i + 2] -= 2;
                s[i + 3] -= 2;
                break;
            }
        }

        //Se todos os quadrados estiverem na mesma altura, isto é o 1 quadrado tiver uma altura igual a do último já que
        //o if anterior ocorrerá até que todos os quadrados estejam alinhados, ele muda a orientação e desce ou sobe o 
        //primeiro quadrado, reiniciando assim a Ola
        else if (s[0] == s[10] && s[1] == s[11])
        {
            controll_orientation = !controll_orientation;

            if (!controll_orientation) {
                s[0] -= 2;
                s[1] -= 2;
            }
            else {
                s[0] += 2;
                s[1] += 2;
            }
        }
    }
}

void keyboard(unsigned char key)
{
    if (key == 'a')
    {
        verifyDiferenceSquares();
        displaySquares();
    }
}

//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//
//    const int LARGURA = 800;
//    const int ALTURA = 600;
//
//    glutInitWindowPosition(100, 100);
//    glutInitWindowSize(LARGURA, ALTURA);
//    glutCreateWindow("Ola");
//
//    glClearColor(0.0, 0.15, 0.25, 1.0);
//
//    //Redefinindo projeção pela Matriz
//
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(-10.0, 10.0, -10.0, 10.0, 1.0, -1.0);
//
//    glutDisplayFunc(displaySquares);
//    glutKeyboardFunc(reinterpret_cast<void (*)(unsigned char, int, int)>(keyboard));
//    glutMainLoop();
//
//    return 0;
//}