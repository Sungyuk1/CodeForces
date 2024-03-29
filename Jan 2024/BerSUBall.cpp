#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;

/*The Berland State University is hosting a ballroom dance in celebration of its 100500-th anniversary! n boys and m girls are already busy rehearsing waltz, minuet, polonaise and quadrille moves.

We know that several boy&girl pairs are going to be invited to the ball. However, the partners' dancing skill in each pair must differ by at most one.

For each boy, we know his dancing skills. Similarly, for each girl we know her dancing skills. Write a code that can determine the largest possible number of pairs that can be formed from n boys and m girls.

Input
The first line contains an integer n (1 ≤ n ≤ 100) — the number of boys. The second line contains sequence a1, a2, ..., an (1 ≤ ai ≤ 100), where ai is the i-th boy's dancing skill.

Similarly, the third line contains an integer m (1 ≤ m ≤ 100) — the number of girls. The fourth line contains sequence b1, b2, ..., bm (1 ≤ bj ≤ 100), where bj is the j-th girl's dancing skill.

Output
Print a single number — the required maximum possible number of pairs.*/

//Greedy Approach with pointer. If we sort the boys skills and girls skills, movbe the pointer to the one with the smaller skill. If we move the pointer of the bigger skill the gap just gets bigger. lee
int main()
{
    int number_boys;
    vector<int> boys_skills;

    cin >>number_boys;

    for(int i = 0; i<number_boys; ++i){
        int skill;
        cin>>skill;
        boys_skills.push_back(skill);
    }

    int number_girls;
    vector<int> girls_skills;

    cin >>number_girls;

    for(int i = 0; i<number_girls; ++i){
        int skill;
        cin>>skill;
        girls_skills.push_back(skill);
    }

    //sort
    sort(boys_skills.begin(), boys_skills.end());
    sort(girls_skills.begin(), girls_skills.end());

    int boy_pointer = 0;
    int girl_pointer = 0;

    int count = 0;

    while(boy_pointer < number_boys && girl_pointer < number_girls){
        if (abs(boys_skills[boy_pointer] - girls_skills[girl_pointer]) <= 1){
            count++;
            boy_pointer++;
            girl_pointer++;
        }else if(boys_skills[boy_pointer] > girls_skills[girl_pointer]){
            girl_pointer++;
        }else{
            boy_pointer++;
        }
    }

    cout<<count<<endl;

}