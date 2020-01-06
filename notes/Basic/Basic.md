# Basic tricks

<br>

## Index

1 . [Excel Column to Number and vice versa](#excel-column-to-number-and-vice-versa)


---
<br>

## 1. Excel Column to Number and vice versa :

Convert Excel Column Letter to Number and Vice Versa. <br>
Eg:  ZQ  => 693  or 694 => ZR

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
