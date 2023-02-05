
#include<bits/stdc++.h>
using namespace std;

 int largestRectangleArea(vector<int>& heights) {

    //////////////////////////////METHOD-1 using to stack/////////////////////////////////
        // stack<int>st;
        // int n = heights.size();

        // vector<int>leftsmall(n,-1),rytsmall(n , n);
        // for(int i=0;i<n;i++){
        //     while(!st.empty() && heights[st.top()] >= heights[i]){
        //             st.pop();
        //     }
        //     if(!st.empty()){
        //         leftsmall[i] = st.top();
        //     }
        //     st.push(i);
        // }
        // while(!st.empty()) st.pop();

        // for(int i = n-1 ; i>= 0;i--) {
        //     while(!st.empty() && heights[st.top()] >= heights[i]){
        //         st.pop();
        //     }
        //     if(!st.empty()){
        //         rytsmall[i] = st.top();
        //     }
        //     st.push(i);

        // }
        // int ans = 0;
        // for(int i=0;i<n;i++){
        //     ans = max(ans , heights[i]*(rytsmall[i]-leftsmall[i]-1));
        // }
        // return ans;

        //////////////////MEthod 2

        int maxA = 0;
        int n = heights.size();
        stack<int>st;

        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()] >= heights[i])){
                int height = heights[st.top()];
                st.pop();
                int width ;
                if(st.empty()) width = i;
                else width = i-st.top()-1;
                maxA = max(maxA , width*height);

            }
            st.push(i);
        } 

        return maxA;
        
    }

    int main() {
        vector<int>v = {2,1,5,6,2,3};
        int ans = largestRectangleArea(v);
        cout<<ans;
    }