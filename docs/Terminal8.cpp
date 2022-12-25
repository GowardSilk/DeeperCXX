#include <Terminal.hpp>

/**
    @defgroup g3_T_4 [wrd::___LOC___::C4___sector] wrd::___TYPE___::TERMINAL
    @ingroup  g3_T
    \brief
    create an algorithm (via function)
    that takes triplet as param and returns
    the count of 1`s occurrent in binary form of given triplet
    @param tr consists of random numbers (1 <= n <= 100)
    @return expected count
    \code{.cpp}
        tr = {1, 2, 3} => [ALGORITHM] => int count = 2
    \endcode
*/
int terminal_function(triplet<int> tr) {
    int sum = tr._triplet_unit_1 + tr._triplet_unit_2 + tr._triplet_unit_3;
    int count = 0;
    while(sum != 0) {
        if(sum % 2 == 1)
            count++;
        sum /= 2;
    }
    return count;
}

int main() {
    wrd::Terminal_prcl terminal;
    terminal.connect(wrd::_TERMINAL_::C_282);
    terminal.hijack(terminal_function);
    terminal.override();
}