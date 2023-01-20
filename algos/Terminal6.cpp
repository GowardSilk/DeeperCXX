#include <Terminal.hpp>

triplet<int> terminal_function(TripletContainer<int> tr_con) {
    std::unordered_map<triplet<int>, int> map;
    for(triplet<int> tr : tr_con) {
        if(map[tr] != 0) {
            return tr;
        }
    }
}

int main() {
    wrd::Terminal_prcl terminal;
    terminal.connect(wrd::_TERMINAL_::C_246);
    terminal.hijack(terminal_function);
    terminal.override();
}