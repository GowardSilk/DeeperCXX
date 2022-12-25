#include <Reactor.hpp>

/**
    @defgroup g2 [wrd::___LOC___::B___sector]
*/

/**
 * @defgroup g2_T wrd::___TYPE___::TERMINAL
 * @ingroup g2
*/

/**
 * @defgroup g2_R wrd::___TYPE___::REACTOR
 * @ingroup g2
*/

/**
    @defgroup g2_R_1 [wrd::___LOC___::B1___sector] wrd::___TYPE___::REACTOR
    @ingroup g2_R
    \brief 
    create an algorithm (via function)
    that takes string as param and returns
    string with all characters` height reversed
    (lower-case -> upper-case && vice versa)
    @param str consists of characters of random height
    @return expected string with all characters` height reversed
    \code{.cpp} 
        str = "aBcDe" => [ALGORITHM] => expec_str = "AbCdE"
    \endcode
*/
wString reactor_function(wString str) {
    for(unsigned i = 0; i < str.length(); i++) {
        if(islower(str.at(i)))
            str.at(i) -= 32;
        else
            str.at(i) += 32;
    }
    return str;
}

int main() {

    wrd::Reactor_prcl reactor;
    reactor.connect(wrd::_REACTOR_::IMPACT_v0_9);
    reactor.hijack(reactor_function);
    reactor.override();

    return DEEPER;
}