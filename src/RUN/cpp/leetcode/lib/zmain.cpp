#include "testIO.h"
#include "../zSolution.h"

#define DEBUG

int main() {
    REGISTER_CONSTRUCTOR_SOLUTION;
    REGISTER_MEMBERFUNCTION_SOLUTION(change);
    while (true) {
        executor.constructSolution();
        executor.executeSolution();
    }
}