#include <Reactor.hpp>

/**
    @defgroup g1 [wrd::___LOC___::A___sector]
*/

/**
 * @defgroup g1_T wrd::___TYPE___::TERMINAL
 * @ingroup g1
*/

/**
 * @defgroup g1_R wrd::___TYPE___::REACTOR
 * @ingroup g1
*/

/**
    @defgroup g1_R_1 [wrd::___LOC___::A1___sector] [wrd::___TYPE___::REACTOR]
    @ingroup  g1_R
    \brief
        create an algorithm (via function)
        that takes string as param and returns
        string with all characters upper-cased
        @param str consists of only lower-cased characters
        @return expected return type consits of upper-cases characters
        \code{.cpp} 
        str = "abcdefgh" => [ALGORITHM] => expect_str = "ABCDEFGH"
        \endcode
*/
wString reactor_function(wString str) {
    for(unsigned i = 0; i < str.length(); i++) {
        str.at(i) -= 32;
    }
    return str;
}

int main() {

    wrd::Reactor_prcl reactor;
    reactor.connect(wrd::_REACTOR_::IMPACT_v1_2A);
    reactor.hijack(reactor_function);
    reactor.override();

}