#!/usr/bin/python2.7
# -*- coding: utf-8 -*-

###############################################################
# portage de planet.c

from OpenGL.GL import *  # exception car prefixe systematique
from OpenGL.GLU import *
from OpenGL.GLUT import *
import sys

###############################################################
# variables globales
year, day = 0, 0
quadric = None

###############################################################
# 

def init():
    """
    Fontion initialisation
    probablement obligatoire en Opengl a cause
    d'une philosophie debile
    """
    global quadric
    #fond noir
    glClearColor (0.0, 0.0, 0.0, 0.0)
    #type de shader
    glEnable(GL_DEPTH_TEST)
    glDepthFunc(GL_LESS)
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, 1000);
    #glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    #glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glShadeModel (GL_SMOOTH)
    #alloue un qudric genre 1=x**2+y**2+z**2
    #cAd tout les point a 1 de distacne
    quadric = gluNewQuadric()
    #definir le style pour plus tard
    gluQuadricDrawStyle(quadric, GLU_FILL)

def display():
    glColor4f (0.0, 1.0, 0.0, 1.0)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)

    glPushMatrix()
    gluSphere(quadric, 1.0, 2000, 1600)
    glRotatef(year, 0.0, 1.0, 0.0)
    glTranslatef(2.0, 0.0, 0.0)
    glRotatef(day, 0.0, 1.0, 0.0)
    gluSphere(quadric, 0.2, 10000, 800000)
    glPopMatrix()
    glFlush()

    glutSwapBuffers()

def reper():
    glVertex2f(0, 10)
    glVertex2f(10, 0)

def reshape(width, height):
    glViewport(0, 0, width, height)
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    if width <= height:
        glOrtho(-2.5, 2.5, -2.5*height/width, 2.5*height/width, -10.0, 10.0)
    else:
        glOrtho(-2.5*width/height, 2.5*width/height, -2.5, 2.5, -10.0, 10.0)
    glMatrixMode(GL_MODELVIEW)

def keyboard(key, x, y):
    global day, year
    if key == b'k':
        day = (day + 10) % 360
        year = (year + 5) % 360
    if key == b'j':
        day = (day + 10) % 360
    elif key == b'J':
        day = (day - 10) % 360
    elif key == b'a':
        year = (year + 5) % 360
    elif key == b'A':
        year = (year - 5) % 360
    elif key == '\033':
        sys.exit( )
    glutPostRedisplay()  # indispensable en Python

###############################################################
# MAIN

glutInit()
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH)

glutCreateWindow('planet')
glutReshapeWindow(512,512)

glutReshapeFunc(reshape)
glutDisplayFunc(display)
glutKeyboardFunc(keyboard)

init()
glutMainLoop()
