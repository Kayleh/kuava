//#define debug

#include "Solution.h"
#include "lib/testIO.h"

using namespace std;

int main()
{
    REGISTER_CONSTRUCTOR_SOLUTION;
    REGISTER_MEMBERFUNCTION_SOLUTION(nextGreaterElements);
    while (true)
    {
        executor.constructSolution();
        executor.executeSolution();
    }
}
