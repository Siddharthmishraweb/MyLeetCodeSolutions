#define ll long long
class Solution {
public:
    int compareVersion(string version1, string version2) {
        queue<ll> pendingNodes1;
        queue<ll> pendingNodes2;
        ll a = 0, b = 0;
        for(ll i = 0 ; i < version1.size() ;i++){
            if(version1[i] == '.'){
                pendingNodes1.push(a);
                a = 0;
            }
            else{
                a = a * 10 + version1[i] - '0';
            }
        }
        if(a != 0) pendingNodes1.push(a);
        for(ll i = 0 ; i < version2.size() ;i++){
            if(version2[i] == '.'){
                pendingNodes2.push(b);
                b = 0;
            }
            else{
                b = b * 10 + version2[i] - '0';
            }
        }
        if(b != 0) pendingNodes2.push(b);
        while(pendingNodes1.size() < pendingNodes2.size()){
            pendingNodes1.push(0);
        }
        while(pendingNodes1.size() > pendingNodes2.size()){
            pendingNodes2.push(0);
        }
        ll size = pendingNodes2.size();
        for(int i = 0 ; i < size ; i++){
            ll first = pendingNodes1.front();
            ll second = pendingNodes2.front();
            pendingNodes1.pop();
            pendingNodes2.pop();
            if(first > second) return 1;
            if(first < second) return -1;
        }
        return 0;
    }
};