#include <Reactor.hpp>

bool reactor_function(wString str1, wString str2) {
    return false;
}

int main() {

    wrd::Reactor_prcl reactor;
    reactor.connect(wrd::_REACTOR_::CITADEL_v2_2B);
    reactor.hijack(reactor_function);
    reactor.override();

    return DEEPER;
}