#include <iostream>
#include "Pieces.h"
#include "Moves.h"

using namespace std;

int main()
{
    Moves mv;
    std::cout << mv.whitePawnsMoves[36].size() << "\n";

    return 0;
}
