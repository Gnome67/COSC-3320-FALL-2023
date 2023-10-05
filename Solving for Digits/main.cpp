#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

bool isValidAssignment(const string &string1, const string &string2, const string &target, const unordered_map<char, char> &symbol_to_digit)
{
    int num1 = 0, num2 = 0, result = 0;
    for (char c : string1) { num1 = num1 * 10 + (symbol_to_digit.at(c) - '0'); }
    for (char c : string2) { num2 = num2 * 10 + (symbol_to_digit.at(c) - '0'); }
    for (char c : target) { result = result * 10 + (symbol_to_digit.at(c) - '0'); }
    return num1 + num2 == result;
}

bool backTrack(int index, const string &symbols, const string &string1, const string &string2, const string &target, unordered_map<char, char> &symbol_to_digit, vector<bool> &used_digits)
{
    if (index == symbols.size())
    {
        if (isValidAssignment(string1, string2, target, symbol_to_digit)) { return true; }
        return false;
    }
    for (char digit = '0'; digit <= '9'; ++digit)
    {
        if (!used_digits[digit - '0'])
        {
            symbol_to_digit[symbols[index]] = digit;
            used_digits[digit - '0'] = true;
            if (backTrack(index + 1, symbols, string1, string2, target, symbol_to_digit, used_digits)) { return true; }
            used_digits[digit - '0'] = false;
        }
    }
    return false;
}

string solveSymbols(const string &symbols, const string &string1, const string &string2, const string &target)
{
    unordered_map<char, char> symbol_to_digit;
    vector<bool> used_digits(10, false); 
    if (backTrack(0, symbols, string1, string2, target, symbol_to_digit, used_digits))
    {
        string result;
        for (char c : symbols) { result += symbol_to_digit[c]; }
        return result;
    }
    return nullptr;
}

int main()
{
    string symbols, string1, string2, target;
    cin >> symbols >> string1 >> string2 >> target;
    string output = solveSymbols(symbols, string1, string2, target);
    cout << output << endl;
    return 0;
}
