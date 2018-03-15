#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

int number_needed(string a, string b) {
    int freq[36]={0};
    int alen = a.length();
    int dec[36]={0};
    
    for(int i=0;i<alen;i++)
    {
        freq[(int)a[i]-97] += 1; 
    }
   
    
    int blen = b.length();
    
    for(int i=0;i<blen;i++)
    {
        
            if(dec[(int)b[i]-97]==0)
            {
                if(freq[(int)b[i]-97]==0)
                { 
                    dec[(int)b[i]-97]=1;
                    freq[(int)b[i]-97] +=1;
                }
                else
                freq[(int)b[i]-97] -= 1;
                
            }
            else 
            freq[(int)b[i]-97] += 1;
        
       
    }
    int c=0;
    for(int i=0;i<36;i++)
    {
        c=c+freq[i];
    }
    
    return c;
   
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}

