---
layout: post
title: Excel Column to Number and vice versa
date: 2020-08-03 18:00
comments: true
external-url:
categories: Basic
---

Convert Excel Column Letter to Number and Vice Versa. <br><br>
Eg: ZQ => 693 or 694 => ZR

```cpp
string colNumberToLetter(int col) {
    string ans;
    while (col) {
        if (col % 26 == 0)
        {
            ans += 'Z';
            col /= 26;
            col--;
        }
        else
        {
            ans += (char)('A' + col % 26 - 1);
            col /= 26;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int colLetterToNumber(string col) {
    int ans = 0;
    for (auto c : col) {
        ans = ans * 26 + (c - 'A' + 1);
    }
    return ans;
}

```
