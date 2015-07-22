
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
    glOrtho(0, 80, 0, 60, .0001, 1000)





colors = dict()
colors["black"] = (0, 0, 0, 1)
colors["white"] = (1, 1, 1, 1)
colors["green"] = (0, 1, 0, 1)
colors["red"] = (1, 0, 0, 1)
colors["blue"] = (0, 0, 1, 1)
colors["yellow"] = (1, 1, 0, 1)
colors["purpur"] = (1, 0, 1, 1)
colors["cyan"] = (0, 1, 1, 1)
#help("OpenGL.GL.GL_QUADS")
has_window = False
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA)
glutInitWindowSize(800, 600)
glutInit(sys.argv)
def draw(objs, movement = (0, 0), finish = None):
    global has_window
    if has_window:
        a = (glutGetWindow())    
#        glutCreateWindow('test')
#        glutDestroyWindow(a)
#        print(glutGetWindow())
    else:
        glutCreateWindow("test")
        init_resources()
        has_window = True

    def on_display():
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        for i in range(len(objs)):
            
            glColor(colors[objs[i].color])
#            print(objs[i].points)
#            print(i)
            """
            glBegin(GL_POLYGON)
            for j in range(len(objs[i].points)):
                glVertex3f(objs[i].points[j].x + 20 * i, objs[i].points[j].y, -1)
                
            glEnd()"""            
            glColor(colors["black"])
            glBegin(GL_LINES)
            for j in range(-1, len(objs[i].points) - 1):
                
                glVertex3f(objs[i].points[j].x + movement[0], objs[i].points[j].y + movement[1], -1)
                glVertex3f(objs[i].points[j + 1].x + movement[0], objs[i].points[j + 1].y + movement[1], -1)
            glEnd()

        if finish != None:
            glColor(colors["red"])
            glBegin(GL_LINES)

            glVertex3f(finish + movement[0], 0, -1)
            glVertex3f(finish + movement[0], 50, -1)
            glEnd()
        glutPostRedisplay()
        glFlush()
        glutSwapBuffers()


    glClearColor(1, 1, 100, 100)
    on_display()
#    glutSetWindow(1)
#    glutDisplayFunc(on_display)
#    glutSwapBuffers()
    

