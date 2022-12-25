#include <Reactor.hpp>

/**
    @defgroup g3_R_2 [wrd::___LOC___::C2___sector] wrd::___TYPE___::REACTOR
    @ingroup g3_R
    @{
        \brief create an algorithm (via function)
        that takes string as param and returns
        count of all vowels in given string
        @param str consists of only lower-cased characters
        @return expected number of vowel occurences of param str
        \code{.cpp}
            str = "abcde" => [ALGORITHM] => expec_int = 2
        \endcode
    @}
*/
int reactor_function(wString str) {
    const char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };
    int final_count = 0;
    for(char ch : str) {
        for(unsigned short i = 0; i < 5; i++) {
            if(vowels[i] == ch) {
                final_count++;
                break;
            }
        }
    }
    return final_count;
}

int main() {

    wrd::Reactor_prcl reactor;
    reactor.connect(wrd::_REACTOR_::BUCKLAND_EX);
    reactor.hijack(reactor_function);
    reactor.override();

    return DEEPER;
}