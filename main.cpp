#include <iostream>
#include <map>

using std::cout;
using std::endl;
using std::string;

void eraseEmptyEntriesFromMap(std::map<char, int> &out) {
    for (auto it = out.begin(), next_it = it; it != out.end(); it = next_it) {
        ++next_it;
        if (it->second == 0) out.erase(it);
    }
}

bool isAnagramEqual(const string &first, const string &second) {
    std::map<char, int> frequency;

    for (int i = 0; i < first.length(); ++i) {
        frequency[first[i]]++;
        frequency[second[i]]--;
    }
    // Удаляем все записи, у которых value == 0
    eraseEmptyEntriesFromMap(frequency);
    // Если нет элементов - значит сравниваемые слова одинаковы
    return frequency.empty();
}

int main() {
    string first = "TirstSecondThirdF";
    string second = "FirstSecondThirdT";
    if (first.length() != second.length()) cout << false << endl;
    else cout << std::boolalpha << isAnagramEqual(first, second) << endl;
}
