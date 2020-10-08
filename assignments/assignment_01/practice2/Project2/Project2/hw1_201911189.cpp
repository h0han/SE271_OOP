/////////////////////////////////////////////////////////
// SE271 - Assignment 1: Source file
// 0. Rename this file with your ID: "hw1_YOURSTUDENTID.cpp"
// 1. Implement each function 
/////////////////////////////////////////////////////////

#include "hw1.h"
#include <iostream>

int count_odd(const unsigned int* array, int size) {
    int cnt = 0;
    int i; // for loop
    for (i = 0; i < size; i++) {
        if (array[i]%2 != 0) {
            cnt += 1;
        }
    }
    return cnt;
}

int normalize(double* array, int size) {
    double max = array[0]; double min = array[0];
    int i; int j; int k; // for loop
    for (i = 0; i < size; i++) {
        if (max < array[i]) {
            max = array[i];
        }
    }

    for (j = 0; j < size; j++) {
        if (min > array[j]) {
            min = array[j];
        }
    }

    for (k = 0; k < size; k++) {
        if ((max - min) == 0) {
            return 0;
        }
        array[k] = (array[k] - min) / (max - min);
    }
    return 1;
}

int find_nth(const int* array, int size, int n) {
    int* arr = new int[size];
    int max_idx; int tmp;
    int i; int j; int k;
    for (k = 0; k < size; k++) {
        arr[k] = array[k];
    }

    for (i = 0; i < size - 1; i++) {
        max_idx = i;

        for (j = i + 1; j < size; j++) {
            if (arr[max_idx] < arr[j]) {
                max_idx = j;
            }
        }
        tmp = arr[max_idx];
        arr[max_idx] = arr[i];
        arr[i] = tmp;
    }

    if ((n < 1) | (n > size)) {
        return 0;
    }
    return arr[n - 1];
    delete[] arr;
}

int count_pattern(const char* str, const char* pattern) {
    int cnt = 0; int incnt=0;
    int i = 0; int j = 0; int k; int l; int m; // for loop
    int strLen = 0; int patternLen = 0;
    while (true) {
        if (str[i] == '\0') {
            break;
        }
        i += 1;
        strLen += 1;
    }

    while (true) {
        if (pattern[j] == '\0') {
            break;
        }
        j += 1;
        patternLen += 1;
    }

    if ((strLen - patternLen) == 0) { // 문자열과 패턴의 길이가 같은 경우
        for (l = 0; l < strLen; l++) {
            if (str[l] == pattern[l]) {
                cnt += 1;
            }
        }
        if (cnt == strLen) {
            return 1;
        }
    }
    
    for (k = 0; k < (strLen-patternLen)+1; k++) {
        incnt = 0; // 문자열과 패턴의 일치 문자 수
        for (m = k; m < k+patternLen; m++) {
            if (str[m] == pattern[m-k]) {
                incnt += 1;
            }
        }
        if (incnt == patternLen) { // 일치 문자 수가 패턴의 길이와 같으면
            cnt += 1;
        }
    }
    return cnt;
}

char* create_shortest_palindrome(const char* src, char* dst) {
    int i = 0; int j; int srclen = 0;

    while (true) {
        if (src[i] == '\0') {
            break;
        }
        i += 1;
        srclen += 1;
    }

    char dst2[100] = { 0 }; // reverse src

    for (j = srclen - 1; j >= 0; j--) {
        dst2[srclen - 1 - j] = src[j];
    }

    int l;
    for (l = 0; l < srclen; l++) {
        int match = 0;
        int m = 0;
        int clonel = l; // clone l
        while ((m < srclen - l) && (clonel < srclen)) {
            if (src[clonel] == dst2[m]) {
                match++; m++; clonel++;
            }
            else break;
        }
        if (match == srclen - l) {
            int n;
            for (n = 0; n < srclen - match; n++) {
                dst[n] = src[n];
            }
            for (int k = 0; k < srclen; k++) {
                dst[n + k] = dst2[k];
            }
            dst[2*srclen-match] = '\0';
            return dst;
        }
    }
}

#ifdef SE271_HW1
int main() {
    using std::cout;
    using std::endl;

    // Problem 1
    unsigned int a[] = { 1, 1, 2, 3, 4 };
    std::size_t size_a = sizeof(a) / sizeof(int);
    cout << "Problem 1: " << count_odd(a, (int)size_a) << endl;

    // Problem 2
    double b[] = { 1, 2, 2, 3, 2 };
    std::size_t size_b = sizeof(b) / sizeof(double);
    normalize(b, (int)size_b);
    cout << "Problem 2: ";
    for (unsigned int i = 0; i < size_b; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;

    // Problem 3
    int c[] = { 1, 5, 3, 2, 4 };
    cout << "Problem 3: " << find_nth(c, sizeof(c) / sizeof(int), 0) << endl;
    int c1[] = { 1, 5, 3, 2, 4 };
    cout << "Problem 3: " << find_nth(c1, sizeof(c1) / sizeof(int), 2) << endl;
    int c2[] = { 1, 5, 3, 2, 4 };
    cout << "Problem 3: " << find_nth(c2, sizeof(c2) / sizeof(int), 6) << endl;

    // Problem 4
    cout << "Problem 4: ex1) " << count_pattern("AAABBBBAAA", "AA") << endl;
    cout << "Problem 4: ex2) " << count_pattern("AABBBBAA", "BB") << endl;
    cout << "Problem 4: ex3) " << count_pattern("ABABABABA", "AB") << endl;


    // Problem 5
    char d[100] = { 0 };
    cout << "Problem 5: ex0) " << create_shortest_palindrome("AB", d) << endl;
    cout << "Problem 5: ex0) " << create_shortest_palindrome("AA", d) << endl;
    cout << "Problem 5: ex1) " << create_shortest_palindrome("ABA", d) << endl;
    cout << "Problem 5: ex2) " << create_shortest_palindrome("AAB", d) << endl;
    cout << "Problem 5: ex3) " << create_shortest_palindrome("AABB", d) << endl; 
    cout << "Problem 5: ex3) " << create_shortest_palindrome("abcba", d) << endl;
    cout << "Problem 5: ex4) " << create_shortest_palindrome("AABBDDD", d) << endl;
    cout << "Problem 5: ex5) " << create_shortest_palindrome("ABCDBBABB", d) << endl;
    cout << "Problem 5: ex5) " << create_shortest_palindrome("CDCDC", d) << endl;
    cout << "Problem 5: ex5) " << create_shortest_palindrome("ABABABABABAB", d) << endl;

    return 0;
}
#endif