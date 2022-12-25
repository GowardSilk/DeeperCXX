#include <Terminal.hpp>

/**
    @defgroup g3_T_3 [wrd::___LOC___::C3___sector] wrd::___TYPE___::TERMINAL
    @ingroup  g3_T
    \brief
    create an algorithm (via function)
    that takes triplet as param and returns
    integer value that represents the binary format of the triplet
    @param tr consists of random numbers (1 <= n <= 100)
    @return expected binary value
    \code{.cpp}
        tr = {1, 2, 3} => [[to binary](1 + 2 + 3)] => int bin = 110
    \endcode
*/
int terminal_function(triplet<int> tr) {
    int sum = tr._triplet_unit_1 + tr._triplet_unit_2 + tr._triplet_unit_3;
    std::string bin;
    while(sum != 0) {
        bin = (sum % 2 == 0 ? "0" : "1") + bin;
        sum /= 2;
    }
    return std::stoi(bin);
}

int main() {
    wrd::Terminal_prcl terminal;
    terminal.connect(wrd::_TERMINAL_::C_954);
    terminal.hijack(terminal_function);
    terminal.override();
}