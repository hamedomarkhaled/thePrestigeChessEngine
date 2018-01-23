#include <iostream>
#include "Pieces.h"
#include "Moves.h"

using namespace std;

int main()
{
    Moves mv;
    std::cout << mv.whitePawnsMoves[28].size() << "\n";
    for(int i = 0; i < (int)mv.whitePawnsMoves[28].size();++i)
        std::cout << mv.whitePawnsMoves[28][i] << "\n";

    return 0;
}
