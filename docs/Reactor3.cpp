#include <Reactor.hpp>

/**
    @defgroup g2_R_2 [wrd::___LOC___::B2_sector] wrd::___TYPE___::REACTOR
    @ingroup g2_R
    @{
        \brief create an algorithm (via function)
        that takes sString as param and returns
        string that contains all letters that are present
        in value and key
        @param strong_str consists of only lower-cased characters
        @return expected string that contains all letters present in key/value pair 
        \code{.cpp} 
            strong_str = {
                value = "hello world"
                key = "hlwd"
            }; => [ALGORITHM] => expec_str = "hlllwd"
        \endcode
    @}
*/
wString reactor_function(sString strong_str) {
    wString ans;
    for(unsigned i = 0; i < strong_str.value.length(); i++) {
        const char x = strong_str.value.at(i);
        for(unsigned j = 0; j < strong_str.key.length(); i++) {
            if(x == strong_str.key.at(j)) {
                ans.push_back(x);
                break;
            }
        }
    }
    return ans;
}

int main() {

    wrd::Reactor_prcl reactor;
    reactor.connect(wrd::_REACTOR_::TWINX_B);
    reactor.hijack(reactor_function);
    reactor.override();

    return DEEPER;
}