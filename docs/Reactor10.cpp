#include <Reactor.hpp>

/**
    @defgroup g4_R_2 [wrd::___LOC___::D2___sector] [wrd::___TYPE___::REACTOR]
    @ingroup  g4_R
    \brief
        create an algorithm (via function)
        that takes string as param and returns
        all string of all characters upper-cased
        @param str consists of only lower-cased characters
        @return expected return type consits of upper-cases characters
*/
bool reactor_function(wString str1, wString str2) {
    
}

int main() {

    wrd::Reactor_prcl reactor;
    reactor.connect(wrd::_REACTOR_::CITADEL_v2_2B);
    reactor.hijack(reactor_function);
    reactor.override();

    return DEEPER;
}