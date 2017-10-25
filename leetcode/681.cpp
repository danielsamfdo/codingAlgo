
/*https://leetcode.com/problems/next-closest-time/description/*/
class Solution {
public:
    int convertToInt(string s){
       //int res;
       return (s[0]-'0')*600 +  (s[1]-'0')*60 + (s[3]-'0')*10 + (s[4]-'0');
    }
    
    int nextbiggest(int time, unordered_set<int> &digits, int maxi){
        vector<int> ans;
        unordered_set<int>::iterator it, it2;
        for(it=digits.begin(); it!=digits.end(); it++){
            for(it2 = digits.begin();it2!=digits.end();it2++){
                
                    int x = (*it)*10 + (*it2);
                    if(x<maxi)
                        ans.push_back(x);
                
            }
        }
        bool camein =false;
        int res = 70;
        //cout<< time << endl;
        for(int i=0;i<ans.size();i++){
            //cout<<ans[i]<<"  ";
            if(ans[i]>time){
                if(!camein){
                    res = ans[i];
                    camein = true;
                }else{
                    res = min(res, ans[i]);
                }
            }
        }
        //cout<<endl;
        if(!camein)return -1;
        return res;
    }
    
    string nextbigTime(int time, unordered_set<int> digits){
        int nextmin = nextbiggest(time%60, digits, 60);
        //cout<<"NEXT MIN"<<endl;
        if(nextmin!=-1){
            return toTime((time/60)*60 + nextmin);
        }
        //cout<<"NEXT HR"<<endl;
        
        int nexthr = nextbiggest(time/60, digits, 24);
        
        int mini = 100;
        for(auto it=digits.begin();it!=digits.end();it++){
            mini = min(mini, *it);
        }
        if(nexthr!=-1){
            //cout<<"NEXT MIN"<<endl;
            
            //nextmin = nextbiggest(0,digits,60);
            return toTime(nexthr*60 + (mini*10+mini));
        }
        return toTime(((mini*10+mini)*60) + (mini*10+mini));
    }
    
    string toTime(int time){
        int min = time%60;
        string minpt = to_string(min);
        if(min<10) minpt = "0"+to_string(min);
        int hr = time/60;
        string hrpt = to_string(hr);
        if(hr<10) hrpt = "0"+to_string(hr);
        return hrpt+":"+minpt;
    }
    
    string nextClosestTime(string time) {
        unordered_set<int> digits;
        digits.insert(time[0]-'0');
        digits.insert(time[1]-'0');
        digits.insert(time[3]-'0');
        digits.insert(time[4]-'0');
        return nextbigTime(convertToInt(time), digits);
        
    }
};