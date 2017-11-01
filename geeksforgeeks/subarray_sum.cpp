//http://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int t,n;
    cin>>t;
    int con_sum;
    while(t--){
        
        cin>> n >> con_sum;
        unordered_map<long long int, int> smap;
        vector<int> arr(n,0);
        long long int sum = 0;
        for(int i=0;i<=n-1;i++){
            cin>>arr[i];
        }
        bool found=false;
        for(int i=0;i<=n-1;i++){
            sum+=arr[i];
            if(sum==con_sum){
                found=true;
                cout<<1<<" "<<i+1<<endl;
                break;
            }
            smap.insert(pair<long long int,int>(sum,i+1));
            //cout<<sum<<"====="<<smap[sum]<<endl;
            if(smap.find(sum - con_sum)!=smap.end()){
                found=true;
                cout<<smap[sum-con_sum]+1<<" "<<i+1<<endl;
                break;
            }
             
        }
        if(!found){
            cout<<-1<<endl;
        }
            
    }
  return 0;
}