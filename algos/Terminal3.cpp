#include <Terminal.hpp>

triplet<int> terminal_func(TripletContainer<int> tr_con) {
    triplet<int> tr = tr_con.at(0);
    for(unsigned i = 1; i < tr_con.size(); i++) {
        if(tr_con.at(i) > tr) {
            tr = tr_con.at(i);
        }
    }
    return tr;
}

int main() {

    wrd::Terminal_prcl terminal;
    terminal.connect(wrd::_TERMINAL_::B_301);
    terminal.hijack(terminal_func);
    terminal.override();

    return DEEPER;
}