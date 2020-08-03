---
layout: post
title: Maximum element from each sub array of size k
date: 2020-08-03 18:00
comments: true
external-url:
categories: Linear-Data-Structures
---

Example: <br><br>
Input:
{1,9,3,4,5,6},
k = 2 <br>
Output:
{9,9,4,5,6}

```cpp
vector<long long> maxOfEachSubArray(vector<long long> a, int k) {
    int n = a.size();
    vector<long long> ans;

    //Using double ended queue
    // Maximum element for current subarray stored at front
    deque<int> dq;
    dq.push_back(0);
    int c = k - 1;

    //When k = 1, need to push first element
    if (c == 0) {
        ans.push_back(a[0]);
        c++;
    }
    for (int i = 1; i < n; i++) {
        //When Deque's front element is out of scope of current subarray considered
        if (i > (dq.front() + k - 1)) {
            dq.pop_front();
        }
        /*While current element is greater than smallest elements of queue,
         remove smallest elements from queue*/
        while (!dq.empty() && a[i] > a[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);

        //Neat trick to insert max element from queue for each subarray
        if (i == c) {
            ans.push_back(a[dq.front()]);
            c++;
        }
    }
    return ans;
}

```

Encountered as a subproblem in `Equal subarrays` in [January Circuits 2020(Hackerearth)](https://www.hackerearth.com/challenges/competitive/january-circuits-20/).
