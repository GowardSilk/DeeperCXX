#include <DEEP_EYE.hpp>

//single-character decode
#define DEC(c)	(((c) - ' ') & 077)

char outdec(char* bp, int n) {
    int c1, c2, c3;
	c1 = DEC(*bp) << 2 | DEC(bp[1]) >> 4;
	c2 = DEC(bp[1]) << 4 | DEC(bp[2]) >> 2;
	c3 = DEC(bp[2]) << 6 | DEC(bp[3]);
	if (n >= 1)
		return c1;
	if (n >= 2)
		return c2;
	if (n >= 3)
		return c3;
}

void from_uu(std::string& input) {
    std::string output;
    int n = DEC(input[0]);
    //calculate expected # of chars and pad if necessary
    int expected = ((n+2)/3)<<2;
    std::cout << expected << std::endl;
    for (int i = input.length()-1; i <= expected; i++) input[i] = ' ';

    char* bp = &input[1];
    while (n > 0) {
        output += outdec(bp, n);
        bp += 4;
        n -= 3;
    }

    input = output;
}

int main() {
    wrd::Log log;

    wrd::DeepEye::LOG_extract(log, wrd::TXT::FBR_26_2049_4);

   //BLACK BOX
    CodeMatrix letter_map = log.getCodeMatrix();
    wString text = log.getText(), num, final;
    for(char& ch : text) {
        if(ch != ';') {
            num += ch;
        }
        else {
            final.push_back(
                letter_map.get_symbol(std::stoi(num))
            );
            num.clear();
        }
    }
    from_uu(final);
    log.setText(final);

    wrd::DeepEye::read(log);
}