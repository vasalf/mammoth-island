#!/usr/bin/python3

from geometry import point, vector
from draw_objects import draw
from objects import object
from map import map as field
from map import bin_search as bin_sec
from random import randint, shuffle, seed, random
import copy
import math
import threading
import time
seed(1)
N = 20
max_amount_of_vertex = 10
D = 0.1
inf = 179179179
eps = 0.001
def rand_figure():
    amount_of_vertex = randint(3, max_amount_of_vertex)

    points = set()

    while len(points) < amount_of_vertex:
        points.add(point(randint(10, 20), randint(10, 20)))
    points = list(points)

    min_point = min(points)
    points.sort(key = lambda x: (-inf, -inf, -inf) if x == min_point else (-math.atan2(x.y - min_point.y, x.x - min_point.x), x.x, x.y))
    j = len(points) - 1

    last_atan = math.atan2(points[j].y - min_point.y, points[j].x - min_point.x)
    while (j > 0) and abs(math.atan2(points[j].y - min_point.y, points[j].x - min_point.x) - last_atan) < eps:
        j -= 1
    points[j:].reverse()
#    print(points)
    return object(points)

def randPoint():
    return point(randint(10, 20), randint(10, 20))

def bin_search(elem, lis):
    l = 0
    r = len(lis)
    while ((r - l) > 1):
        m = (l + r) // 2
        if lis[m] > elem:
            r = m
        else:
            l = m
    return r
    
def merge(fig1, fig2):
    points = []
    points.extend(fig1.points)
    points.extend(fig2.points)
    shuffle(points)
    if random() < D:
        idx = randint(0, (len(fig1.points) + len(fig2.points)) // 2)
        points[idx] = randPoint()
    points = (list(set(points[:(len(fig1.points) + len(fig2.points)) // 2])))
    min_point = min(points)
    points.sort(key = lambda x:(-inf, -inf, -inf) if x == min_point else (math.atan2(x.y - min_point.y, x.x - min_point.x), x.x - min_point.x, x.y - min_point.y))
    j = len(points) - 1

    last_atan = math.atan2(points[j].y - min_point.y, points[j].x - min_point.x)
    while (j > 0) and abs(math.atan2(points[j].y - min_point.y, points[j].x - min_point.x) - last_atan) < eps:
        j -= 1
    points[j:].reverse()
    return object(points)
    


def take_part(my_field, figure, start_point):
    counter = 0
    my_field.set_figure(copy.deepcopy(figure), start_point)
    last_x = start_point.x
    last_time = time.time()
    while counter < 100 and my_field.figures[0].centre.x < (1 << my_field.curr_turn) and my_field.figures[0].centre > point(0, 0):
        
        my_field.move(delta_time)
        if abs(my_field.figures[0].v_centre.x) < eps and abs(my_field.figures[0].v_centre.y) < eps:
            counter += 1
        else:
            counter //= 2
        left, right = bin_sec(my_field.figures[0], my_field.track, 2 * wight)
        if time.time() - last_time > 15:
            if last_x > my_field.figures[0].centre.x:
                counter = 1001
            last_x = my_field.figures[0].centre.x
            last_time = time.time()

        draw([my_field.figures[0]] + my_field.track[left:right + 1],
        (-my_field.figures[0].centre.x + 15, -my_field.figures[0].centre.y + 15), 
        finish = 1 << my_field.curr_turn)
    ret = my_field.figures[0].centre.x
    my_field.figures.pop()
    return ret


wight = 50
height = 30
delta_time = 0.05
figures = []
#input()
my_field = field()
results = [0] * N
new_figures = [0] * N
sums = [0] * N
start_v = vector(1, 1)
start_impulse = 200
start = point(11, 21)
for i in range(N):
#    print(i)
    figures.append(rand_figure())
    
#    draw(figures[-1:])
#    sleep(1)
#draw(figures)
#input()
while True:
    for i in range(N):
        figures[i].v_centre = start_v.resize(start_impulse / figures[i].mass)
        results[i] = take_part(my_field, figures[i], start)
        
    max1, max2 = 0, 1

    if results[0] < results[1]:
        max1, max2 = max2, max1
    for i in range(N):
        if results[i] > results[max1]:
            max2 = max1
            max1 = i
        elif results[i] > results[max2]:
            max2 = i
    new_figures[0:2] = [figures[max1], figures[max2]]
    sums[0] = int(results[0])
    
    for i in range(1, N):
        sums[i] = sums[i - 1] + int(results[i])
    i = 0
    print(results)
    while i < N - 2:
        a, b = randint(0, sums[-1] - 1), randint(0, sums[-1] - 1)
        idx1, idx2 = bin_search(a, sums), bin_search(b, sums)
#        input()
        if idx1 != idx2:
            new_figures[i + 2] = merge(figures[idx1], figures[idx2])
            i += 1
    figures = copy.copy(new_figures)
#    input()
    my_field.curr_turn += 1
        

