#include "lib/testIO.h"
#include "lib/zSolution.h"

int main()
{
    REGISTER_CONSTRUCTOR_SOLUTION;
    REGISTER_MEMBERFUNCTION_SOLUTION(countRestrictedPaths);
    while (true)
    {
        executor.constructSolution();
        executor.executeSolution();
    }
}