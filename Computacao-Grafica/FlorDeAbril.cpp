///*Aluno: Rodrigo Santos da Silva - 5º Período
//* Girar: Esquerda = a, Direita = d
//* Velocidade: Mais = m, Menos = l
//*/
//
//#include <GL/glut.h>
//#include <iostream>
//
//using namespace std;
//
//#define PI 3.14159265358979323846
//#define SIN_60 0.86
//
//float speed_angle = PI / 4;
//
//typedef struct Vertex {
//    GLfloat x, y;
//} Vertex;
//
////float colors[7][3] = { {1.0, 1.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0},
////                        {0.0, 0.0, 0.0}, {1.0, 1.0, 0.0} };
//
//Vertex flower[] = {
//    {12.5, 25 * SIN_60},
//    {20.0, 5.0},
//
//    {-12.5, 25 * SIN_60},
//    {-20.0, 5.0},
//
//    {20.0, -5.0},
//    {12.5, 25 * (-SIN_60)},
//
//    {-20.0, -5.0},
//    {-12.5, 25 * (-SIN_60)}
//};
//
//void init(void)
//{
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//    glOrtho(-100.0, 100.0, -100.0, 100.0, 1.0, -1.0);
//    glutReshapeWindow(640, 480);
//    glMatrixMode(GL_PROJECTION); //Projecao 2D
//    glLoadIdentity();
//}
//
//
//void spin(float angle)
//{
//    Vertex aux;
//
//    for (int i = 0; i < 8; i += 2) {
//        for (int j = 0; j <= i + 1; j++) {
//            aux = flower[j];
//            flower[j].x = (aux.x * cos(angle)) - (aux.y * sin(angle));
//            flower[j].y = (aux.y * cos(angle)) + (aux.x * sin(angle));
//        }
//    }
//    glutPostRedisplay();
//}
//
//void keyboard(unsigned char key, int a, int b)
//{
//    float variation;
//
//    switch (key) {
//    case 'a':
//        spin(speed_angle);
//        break;
//    case 'd':
//        spin(-speed_angle);
//        break;
//    case 'm':
//        variation = speed_angle + (1.0f * PI / 16);
//        speed_angle = variation;
//        cout << "Speed: " << speed_angle << "\n";
//        break;
//    case 'l':
//        variation = speed_angle - (1.0f * PI / 16);
//        speed_angle = variation;
//        cout << "Speed: " << speed_angle << "\n";
//        break;
//    }
//}
//
//void display()
//{
//    /* Limpar todos os pixels  */
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    glColor3f(1.0, 1.0, .0);
//    glBegin(GL_POLYGON);
//    glVertex3f(-1.5, 0.0, -1.0f);
//    glVertex3f(1.5, 0.0, -1.0f);
//    glVertex3f(-1.5, -50.0, -1.0f);
//    glVertex3f(1.5, -50.0, -1.0f);
//    glEnd();
//
//    /*Desenha folhas da flor de abril*/
//
//    for (int i = 0; i < 8; i += 2) {
//        glBegin(GL_TRIANGLES);
//
//        if (i < 7) {
//            glColor3f(colors[i][0], colors[i][1], colors[i][2]);
//        }
//        glVertex2f(0.0, 0.0);
//
//        for (int j = i; j <= i + 1; j++) {
//            GLfloat x = flower[j].x;
//            GLfloat y = flower[j].y;
//            glVertex2f(x, y);
//        }
//
//        glEnd();
//    }
//
//    glFlush();
//}
//
//
////int main(int argc, char** argv) {
////
////    glutInit(&argc, argv);
////
////    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
////    glutInitWindowSize(640, 480);
////    glutCreateWindow("Flor de Abril");
////
////    init();
////
////    glutDisplayFunc(display);
////    glutKeyboardFunc(keyboard);
////    glutMainLoop();
////
////
////    return 0;
////
////}