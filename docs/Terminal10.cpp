#include <Terminal.hpp>

bool find(unsigned& index, TripletContainer<int>& tr_con) {
    for(unsigned j = 0; j < tr_con.size(); j++) {
        if(index != j && tr_con.at(index) == tr_con.at(j)) {
            return true;
        }
    }
    return false;
}

/**
    @defgroup g4_T_2 [wrd::___LOC___::D2___sector] wrd::___TYPE___::TERMINAL
    @ingroup  g4_T
    \brief
    create an algorithm (via function)
    that takes TripletContainer as param and returns
    TripletContainer without any recurring elements
    @param tr_con consists of random triplets
    @return expected TripletContainer
    \code{.cpp}
        tr_con {
            {1, 2, 3},  //SAME
            {2, 3, 1},  //SAME
            {5, 6, 4},
            {1, 6, 2},
            {3, 2, 1}   //SAME
        } => [ALGORITHM] => expected = {
            {5, 6, 4},
            {1, 6, 2}
        }
    \endcode
*/
TripletContainer<int> terminal_function(TripletContainer<int> tr_con) {
    TripletContainer<int> new_tr_con(tr_con.size());
    for(unsigned i = 0; tr_con.size(); i++) {
        if(!find(i, tr_con))
            new_tr_con.push_back(tr_con.at(i));
    }
    return new_tr_con;
}

int main() {
    wrd::Terminal_prcl terminal;
    terminal.connect(wrd::_TERMINAL_::D_443);
    terminal.hijack(terminal_function);
    terminal.override();
}