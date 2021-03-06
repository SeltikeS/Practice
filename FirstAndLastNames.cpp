#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        // Add fact of change First Name in Year
        if(m_first_names.count(year) > 0) {
            m_first_names[year] = first_name;
        }
    }
    
    void ChangeLastName(int year, const string& last_name) {
        // Add fact of change Last Name in Year
        if(m_last_names.count(year) > 0) {
            m_last_names[year] = last_name;
        }
    }
    
    string GetFullName(int year) {
        // Take First and Last Names in Year
        string this_year_first_name = 0;
        string this_year_last_name = 0;
        
        for(const auto& item : m_first_names) {
            if(item.first > year) break;
            this_year_first_name = item.second; 
        }
        
        for(const auto& item : m_last_names) {
            if(item.first > year) break;
            this_year_last_name = item.second; 
        }
        
        if(this_year_first_name.length() > 0) {
            
            if(this_year_last_name.length() > 0) {
                return  this_year_first_name + ' ' + this_year_last_name;
            } else {
                return this_year_first_name + " with unknown last name";
            }
        } else {
            if(this_year_last_name.length() > 0) {
                return  this_year_last_name + " with unknown first name";
            } else {
                return "incognito";
            }
        }
    }
    
    Person(){
        m_first_names.clear();
        m_last_names.clear();
    }
private:
    map<int, string> m_first_names;
    map<int, string> m_last_names;
};




int main()
{
    Person person;
    
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeevna");
    for(int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeFirstName(1970, "Appolinaria");
    for(int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeLastName(1968, "Volkova");
    for(int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    
    return 0;
}
