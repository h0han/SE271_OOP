/////////////////////////////////////////////////////////////
// Object Oriented Programming - SE271 | Fall 2020 | Final //
/////////////////////////////////////////////////////////////

#include "ProblemD.h"

BinNum::BinNum(std::vector<char> str) {
	value = 0;
	int size = str.size();
	for (size_t i = 0; i < str.size(); ++i) {
		if (str[size - i - 1] == '1') {
			int v = 1;
			for (size_t j = 0; j < i; ++j) {
				v *= 2;
			}
			value += v;
		}
	}
}

std::ostream& operator<<(std::ostream& o, BinNum c) {
	if (c.value == 0) {
		o << "0";
	} else {
		int v = c.value;
		std::string ret = "";
		while (v > 0) {
			if (v % 2 == 0)
				ret = "0" + ret;
			else
				ret = "1" + ret;
			v /= 2;
		}
		o << ret;
	}
	return o;
}

static bool isOp(const char& c) {
    char ops[] = { '+', '-', '*', '/' };
    for (auto o : ops) {
        if (o == c)
            return true;
    }
    return false;
}


std::vector<std::string> parse_eq(std::string str) {
    std::vector<std::string> ret;

	std::string::iterator curPos = str.begin();
    while (curPos != str.end()) {
        auto nextPos = std::find_if(curPos, str.end(), isOp);
        ret.push_back(std::string(curPos, nextPos));
        if (nextPos != str.end()) {
            ret.push_back(std::string(nextPos, nextPos + 1));
            ++nextPos;
        }
		curPos = nextPos;
    }

    return ret;
}
