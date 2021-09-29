/* Question Description: To get the third last consonent of string
** all in lower case
** string in char array form
** can only make changes in the "write code here" area
Example 1 : abhishek
Output: s
Example 2 : aeioupl
Output: 0
*/
#include <bits/stdc++.h>
using namespace std;
char funn(char s[]){
    // write code here
    int n=0;
    for(int i=0; s[i]!='\0';i++){
        n++;
    }
    /*
    as in online compilers this wont work: int n= sizeof(s)/sizeof(s[0]);
    if instead of char array 'string' is given then use: int n= s.length();
    */
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
// read only
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
// Time Complexity = O[n]
