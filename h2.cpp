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

#include <string.h>

using namespace std;

struct node
{
    char r;
    struct node *ptr[26];
};
struct node* mroot= new struct node;

//root->r='*';

void add(string contact)
{
    int clen = contact.length();
    struct node* root = mroot;
    
    for(int i =0;i<clen;i++)
    {
        if(root->ptr[contact[i]-97]== NULL)
        {
            root->ptr[contact[i]-97] = new node;
            
            //cout<<"*"<<contact[i];
            root = root->ptr[contact[i]-97];
            
        }
        else
        {
            root = root->ptr[contact[i]-97];
            //cout<<contact[i];
        }
    }
    root->r='*';
}

int find(struct node *root)
{
    int scount =0;
   // cout<<"\ncall to find\n";
    
            if(root->r=='*')
                       scount++;
                for(int i =0;i<26;i++)
                {
                     if(root->ptr[i]!=NULL)
                       scount = scount + find(root->ptr[i]);
                   
                }            
           
    return scount;
    
}

int main(){
    long long n;
    cin >> n;
    for(long a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        if(op=="add")
        {
            add(contact);
            //cout<<"\nfor--"<<contact<<endl;
        }
        else if(op=="find")
        {
          //  cout<<"\nfinding---"<<contact<<endl;
            int clen = contact.length();
            int scount =0;
            struct node* root = mroot;
            int i=0;
            for( i =0;i<clen;i++)
            {
                if(root->ptr[contact[i]-97]!=NULL)
                {
                    root = root->ptr[contact[i]-97];
              //      cout<<contact[i];
                }
                
                else
                    break;

            } 
            if(i==clen)
            {
              //  cout<<"\nperfect match\n";
                if(root->r=='*')
                       scount++;
                for(int i =0;i<26;i++)
                {
                   if(root->ptr[i]!=NULL)
                   {
                       
                   //     cout<<endl<<scount<<"--before\n";
                       scount = scount + find(root->ptr[i]);
                  //     cout<<endl<<scount<<"--after\n";
                       
                   }
                }            
            }
            else
                scount =0;

            //return count+1;
                    cout<<scount<<endl;
                }

        
       
    }
    /*struct node * ro =mroot;
    
    
    ro=ro->ptr[(int)'s'-97];    
    if(ro->r =='*')
            cout<<ro->r;
    cout<<'s';
    
    ro=ro->ptr[(int)'a'-97];    
    if(ro->r =='*')
            cout<<ro->r;
    cout<<'a';
    ro=ro->ptr[(int)'a'-97];    
    if(ro->r =='*')
            cout<<ro->r;
    cout<<'a';
    
    if(ro->ptr[(int)'s'-97] ==NULL)
        cout<<"\nrrrr";
    
    cout<<"ahsdahs"<<mroot->r;*/
    return 0;
}

