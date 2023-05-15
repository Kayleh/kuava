#include "Solution.h"
#include "lib/testIO.h"
#define debug

using namespace std;

int main()
{
    REGISTER_CONSTRUCTOR_SOLUTION;
    REGISTER_MEMBERFUNCTION_SOLUTION(maxEqualRowsAfterFlips);
    while (true)
    {
        executor.constructSolution();
        executor.executeSolution();
    }
}
