#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<char> dna_vec;
    string dna;
    int leng;
    cin >> leng >> dna;
    for (int i = 0; i < leng; i++) dna_vec.push_back(dna[i]);

    while (dna_vec.size() > 1) {  // 크기가 1이 될 때까지 반복
        char mixChar;
        if (dna_vec.back() == 'A' && dna_vec[dna_vec.size() - 2] == 'A')
            mixChar = 'A';
        else if (dna_vec.back() == 'G' && dna_vec[dna_vec.size() - 2] == 'G')
            mixChar = 'G';
        else if (dna_vec.back() == 'C' && dna_vec[dna_vec.size() - 2] == 'C')
            mixChar = 'C';
        else if (dna_vec.back() == 'T' && dna_vec[dna_vec.size() - 2] == 'T')
            mixChar = 'T';
        else if ((dna_vec.back() == 'A' && dna_vec[dna_vec.size() - 2] == 'G') ||
                 (dna_vec.back() == 'G' && dna_vec[dna_vec.size() - 2] == 'A'))
            mixChar = 'C';
        else if ((dna_vec.back() == 'A' && dna_vec[dna_vec.size() - 2] == 'C') ||
                 (dna_vec.back() == 'C' && dna_vec[dna_vec.size() - 2] == 'A'))
            mixChar = 'A';
        else if ((dna_vec.back() == 'A' && dna_vec[dna_vec.size() - 2] == 'T') ||
                 (dna_vec.back() == 'T' && dna_vec[dna_vec.size() - 2] == 'A'))
            mixChar = 'G';
        else if ((dna_vec.back() == 'G' && dna_vec[dna_vec.size() - 2] == 'C') ||
                 (dna_vec.back() == 'C' && dna_vec[dna_vec.size() - 2] == 'G'))
            mixChar = 'T';
        else if ((dna_vec.back() == 'G' && dna_vec[dna_vec.size() - 2] == 'T') ||
                 (dna_vec.back() == 'T' && dna_vec[dna_vec.size() - 2] == 'G'))
            mixChar = 'A';
        else if ((dna_vec.back() == 'C' && dna_vec[dna_vec.size() - 2] == 'T') ||
                 (dna_vec.back() == 'T' && dna_vec[dna_vec.size() - 2] == 'C'))
            mixChar = 'G';

        // 뒤에서 두 원소 제거
        dna_vec.erase(dna_vec.end() - 2, dna_vec.end());
        // 새로운 원소 추가
        dna_vec.push_back(mixChar);
    }

    // 최종 결과 출력
    cout << dna_vec[0] << endl;

    return 0;
}
