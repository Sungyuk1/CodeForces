#include <iostream>
using namespace std;
/*
One hot summer day Pete and his friend Billy decided to buy a watermelon. They chose the biggest and the ripest one, in their opinion. After that the watermelon was weighed, and the scales showed w kilos. They rushed home, dying of thirst, and decided to divide the berry, however they faced a hard problem.

Pete and Billy are great fans of even numbers, that's why they want to divide the watermelon in such a way that each of the two parts weighs even number of kilos, at the same time it is not obligatory that the parts are equal. The boys are extremely tired and want to start their meal as soon as possible, that's why you should help them and find out, if they can divide the watermelon in the way they want. For sure, each of them should get a part of positive weight.

Input
The first (and the only) input line contains integer number w (1 ≤ w ≤ 100) — the weight of the watermelon bought by the boys.

Output
Print YES, if the boys can divide the watermelon into two parts, each of them weighing even number of kilos; and NO in the opposite case.
*/
int main()
{
    int watermelon_weight;
    cin>>watermelon_weight;

    //Note that when 2 is split in two, it results in 1 and 1 which are not even
    //No odd number can be split into two even numbers
    //Any even number greater than 2 can be split into two even numbers, the prime factorization of the number is always 2* (number bigger than 1)
    
    if(watermelon_weight == 0){
        cout<<"NO"<<endl;
    }
    else if(watermelon_weight%2 == 1){
        cout<<"NO"<<endl;
    }
    else if(watermelon_weight ==2){
        cout<<"NO"<<endl;
    }else{
       cout<<"YES"<<endl;
    }

}