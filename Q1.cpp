#include <bits/stdc++.h>
using namespace std;
char funn(char s[]){
    int n=0;
    for(int i=0; s[i]!='\0';i++){
        n++;
    }
    int k=0;
    for(int i= n-1; i>=0; i--){
        if(!(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')){
            k++;
        }
        if(k==3)
        {
            return s[i];
        }
    }
    return '0';
}
int main()
{
    int n;
    cin>>n;
    char s[n];
    cin>>s;
    char res=funn(s);
    cout<<res;
    return 0;
}
