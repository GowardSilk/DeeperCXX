#include <Terminal.hpp>

int calc_diff(TripletContainer<int>& tr_con, int pos) {
    return abs(tr_con.sum_at(0, std::begin(tr_con)+pos) - tr_con.sum_at(0, std::begin(tr_con)+1+pos));
}

/**
    @defgroup g2_T_3 [wrd::___LOC___::B3___sector] wrd::___TYPE___::TERMINAL
    @ingroup  g2_T
    \brief
    create an algorithm (via function)
    that takes TripletContainer as param and returns
    integer value that represents the highest difference
    between 2 following triplet values
    @param tr_con consists of random triplets
    @return expected integer value (max difference)
    \code{.cpp}
        tr_con = {
            {1, 2, 3}, 
            {3, 2, 1}, --> max_diff(first, second) = 0
            {5, 4, 1}, --> max_diff(first, second) = 4
            {6, 7, 2}  --> max_diff(first, second) = 5
        } => [ALGORITHM] => expec_int = 5
    \endcode
*/
int terminal_function(TripletContainer<int> tr_con) {
    int max_diff = calc_diff(tr_con, 0);
    for(unsigned i = 1; i < tr_con.size()-1; i++) {
        if(max_diff < calc_diff(tr_con, i))
            max_diff = calc_diff(tr_con, i);
    }
    return max_diff;
}

int main() {

    wrd::Terminal_prcl terminal;
    terminal.connect(wrd::_TERMINAL_::B_524);
    terminal.hijack(terminal_function);
    terminal.override();

    return DEEPER;
}