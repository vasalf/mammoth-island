#include "world.h"
#include <string>
#include <cassert>
#include <fstream>

using namespace std;

World::World(int _h, int _w, int _d)
{
    height = _h;
    width = _w;
    depth = _d;
    data = new char[(_h * _w * _d + 1) / 2];
}

static char get_first_info(char a)
{
    return (a & 0xf0) >> 4;
}

static char get_second_info(char a)
{
    return a & 0xf;
}

char World::GetField(int x, int y, int z)
{
    int index = x * height * depth + y * depth + z;
    if (index % 2)
        return get_second_info(data[index / 2]);
    else
        return get_first_info(data[index / 2]);
}

void World::SetField(int x, int y, int z, char val)
{
    int index = x * height * depth + y * depth + z;
    if (index % 2)
        data[index / 2] = (get_first_info(data[index / 2]) << 4) | val;
    else
        data[index / 2] = (val << 4) | get_second_info(data[index / 2]);
}

static char get_first_byte_of_short(int a)
{
    return (a & 0xff00) >> 8;
}

static char get_second_byte_of_short(int a)
{
    return a & 0xff;
}

void World::WriteToFile(string filename)
{
    ofstream fout;
    fout.open(filename, ios::out | ios::binary | ios::trunc);
    assert(fout.is_open());
    char _h[2], _w[2], _d[2];
    _h[0] = get_first_byte_of_short(height);
    _h[1] = get_second_byte_of_short(height);
    _w[0] = get_first_byte_of_short(width);
    _w[1] = get_second_byte_of_short(width);
    _d[0] = get_first_byte_of_short(depth);
    _d[1] = get_second_byte_of_short(depth);
    fout.write(_h, 2);
    fout.write(_w, 2);
    fout.write(_d, 2);
    fout.write(data, (height * width * depth + 1) / 2);
    fout.close(); 
}
