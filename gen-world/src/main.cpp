#include <iostream>
#include <string>
#include <cassert>
#include "world.h"

using namespace std;

string format = "Input format is three decimal natural numers: \n\
The first is height of the world \n\
The second is width of the world \n\
The third is depth of the world. \n\
\n\
Also you should provide output file name as first command line argument. \n\
WARNING: It would be rewritten completely.";

int main(int argc, char** argv)
{
    cout << format << endl;
    assert(argc >= 2);
    int height, width, depth;
    cin >> height >> width >> depth;
    World W(height, width, depth);
    W.Generate();
    cout << "The world is generated" << endl;
    W.WriteToFile(argv[1]);
}
