#include<bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
        // map<int,int>mp;
        // for(auto x : nums)
        //     mp[x]++;
        // vector<pair<int,int>>v;
        // for(auto &x :mp)
        //     v.push_back(x);
        
        // sort(v.begin() , v.end(),cmp);
        
        // vector<int>ans;
        // int a = 0;
        // for(auto x : v){
        //     ans.push_back(x.first);
        //     a++;
        //     if(a==k) break;
            
        // }
        // return ans;

        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int,int>mp;
        for(auto x : nums)
        mp[x]++;
        for(auto x : mp){
            pq.push({x.second , x.first});
            if(pq.size() > k)
            pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

    int main(){
        vector<int>v = {1,1,1,2,2,3};
        int k = 2;
        vector<int>ans = topKFrequent(v,k);
        for(auto num:ans){
            cout<<num<<" ";
        }

    }