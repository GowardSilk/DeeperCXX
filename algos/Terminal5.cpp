#include "../Terminal.hpp"

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