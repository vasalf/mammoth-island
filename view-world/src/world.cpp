#include "world.h"
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

static const int sizes_blocksize = 2 * 3;

static int read_short_int(char* buf)
{
   return ((int)(buf[0]) << 8) | ((int)(buf[1]));
}

World::World(string filename)
{
    ifstream fin;
    fin.open(filename, ios::in | ios::binary);
    char* sizes = new char[sizes_blocksize];
    assert(fin.is_open());
    fin.read(sizes, sizes_blocksize);
    height = read_short_int(sizes);
    width = read_short_int(sizes + 2);
    depth = read_short_int(sizes + 4);
    data = new char[(height * width * depth + 1) / 2];
    fin.read(data, (height * width * depth + 1) / 2);
    fin.close();
    delete[] sizes;
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
