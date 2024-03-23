#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

//Not Pattern search algo since what we are searching for is very short with no repeats
//Search for mapie and remove the p. then searc for map and pie
int main(){
    int t;cin>>t;

    while(t--){
        int n; cin>>n;
        string s; cin>>s;

        string mapie = "mapie";
        int mapie_count = 0;
        string::size_type pos = 0;

        while ((pos = s.find(mapie, pos )) != std::string::npos) {
            ++mapie_count;
            pos += mapie.length();
        }

        string m = "map";
        int map_count = 0; 
        pos = 0; 
        while ((pos = s.find(m, pos )) != std::string::npos) {
            ++map_count;
            pos += m.length();
        }

        string pie = "pie";
        int pie_count = 0;
        pos = 0; 
        while ((pos = s.find(pie, pos )) != std::string::npos) {
            ++pie_count;
            pos += pie.length();
        }

        int ans = (map_count-mapie_count) + (pie_count - mapie_count) + mapie_count;
        cout<<ans<<endl;

    }

}