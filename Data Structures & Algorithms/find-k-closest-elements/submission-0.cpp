class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int n = arr.size();

        int left = -1, right = n;

        // Find first element >= x
        for (int i = 0; i < n; i++) {
            if (arr[i] < x)
                left = i;
            else {
                right = i;
                break;
            }
        }

        while (ans.size() < k) {
            if (left >= 0 && right < n) {
                if (abs(x - arr[left]) <= abs(x - arr[right])) {
                    ans.push_back(arr[left]);
                    left--;
                } else {
                    ans.push_back(arr[right]);
                    right++;
                }
            }
            else if (left >= 0) {
                ans.push_back(arr[left]);
                left--;
            }
            else if (right < n) {
                ans.push_back(arr[right]);
                right++;
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};