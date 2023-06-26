// ——————————————————————————————————————————————————————————————————————
#include "lib/testIO.h"
#include "Solution.h"

using namespace std;
int main()
{
    REGISTER_CONSTRUCTOR_SOLUTION;
    REGISTER_MEMBERFUNCTION_SOLUTION(findOrder);
    while (true)
    {
        executor.constructSolution();
        executor.executeSolution();
    }
    return 0;
}