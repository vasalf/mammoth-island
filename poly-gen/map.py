from objects import object
from geometry import point, vector, dist
from random import randint
import math

tic = 0.01
good_dist = 30
eps = 0.001

def get_ortogon(a, b, w=1):
    vec_norm = vector(a, b).get_ort().resize(w)
    if vec_norm.y > 0:
        vec_norm = -vec_norm
    return object([a, b, b + vec_norm, a + vec_norm])


def bin_search(elem, lis, w):
    l = 0
    r = len(lis)
    while (r - l) > 1:
        m = (l + r) // 2
        if lis[m] > elem:
            r = m        
        else:
            l = m
    ans1 = 0
    ans2 = r
    while (r - ans1) > 1:
        m = (r + ans1) // 2
        if dist(lis[m].centre, elem.centre) > w:
            ans1 = m
        else:
            r = m
    r = len(lis)
    while (r - ans2) > 1:
        m = (r + ans2) // 2
        if (dist(lis[m].centre, elem.centre) > w):
            r = m
        else:
            ans2 = m
    return (ans1, ans2)
        
    
right_side = 10000
sqrt_3 = math.sqrt(3)

class map:
    def __init__(self):
        self.curr_turn = 4
        self.track = []
        self.figures = []
        l = 0
        r = 0
        am = 2
        while r < right_side:
            rad = randint(2, 2 * am)
            am += 1
            l = r
            r += 1.5 * rad
            radsq = rad * rad
            rad_const = rad - rad * sqrt_3 / 2
            if am % 2 == 0:
                
                for i in range(-rad // 2, -rad - 1, -1):
                    self.track.append(get_ortogon(point(l + rad_const - math.sqrt(radsq - i * i), i + rad // 2)
                                                  , point(l + (rad_const + 1) // 2 - math.sqrt(radsq - (i + 1) ** 2), (i + 1) + rad // 2)))
                    
                    self.track.append(get_ortogon(point(l + (rad_const + 1) // 2 + math.sqrt(radsq - i * i), i + rad // 2)
                                                  , point(l + (rad_const + 1) // 2 + math.sqrt(radsq - (i + 1) ** 2), (i + 1) + rad // 2)))
            else:
                for i in range((rad) // 2, rad):
                    self.track.append(get_ortogon(point(l + (rad_const + 1) // 2 - math.sqrt(radsq - i * i), i - rad // 2)
                                , point(l + (rad_const + 1) // 2 - math.sqrt(radsq - (i + 1) ** 2), i + 1 - rad // 2) ))
                                    
                    self.track.append(get_ortogon(point(l + (rad_const + 1) // 2 + math.sqrt(radsq - i * i), i - rad // 2)
                                , point(l + (rad_const + 1) // 2 + math.sqrt(radsq - (i + 1) ** 2), i + 1 - rad // 2)))                
        self.track.sort()
        for i in range(len(self.track)):
            self.track[i].color = "blue"
        
    def set_figure(self, figure, coords):
        vec = vector(figure.centre, coords)
        figure.centre = coords
        for i in range(len(figure.points)):
            figure.points[i] = figure.points[i] + vec
        figure.rotate_centre = figure.rotate_centre + vec
        self.figures.append(figure)
        
    def move(self, time):
        for i in range(len(self.figures)):
            left, right = bin_search(self.figures[i], self.track, good_dist)
            for j in range(left, right + 1):
                self.figures[i].meet(self.track[j])
        for i in range(len(self.figures)):
            for j in range(i + 1, len(self.figures)):
                self.figures[i].meet(self.figures[j])
        for i in range(len(self.figures)):
            self.figures[i].move(time)
            
    
a = map()
