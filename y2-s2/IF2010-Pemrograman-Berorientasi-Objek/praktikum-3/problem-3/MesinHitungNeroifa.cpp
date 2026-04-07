#include "MesinHitungNeroifa.hpp"
#include "MesinHitungException.hpp"

#include <cctype>
#include <sstream>
#include <stack>
using namespace std;

MesinHitungNeroifa::MesinHitungNeroifa() {}

int MesinHitungNeroifa::hitung(const string &ekspresi) const {
    stack<int> st;
    stringstream ss(ekspresi);
    string token;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (st.size() < 2) {
                throw InsufficientOperandException();
            }

            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();

            int result = 0;
            if (token == "+") {
                result = operand1 + operand2;
            } else if (token == "-") {
                result = operand1 - operand2;
            } else if (token == "*") {
                result = operand1 * operand2;
            } else {
                if (operand2 == 0) {
                    throw DivisionByZeroException();
                }
                result = operand1 / operand2;
            }

            st.push(result);
        } else {
            bool valid = true;
            int startIdx = 0;

            if (token.empty()) {
                valid = false;
            } else if (token[0] == '-') {
                if (token.size() == 1) {
                    valid = false;
                } else {
                    startIdx = 1;
                }
            }

            for (int i = startIdx; valid && i < static_cast<int>(token.size());
                 i++) {
                if (!isdigit(static_cast<unsigned char>(token[i]))) {
                    valid = false;
                }
            }

            if (!valid) {
                throw InvalidTokenException(token);
            }

            st.push(stoi(token));
        }
    }

    if (st.size() != 1) {
        throw InvalidExpressionException();
    }

    return st.top();
}
