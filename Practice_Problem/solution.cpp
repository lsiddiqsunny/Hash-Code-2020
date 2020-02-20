#include<bits/stdc++.h>
using namespace std;

string in_name[]={"a_example.in","b_small.in","c_medium.in","d_quite_big.in","e_also_big.in"};
string out_name[]={"a_example.out","b_small.out","c_medium.out","d_quite_big.out","e_also_big.out"};
int main(){
    for(int cs=0;cs<5;cs++){
        freopen(in_name[cs].c_str(),"r",stdin);
        freopen(out_name[cs].c_str(),"w",stdout);
        long long int m,n;
        cin>>m>>n;
        pair<long long int,int> a[n];
        for(int i=0;i<n;i++){
            cin>>a[i].first;
            a[i].second=i;
        //   cout<<a[i].first<<endl;
        }
        sort(a,a+n);

        vector<int>sol;
        for(int i=n-1;i>=0;i--){
            if(m>=a[i].first){
                sol.push_back(a[i].second);
                m-=a[i].first;
            }
        }
        sort(sol.begin(),sol.end());
        cout<<sol.size()<<endl;
        for(int i=0;i<sol.size();i++){
            cout<<sol[i]<<" ";
        }

    }
    
}