#include "Shadow.hpp"
#include "Reactor.hpp"

triplet<int> my_func(triplet<int> tr) {
    return {0, 0, 0};
}

int main() {

    wrd::Terminal_prcl terminal;

    wrd::Shadow_prcl<triplet<int>, triplet<int>> shadow(
        {
            {{0, 0, 0}, {1, 2, 3}}, //OK
            {{0, 0, 0}, {4, 5, 6}}, //OK
            {{1, 0, 1}, {7, 8, 9}}, //shadow will warn you
            {{1, 1, 1}, {1, 3, 7}}  //look at the return of my_func
        }
    );

    shadow.append(
        {
            {{1, 1, 0}, {2, 3, 5}}, //WARNING
            {{0, 1, 1}, {23, 32, 32}} //WARNING
        }
    );

    shadow.disconnect(terminal);
    shadow.hijack(my_func);

    terminal.connect(wrd::_TERMINAL_::A);
    terminal.hijack(my_func);
    terminal.override();

    return DEEPER;
}