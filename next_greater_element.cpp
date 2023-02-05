#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>mp;
       stack<int>st;
       for(int i = nums2.size()-1;i>=0;i--){
          while(!st.empty() && st.top() <= nums2[i]){
              st.pop();
          }
          if(st.empty()){
              mp[nums2[i]] = -1;
          }
          else{
              mp[nums2[i]] = st.top();
          }
          st.push(nums2[i]);
       }

       for(auto x : nums1){
           if(mp.find(x) != mp.end()){
               ans.push_back(mp[x]);
           }
       }

       return ans;
    }
    int main(){
        vector<int>nums1 = {4,1,2};
        vector<int>nums2 = {1,3,4,2};
        vector<int>ans = nextGreaterElement(nums1,nums2);

        for(auto x : ans)
        cout<<x<<" ";
    }