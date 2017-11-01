#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int BS(vector<int> &rad, float v){
    
    int low = 0;
    int high = rad.size()-1;
    if(v>rad[high])
        return rad.size()-1;
    if(v<rad[low])
        return low-1;
    while(low<high){
        int mid = (low+high)/2;
        if(rad[mid]>v){
            high = mid-1;
        }
        else if(rad[mid]<v)
            low = mid;
        else
            return mid;
    }
    return low;
}

int NoOfQ(vector<int> &rad, int x1, int y1, int x2, int y2){
    float P1 = sqrt(x1*x1  + y1*y1);
    float P2 = sqrt(x2*x2  + y2*y2);
    float disP2 = P1>P2 ? P1: P2;
    float disP1 = P1>P2 ? P2: P1;
    
    int p1 = BS(rad, disP1);
    int p2 = BS(rad, disP2);
    return abs(p2-p1);    
}


int main() {
    int c,i=0;
    cin>>c;
    vector<int> rad(c);
    while(i<c){
        cin>>rad[i];
        i++;
    }
    //sort(rad.begin(),rad.end());
    int m,x1,y1,x2,y2;
    cin>>m;
    int count = 0;
    while(m--){
        cin>>x1>>y1>>x2>>y2;
        count+= NoOfQ(rad, x1, y1, x2, y2);
    }
    cout<<count<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
