#include <iostream>
using namespace std;

int main()
{
    int number_of_rides;
    int m_ticket_number_of_rides;
    int price_single_ticket;
    int price_m_ticket;

    cin >>number_of_rides >>m_ticket_number_of_rides >>price_single_ticket>>price_m_ticket;

    if(price_single_ticket* m_ticket_number_of_rides <= price_m_ticket){
        cout<<number_of_rides*price_single_ticket<<endl;
    }else{
        int clean_ms = number_of_rides/m_ticket_number_of_rides;
        int remaining_rides = number_of_rides% m_ticket_number_of_rides;
        if(price_single_ticket * remaining_rides >= price_m_ticket){
            int output = (price_m_ticket * (clean_ms+1));
            cout<<output<<endl;
        }
        else{
            int output = (price_m_ticket * (clean_ms)) + (price_single_ticket*remaining_rides);
            cout<<output<<endl;
        }
        
    }

    return 0;

}