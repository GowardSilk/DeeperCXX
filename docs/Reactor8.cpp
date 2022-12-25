#include <Reactor.hpp>

bool contains(char &ch)
{
    const char *punctuation = "!()-[]{};:'\",<>./?@#$%^&*_~";
    for (unsigned short i = 0; i < 28; i++)
    {
        if (punctuation[i] == ch)
        {
            return true;
        }
    }
    return false;
}

///
///    @defgroup g3_R_4 [wrd::___LOC___::C4___sector] wrd::___TYPE___::REACTOR
///    @ingroup g3_R
///    \brief create an algorithm (via function)
///    that takes string as param and returns
///    string without ANY punctuation
///    (punctuation = "!()-[]{};:'\",<>./?@#$%^&*_~")
///    @param str consists of only lower-cased characters && punctuation
///    @return expected string without punctuation
///    \code{.cpp}
///        str = "abc/s!;" => [ALGORITHM] => expec_str = "abcs"
///    \endcode
///

wString reactor_function(wString str)
{
    wString new_str;
    for (char ch : str)
    {
        if (!contains(ch))
        {
            new_str.push_back(ch);
        }
    }
    return new_str;
}

int main()
{
    wrd::Reactor_prcl reactor;
    reactor.connect(wrd::_REACTOR_::PLASIA_v0_2A);
    reactor.hijack(reactor_function);
    reactor.override();

    return DEEPER;
}