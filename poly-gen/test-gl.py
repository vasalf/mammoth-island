from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import sys
from time  import sleep

def init_resources():
    glEnable(GL_BLEND)
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)
        
    glEnable(GL_DEPTH_TEST)
    glDepthFunc(GL_LESS)

    glClearColor(0, 100, 50, 1)
    glOrtho(-2, 2, -2, 2, .0001, 1000)

def on_display():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        
    glColor(1, 0, 0, 1)
    glBegin(5)
    glVertex3f(-1, -1, -1)
    glVertex3f(0, 1, -1)
    glVertex3f(1, 0, -1)
    glVertex3f(0, 0, -1)
    glVertex3f(-0.5, -1, -1)
    glEnd()
    glColor(1, 1, 0, 1)
    glBegin(GL_POLYGON)
    glVertex3f(0, 0, -1)
    glVertex3f(0, 1, -1)
    glVertex3f(0.5, 0.5, -1)
    glVertex3f(1, 1, -1)
    glVertex3f(2, 0, -1)


    glEnd()
    glutPostRedisplay()
    
    glutSwapBuffers()



def on_display1():
    
   
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        
    glutPostRedisplay()

    glutSwapBuffers()


glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA)
glutInitWindowSize(800, 600)
glutInit(sys.argv)
glutCreateWindow("test")
init_resources()

(on_display())
glFlush()
glDrawBuffers()
sleep(2)
(on_display1())
glFinish()
sleep(2)
