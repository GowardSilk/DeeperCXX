#include <Shadow.hpp>
#include <Reactor.hpp>

triplet<int> my_func(triplet<int> tr) {
    return {0, 0, 0};
}

int main() {
    wrd::Terminal_prcl terminal;
    terminal.connect(wrd::_TERMINAL_::A_220);
    terminal.hijack(my_func);
    terminal.override();

    return DEEPER;
}