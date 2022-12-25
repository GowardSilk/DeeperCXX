#include <Reactor.hpp>

/**
    @defgroup g3_R_3 [wrd::___LOC___::C3___sector] wrd::___TYPE___::REACTOR
    @ingroup g3_R
    @{
        \brief create an algorithm (via function)
        that takes string as param and returns
        boolean value, whether it is palindromatic or not
        @param str consists of only lower-cased characters
        @return expected boolean value if param str is palindromatic
        \code{.cpp}
            str = "abcde" => [ALGORITHM] => b = false
            str = "abcba" => [ALGORITHM] => b = true
        \endcode
    @}
*/
bool reactor_function(wString str) {
    for(unsigned i = 0; i < str.length()/2; i++) {
        if(str[i] != str[str.length()-1-i])
            return false;
    }
    return true;
}

int main() {

    wrd::Reactor_prcl reactor;
    reactor.connect(wrd::_REACTOR_::JAMBO_v1_9);
    reactor.hijack(reactor_function);
    reactor.override();

    return DEEPER;
}