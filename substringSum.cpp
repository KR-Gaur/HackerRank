#include<iostream>

using namespace std;

int main(){
	
	string s = "123456";
	int count =0,total=0;
	cout<<s[s.length()]<<" "<<endl;
	for(int i=0;i<s.length();i++) {
		for(int j=0;j+i<s.length();j++){
		count = 0;
			for(int k=0;k<=j;k++){
				//cout<<s[i+k];//<<"--"<<j<<", ";
				count = count*10 + int(s[i+k]-'0');
			}
			total+=count;
		//	cout<<total;
		//cout<<endl;
		}
	}
	cout<<total<<endl;
	return 0;
}
/*
 for(int i=0; i<n; i++){
        for(int k=0; i+k<n; k++){
            c=0;
            if(k%2!=0)
            {
                for(int j=0; j<=k; j++){
              //  cout<<arr[i+j]<<"("<<k<<") ";
                if(arr[i+j]==0) c++;
                else c--;
                }
                
                if(c==0) {
                    if(max_size<k+1)
                    max_size=k+1;
                } 
                
            }
        //cout<<" ,";
    }
    //cout<<endl;
    }
*/
