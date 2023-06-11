#include "lib/testIO.h"
#include "zSolution.h"

int main()
{
    REGISTER_CONSTRUCTOR_SOLUTION;
    REGISTER_MEMBERFUNCTION_SOLUTION(countCompleteComponents);
    while (true)
    {
        executor.constructSolution();
        executor.executeSolution();
    }
}