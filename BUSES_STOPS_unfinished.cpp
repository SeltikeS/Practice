#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int q;
    cin >> q;
    
    map<string, vector<string>> buses;
    map<string, vector<string>> stops;
    
    for(int i = 0; i < q; ++i){
        string command;
        cin >> command;
        
        if(command == "NEW_BUS"){
            string bus;
            int stop_count;
            cin >> bus >> stop_count;
            
            for(int j = 0; j < stop_count; ++j){
                string stop;
                cin >> stop;
                buses[bus].push_back(stop);
                stops[stop].push_back(bus);
            }
        } else if(command == "BUSES_FOR_STOP"){
            string stop;
            cin >> stop;
            if(stops.count(stop) == 0){
                cout << "No stop" << endl;
            } else {
                for(const auto& bus_item : stops[stop]){
                    cout << bus_item << ' ';
                }
                cout << endl;
            }
        } else if(command == "STOPS_FOR_BUS"){
            
        }
        
        
    }

    return 0;
}
