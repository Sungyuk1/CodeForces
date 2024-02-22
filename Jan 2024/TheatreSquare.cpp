#include <iostream>
using namespace std;
/*Theatre Square in the capital city of Berland has a rectangular shape with the size n × m meters. On the occasion of the city's anniversary, a decision was taken to pave the Square with square granite flagstones. Each flagstone is of the size a × a.

What is the least number of flagstones needed to pave the Square? It's allowed to cover the surface larger than the Theatre Square, but the Square has to be covered. It's not allowed to break the flagstones. The sides of flagstones should be parallel to the sides of the Square.

Input
The input contains three positive integer numbers in the first line: n,  m and a (1 ≤  n, m, a ≤ 109).

Output
Write the needed number of flagstones.

*/
int main()
{
    long long n;
    long long m;
    long long a;

    cin >> n >>m >>a;

    //Just calculating the overflow. If both sides can be divided by a, there is no need for any overflow and the tiles fit evenly.
    //If only one side divides by a evenly, there will be overflow on that side.
    //If neither side divides a evenly, there will be overflow on both sides. 
    if(n%a == 0 && m%a ==0){
        long long number_n = n/a;
        long long number_m = m/a;
        cout<<number_n * number_m<<endl;
    }
    else if (n%a == 0){
        long long number_n = n/a;
        long long number_m = (m/a) +1;
        cout<<number_n * number_m<<endl;
    }
    else if (m%a ==0){
        long long number_n = (n/a)+1;
        long long number_m = m/a;
        cout<<number_n * number_m<<endl;
    }
    else{
        long long number_n = (n/a)+1;
        long long number_m = (m/a)+1;
        cout<<number_n * number_m<<endl;
    }





}