import math

from physics import get_v, set_v

from geometry import square, point, vector, line, \
                     angle, is_in, dist, simmetry, \
                     get_line, \
                     intersect, intersect_lines, segments_intersect

inf = point(179179179, 179179179)
vector_abcyss = vector(1, 0)
grav = vector(float(input()), float(input()))
#grav = vector(0, 0)
class object:
    def __init__(self, arg=[], mass=-1):
        self.points = arg
        self.mass = mass
        if mass == -1:  
            self.mass = square(arg)
        self.acc = grav
        self.color = "black"
        self.coeff = 1
        self.centre = sum(arg) / len(arg)
        self.v = [vector(0, 0) for i in range(len(arg))]
        self.v_centre = vector(0, 0)
        self.rotate_centre = self.centre

    def move(self, time=0, acc = (0)):
        ang = 0
        vec = vector(self.rotate_centre, self.centre)
        if self.centre != self.rotate_centre:
            
   #         print(self.rotate_centre)
            useful_v = get_v(self.v_centre, vec)
            w_vec = (useful_v[1] / dist(self.rotate_centre, self.centre))
            if vec * (vec + w_vec) < 0:
                ang = -1
            else:
                ang = 1
            w = w_vec.length()
        else:
            useful_v = (self.v_centre, vector(0))
            w = 0
        for i in range(len(self.points)):
            curr = self.points[i]
            self.points[i] = self.points[i]
            if curr != self.rotate_centre:
                self.v[i] = (vector(self.rotate_centre, curr).get_ort()).resize(w * dist(self.rotate_centre, curr))
            else:
                self.v[i] = vector(0)
            if vector(self.rotate_centre, curr) * (vector(self.rotate_centre, curr) + self.v[i]) * ang < 0:

                self.v[i] = -self.v[i]
            """
            if self.v[i] != 0 and curr != self.rotate_centre:
                self.v[i] = get_v(self.v_centre, vector(self.rotate_centre, self.centre))
                self.v[i] = (self.v[i] + vector() if curr == self.rotate_centre else \
                (time * vector(curr, self.rotate_centre).resize(
                self.v[i].lengthsq()\
                / dist(curr, self.rotate_centre)))).resize(self.v[i].length())
            """
            self.points[i] = (self.points[i] + (self.v[i] + useful_v[0]) * time)
        """
        self.v_centre = (self.v_centre + vector() if self.centre == self.rotate_centre else\
        (time * vector(self.centre, self.rotate_centre).resize(self.v_centre.lengthsq()\
        / dist(self.centre, self.rotate_centre)))).resize(self.v_centre.length()) + self.acc * time
        """
        self.centre = self.centre + self.v_centre * time
        self.acc = self.acc + acc
        self.v_centre += self.acc * time 
        self.rotate_centre = self.rotate_centre + useful_v[0] * time

        return self
    
    def square(self):
        return square(self.points)
    
    def __lt__(self, other):
        return self.centre < other.centre
    
    def __le__(self, other):
        return self.centre <= other.centre
    
    def __gt__(self, other):
        return self.centre > other.centre
    
    def __ge__(self, other):
        return self.centre >= other.centre
    
            
    def meet(self, other):
        meeted = []
        first = [0] * len(self.points)
        second = [0] * len(other.points)
        for i in range(len(self.points)):
            first[i] = is_in(self.points[i], other.points)
        for i in range(len(self.points)):
            if first[i] ^ first[i - 1]:
                meeted.append(intersect(self.points[i], self.points[i - 1], other.points))
        for i in range(len(other.points)):
            second[i] = is_in(other.points[i], self.points)
        for i in range(len(other.points)):
            if second[i] ^ second[i - 1]:
                meeted.append(intersect(other.points[i], other.points[i - 1], self.points))
#        print(meeted) 
        if len(meeted) == 0:
            return
        min_p, max_p = inf, -inf
        for i in range(len(meeted)):
            min_p = min(min_p, meeted[i])
            max_p = max(max_p, meeted[i])
        meeted = [min_p, max_p]

        if self.v != 0 or other.v != 0:
            our_impulse = self.v_centre.length() * self.mass + other.v_centre.length() * other.mass
            our_impulse *= self.coeff * other.coeff
            our_direct = (get_line(min_p, max_p)).get_ort()
            centre = (min_p + max_p) / 2
            self.v_centre = vector(centre, simmetry(self.centre, our_direct))\
                            .resize(our_impulse / (2 * self.mass))
            other.v_centre = -vector(centre, simmetry(self.centre, our_direct))\
                             .resize(our_impulse / (2 * other.mass))
            
        if self.centre > max_p:
            self.rotate_centre = max_p
        elif self.centre < min_p:
            self.rotate_centre = min_p

        if other.centre > max_p:
            other.rotate_centre = max_p
        elif other.centre < min_p:
            other.rotate_centre = min_p
        
             
            
""" Debugging raws        
a = object([point(0, 0), point(0, 1), point(1, 1), point(1, 0)])
#a.acc = vector(1, 0)
a.v = [vector(-1, 1), vector(1, 1), vector(1, -1), vector(-1, -1)]
print(a.points)
print(a.square())
print(a.centre)
print(a.v)
print("---------------")
for i in range(6283):
    a.move(0.001, vector(0, 0.00))
print(a.points)

print("---------------")

first = object([point(0, 0), point(-1, 2), point(3, 1)])
second = object([point(1, 0), point(1, 1), point(2, 1), point(2, 0)])
print(first.centre, second.centre)
first.v_centre = vector(1, 1)
print(first.points)
print(second.points)
first.meet(second)
for i in range(1000):
    first.move(0.001)
    second.move(0.001)
print('--')
print(first.points)
print(second.points)
#print(inf)
"""
