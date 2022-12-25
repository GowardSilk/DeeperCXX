#include <Reactor.hpp>

/**
    @defgroup g4 [wrd::___LOC___::D___sector]
*/

/**
 * @defgroup g4_T wrd::___TYPE___::TERMINAL
 * @ingroup g4
*/

/**
 * @defgroup g4_R wrd::___TYPE___::REACTOR
 * @ingroup g4
*/


/**
    @defgroup g4_R_1 [wrd::___LOC___::D1___sector] wrd::___TYPE___::REACTOR
    @ingroup g4_R
    @{
        \brief create an algorithm (via function)
        that takes string as param and returns
        string without any integer values present
        @param str consists of only lower-cased characters and integer values
        @return expected string without integer values
        \code{.cpp}
            str = "a1b2c3" => [ALGORITHM] => expec_str = "abc"
        \endcode
    @}
*/
wString reactor_function(wString str) {
    wString new_str;
    for(const char& ch : str) {
        if(ch < 48 || ch > 57) {
            new_str.push_back(ch);
        }
    }
    return new_str;
}

int main() {

    wrd::Reactor_prcl reactor;
    reactor.connect(wrd::_REACTOR_::BEAMX_v093);
    reactor.hijack(reactor_function);
    reactor.override();

    return DEEPER;
}