#include <Terminal.hpp>

/**
    @defgroup g3_T_1 [wrd::___LOC___::C1___sector] wrd::___TYPE___::TERMINAL
    @ingroup  g3_T
    \brief
    create an algorithm (via function)
    that takes TripletContainer as param and returns
    sorted TripletContainer (from lowest to highest val)
    @param tr_con consists of random triplets
    @return expected sorted TripletContainer
    \code{.cpp}
        tr_con = {
            {6, 7, 2}, 
            {3, 2, 1},
            {5, 4, 1},
            {1, 2, 3},
        } => [ALGORITHM] => expec_tr = {
            {3, 2, 1},
            {1, 2, 3},
            {5, 4, 1},
            {6, 7, 2} 
        }
    \endcode
*/
TripletContainer<int> terminal_function(TripletContainer<int> tr_con) {
    std::sort(std::begin(tr_con), std::end(tr_con), [](triplet<int>& tr1, triplet<int>& tr2){
        return tr1 < tr2;
    });
    return tr_con;
}

int main() {

    wrd::Terminal_prcl terminal;
    terminal.connect(wrd::_TERMINAL_::C_303);
    terminal.hijack(terminal_function);
    terminal.override();

    return DEEPER;
}