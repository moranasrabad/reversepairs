#include <vector>
#include <iostream>
using namespace std;
class int2 {
public:
    int a;
    int b;
};
class Solution {
public:
    int ans = 0;
        std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> ReversePairs;
  // store indices of reverse pairs

    void merge(vector<int2> &a, int low, int mid, int high) {
        int k = high - low + 1;
        vector<int2> temp(k);
        
        int i = low, j = mid + 1;
        k = 0;
        int first = mid + 1;
        while (i <= mid) {
            while (first <= high && a[first].a * 2 < a[i].a) {
                first++;
            }
            while (j <= high && a[j].a <= a[i].a) {
                temp[k] = a[j];
                j++;
                k++;
            }
            ans += first - (mid + 1);
            for (int idx = mid + 1; idx < first; idx++) {
            ReversePairs.push_back({{a[i].a, a[idx].a},{a[i].b,a[idx].b}}); // store indices of reverse pairs
            }
            temp[k] = a[i];
            i++;
            k++;
        }
        while (j <= high) {
            temp[k] = a[j];
            k++;
            j++;
        }
        k = 0;
        for (int i = low; i <= high; i++) {
            a[i] = temp[k];
            k++;
        }
    }

    void calc(vector<int2> &a, int low, int high) {
        if (low >= high) return;
        int mid = low + (high - low) / 2;
        calc(a, low, mid);
        calc(a, mid + 1, high);
        merge(a, low, mid, high);
    }

    int solve(vector<int2> &A) {
        ans = 0;
        int n = A.size();
        calc(A, 0, n - 1);
        return ans;
    }
};
void main() {
    Solution ob;
    vector<int> v;
    int n;
    std::cout<<"enter the length of your array : ";
    std::cin>>n;
    vector<int2> test;
    for(int i=0;i<n;i++){
        int2 temp;
        std::cin>>temp.a;
        temp.b=i;
        test.push_back(temp);
        
    }
    int cnt = ob.solve(test);
    std::cout << "The number of reverse pairs is: " << cnt << endl;
    std::cout << "The reverse pairs are: " << endl;
        for (auto &pair : ob.ReversePairs) {
        std::cout << "[" << pair.first.first << ", " << pair.first.second << "]" <<" | ";
        std::cout << "(" << pair.second.first << ", " << pair.second.second << ")" << endl;
    }
}