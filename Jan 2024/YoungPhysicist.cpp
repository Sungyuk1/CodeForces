#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    //memo?
    int x = 0;
    int y = 0;
    int z = 0;
    
    int n;
    cin>>n;
    for(int i = 0; i<n; ++i){
        int f_x;
        int f_y;
        int f_z;

        cin>>f_x>>f_y>>f_z;

        x+=f_x;
        y+=f_y;
        z+=f_z;
    }

    if (x==0 && y ==0 &&z==0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

}