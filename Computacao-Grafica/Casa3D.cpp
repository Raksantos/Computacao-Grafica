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
//typedef struct Vertex {
//    GLfloat x, y, z;
//} Vertex;
//
//static GLubyte front_cube[] = { 0,3,2,1 };
//static GLubyte back_cube[] = { 5,6,7,4 };
//static GLubyte left_cube[] = { 4,7,3,0 };
//static GLubyte right_cube[] = { 1,2,6,5 };
//static GLubyte top_cube[] = { 4,0,1,5 };
//static GLubyte bottom_cube[] = { 6,2,3,7 };
//
//static GLubyte front_piramid[] = { 1,8,0 };;
//static GLubyte left_piramid[] = { 1,5,8 };
//static GLubyte right_piramid[] = { 5,4,8 };
//static GLubyte back_piramid[] = { 4,0,8 };
//
//static GLfloat vertexs[27] = {
//    0.0,  30.0, 30.0, // 0 
//    30.0, 30.0, 30.0, // 1 
//    30.0,  0.0, 30.0, // 2 
//    0.0,   0.0, 30.0, // 3 
//    0.0,  30.0,  0.0, // 4 
//    30.0, 30.0,  0.0, // 5 
//    30.0,  0.0,  0.0, // 6 
//    0.0,   0.0,  0.0, // 7 
//    15.0, 45.0, 15.0  // 8
//};
//
//float colors[9][3] = { {0.0, 0.0, 1.0}/*azul*/, {1.0, 0.0, 0.0}/*vermelho*/,
//                       {1.0, 1.0, 0.0}/*amarelo*/, {0.0, 1.0, 0.0}/*verde*/,
//                       {0.8, 0.6, 0.1}/*laranja*/, {1.0, 0.0, 1.0},/*Ciano*/
//                       {0.7, 0.1, 0.6}/*rosa*/, {0.6, 0.6, 0.6}, /*Cinza*/
//                       {0.9, 0.3, 0.7} };
//
//static int y_axis, x_axis;
//int width, height;
//
//void init(void)
//{
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//    glOrtho(-50, 50, -50, 50, -50, 50);
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_CULL_FACE);
//}
//
//void reshape(int w, int h) {
//    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//    width = w;
//    height = h;
//}
//
//void keyboard(unsigned char key, int a, int b)
//{
//    switch (key) {
//    case 27:
//        exit(0);
//        break;
//    case 'a':
//        y_axis = (y_axis - 5) % 360;
//        glutPostRedisplay();
//        break;
//    case 'd':
//        y_axis = (y_axis + 5) % 360;
//        glutPostRedisplay();
//        break;
//    case 'w':
//        x_axis = (x_axis - 5) % 360;
//        glutPostRedisplay();
//        break;
//    case 's':
//        x_axis = (x_axis + 5) % 360;
//        glutPostRedisplay();
//        break;
//    case 'r':
//        y_axis = (y_axis - 5) % 360;
//        glutPostRedisplay();
//        break;
//    case 'R':
//        y_axis = (y_axis - 5) % 360;
//        glutPostRedisplay();
//        break;
//    }
//}
//
//void display()
//{
//    /* Limpar todos os pixels  */
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    glPushMatrix();
//    glRotatef((GLfloat)y_axis, 0.0, 1.0, 0.0);
//    glRotatef((GLfloat)x_axis, 1.0, 0.0, 0.0);
//
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glVertexPointer(3, GL_FLOAT, 0, vertexs);
//
//    //Frente
//    glColor3f(colors[0][0], colors[0][1], colors[0][2]);
//    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, front_cube);
//
//    //Left
//    glColor3f(colors[1][0], colors[1][1], colors[1][2]);
//    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, left_cube);
//
//    //Right
//    glColor3f(colors[2][0], colors[2][1], colors[2][2]);
//    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, right_cube);
//
//    //Back
//    glColor3f(colors[3][0], colors[3][1], colors[3][2]);
//    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, back_cube);
//
//    //Bottom
//    glColor3f(colors[4][0], colors[4][1], colors[4][2]);
//    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, bottom_cube);
//
//    //top
//    glColor3f(colors[4][0], colors[4][1], colors[4][2]);
//    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, top_cube);
//
//    /*Front Piramid */
//    glColor3f(colors[5][0], colors[5][1], colors[5][2]);
//    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, front_piramid);
//
//    //Left Piramid
//    glColor3f(colors[6][0], colors[6][1], colors[6][2]);
//    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, left_piramid);
//
//    //Right Piramid
//    glColor3f(colors[7][0], colors[7][1], colors[7][2]);
//    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, right_piramid);
//
//    //Back Piramid
//    glColor3f(colors[8][0], colors[8][1], colors[8][2]);
//    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, back_piramid);
//
//    glPopMatrix();
//    glutSwapBuffers();
//}
//
//
//int main(int argc, char** argv) {
//
//    glutInit(&argc, argv);
//
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(640, 480);
//    glutCreateWindow("Casa");
//    glutInitWindowPosition(100, 100);
//    init();
//    glutDisplayFunc(display);
//    glutKeyboardFunc(keyboard);
//    glutReshapeFunc(reshape);
//    glutMainLoop();
//
//    return 0;
//
//}