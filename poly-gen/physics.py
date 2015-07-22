from geometry import *

def get_v(v, l):
    if type(l) is vector:
        l = line(l)
#    print(l)
            
    norm = l.get_normal()
    d = l.get_dist(v)
    norm = norm.resize(d)
    if not in_line(norm + v, l):
        norm = -norm
    return vector((norm + v).to_point()), -(norm)

def set_v(w, centre, p):
    return w * dist(centre, p)
    
