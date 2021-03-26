//双栈算术表达式求值
//*/优先级大于+-, 同样的运算符 栈内优先级高于栈外

#include <bits/stdc++.h>
using namespace std;

stack<int> num; //操作数
stack<char> op; //运算符

//对栈顶的2个数进行运算
void eval() {
    auto b = num.top(); num.pop();
    auto a = num.top(); num.pop();
    auto c = op.top(); op.pop();
    int x;
    if (c == '+') x = a + b;
    else if (c == '-') x = a - b;
    else if (c == '*') x = a * b;
    else x = a / b;

    num.push(x);
}

int main() {
    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}}; //运算符优先级
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        auto c = str[i];
        if (isdigit(c)) {
            int x = 0, j = i;
            while (j < str.size() && isdigit(str[j]))
                x = x * 10 + str[j++] - '0'; //扣出字符串中的数字
            i = j - 1;
            num.push(x);
        }
        else if (c == '(') op.push(c);
        else if (c == ')') {
            while (op.top() != '(') eval();
            op.pop(); //弹出 '('
        }
        else { //c是运算符
            while (op.size() && op.top() != '(' && pr[op.top()] >= pr[c]) eval(); //>=意思是相同优先级先算栈内
            op.push(c);
        }
    }
    while (op.size()) eval();
    cout << num.top() << endl;

    return 0;
}