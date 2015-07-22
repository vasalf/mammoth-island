import math


eps = 0.001


class point:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __lt__(self, other):
        return (self.x < other.x or self.x == other.x and self.y < other.y)
    
    def __le__(self, other):
        return (self.x < other.x or self.x == other.x and self.y <= other.y)

    def __eq__(self, other):
        return (abs(self.x - other.x) < eps and abs(self.y - other.y) < eps)

    def __ne__(self, other):
        if type(other) is point:
            return not(self == other)
        else:
            return True

    def __gt__(self, other):
        return other < self

    def __ge__(self, other):
        return other <= self
    
    def __hash__(self):
        return hash((self.x, self.y))
    
    def __add__(self, other):
        if type(other) is point:
            return point(self.x + other.x, self.y + other.y)
        elif other == 0:
            return point(self.x, self.y)
        else:
            return NotImplemented
    
    def __radd__(self, other):
        if type(other) is point:    
            return point(self.x + other.x, self.y + other.y)
        elif other == 0:
            return point(self.x, self.y)
        else:
            return NotImplemented

    def __truediv__(self, other):
        if type(other) is int or type(other) is float:
            return point(self.x / other, self.y / other)
        else:
            return NotImplemented

    def __repr__(self):
        return ("(%f ; %f)" % (self.x, self.y))

    def __neg__(self):
        return point(-self.x, -self.y)

def dist(a, b):
    return math.sqrt((a.x - b.x) ** 2 + (a.y - b.y) ** 2)

def square(points):
    ans = 0
    for i in range(-1, len(points) - 1):
        ans += vector(points[i]) * vector(points[i + 1])
    return abs(ans)

def angle(a, b, c):
    return math.atan2(vector(b, a) * vector(b, c), vector(b, a) % (vector(b, c)))

def is_in(a, points):
    ans = 0
    for i in range(-1, len(points) - 1):
        ans += angle(points[i], a, points[i + 1])
    return abs(ans) > eps


class vector:
    def __init__(self, x=0, y=0):
        if type(x) is point:
            if (type(y) is point):
                self.x = y.x - x.x
                self.y = y.y - x.y
            else:
                self.x = x.x
                self.y = x.y
        else:
            self.x = x
            self.y = y
    
    def __mul__(self, other):

        if type(other) is vector or type(other) is point:
            return self.x * other.y - self.y * other.x
        elif type(other) is int or type(other) is float:
            return vector(self.x * other, self.y * other)
        else:
            return NotImplemented
    
    def __rmul__(self, other):  
        if type(other) is vector or type(other) is point:
            return self.x * other.y - self.y * other.x
        elif type(other) is int or type(other) is float:
            return vector(self.x * other, self.y * other)
        else:
            return NotImplemented
    
    def to_point(self):
        return point(self.x, self.y)
    
    def length(self):
        return math.sqrt(self.x * self.x + self.y * self.y)

    def lengthsq(self):
        return self.x * self.x + self.y * self.y

    def resize(self, other):
        
        return vector((self.x / (self).length()) * other, (self.y / (self).length()) * other)

    def __mod__(self, other):
        return self.x * other.x + self.y * other.y

    def __add__(self, other):
        if type(other) is vector:
            return vector(self.x + other.x, self.y + other.y)
        elif type(other) is point:
            return point(self.x + other.x, self.y + other.y)
        elif other == 0:
            return vector(self.x, self.y)
        else:
            return NotImplemented
     
    def __radd__(self, other):
        if type(other) is vector:
            return vector(self.x + other.x, self.y + other.y)
        elif type(other) is point:
            return point(self.x + other.x, self.y + other.y)
        else:
            return NotImplemented

    def __neg__(self):
        return vector(-self.x, -self.y)

    def __sub__(self, other):
        return self + (-other)
    
    def __rsub__(self, other):
        return other + (-self)
    
    def __truediv__(self, other):
        return vector(self.x / other, self.y / other)

    def __repr__(self):
        return ("(" + str(self.x) + " ; " + str(self.y) + ")")
    
    def __ne__(self, other):
        if type(other) is vector:
            return self.x != other.x or self.y != other.y
        elif other == 0:
            return self.x != 0 or self.y != 0
        else:
            
            return True
        
    def get_ort(self):
        return vector(-self.y, self.x)
    
    

class line:
    def __init__(self, a = 0, b = 0, c = 0):
        if type(a) is vector:
            self.c = 0
            self.a = a.y
            self.b = -a.x
        else:
            self.a = a
            self.b = b
            self.c = c
            
    def point_on_line(self):
        if self.a == 0:
            if self.b == 0:
                return point(0, 0)
            return point(0, -self.c / self.b)
        
        else:
            return point(-self.c / self.a, 0)
        
    def get_ort(self):
        p = self.point_on_line()
        v = self.get_normal()
        return get_line(p, p + v)
    
    def get_normal(self):
        return vector(self.a, self.b)
    

    def get_dist(self, p):
        if self.a == 0 and self.b == 0:
            self.a = -1
            self.b = 1
            self.c = 0

        return abs(p.x * self.a + p.y * self.b + self.c) / math.sqrt(self.a * self.a + self.b * self.b)
        
    def __repr__(self):
        return "| %f * x + %f * y + %f = 0 |" % (self.a, self.b, self.c)
    
    
def get_line(a, b):
    res = line()
    if type(a) is point and type(b) is point:
        if a == b:
            res.a == -1
            res.b == 1
            res.c == 0
        else:
            res.a = b.y - a.y
            res.b = a.x - b.x
            res.c = a.y * b.x - b.y * a.x
    return res

def intersect_lines(a, b):
    if a.b * b.a == a.a * b.b:
        return None
    else:
        return point(-a.b * b.c + b.b * a.c, a.a * b.c - b.a * a.c) / (a.b * b.a - a.a * b.b)

def segments_intersect(a, b, c, d):
    vec_ab, vec_ac, vec_ad, vec_ca, vec_cb, vec_cd = vector(a, b), vector(a, c), vector(a, d), vector(c, a), vector(c, b), vector(c, d)
    res1 = (vec_ac * vec_ab) * (vec_ab * vec_ad)
    res2 = (vec_ca * vec_cd) * (vec_cd * vec_cb)
    if res1 > 0 or res2 > 0:
        if res1 >= 0 and res2 >= 0:
            return intersect_lines(get_line(a, b), get_line(c, d))
    if res1 < 0 or res2 < 0:
        return None
    else:
        if vec_ac % vec_ad <= 0:
            return a
        if vector(b, c) % vector(b, d) <= 0:
            return b
        if vec_cb % vec_ca <= 0:
            return c
        return None
        

    

def in_line(p, l):
    return l.get_dist(p) < eps

def simmetry(p, l):
    d = l.get_dist(p)
    ort = vector(l.a, l.b)
    ort.resize(d)
    if in_line((p + ort), l):
        return p + 2 * ort
    else:
        return p - 2 * ort
        

def intersect(a, b, points):
    for i in range(-1, len(points) - 1):
        res = segments_intersect(a, b, points[i], points[i + 1])
        if res != None:
            return res

