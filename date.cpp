#include "date.h"
#include <sstream>

using namespace std;

Date::Date(int year, int month, int day) : Year(year), Month(month), Day(day) {}
    
    int Date::GetYear() const {
        return Year;
    }
    
    int Date::GetMonth() const {
        return Month;
    }
    
    int Date::GetDay() const {
        return Day;
    }
    
bool operator <(const Date& lhs, const Date& rhs) {
    if(lhs.GetYear() == rhs.GetYear()){
        if(lhs.GetMonth() == rhs.GetMonth()){
            return lhs.GetDay() < rhs.GetDay();
        }
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetYear() < rhs.GetYear();
}

bool operator <=(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() <= rhs.GetDay();
        }
        return lhs.GetMonth() <= rhs.GetMonth();
    }
    return lhs.GetYear() <= rhs.GetYear();
}

bool operator >(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() > rhs.GetDay();
        }
        return lhs.GetMonth() > rhs.GetMonth();
    }
    return lhs.GetYear() > rhs.GetYear();
}

bool operator >=(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() >= rhs.GetDay();
        }
        return lhs.GetMonth() >= rhs.GetMonth();
    }
    return lhs.GetYear() >= rhs.GetYear();
}

bool operator==(const Date& lhs, const Date& rhs) {
    return(lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay());
}

bool operator!=(const Date& lhs, const Date& rhs) {
    return (!(lhs == rhs));
}

ostream& operator<<(ostream& os, const Date& date){

    os << setw(4) << setfill('0') << date.GetYear();
    os << "-";
    os << setw(2) << setfill('0') << date.GetMonth();
    os << "-";
    os << setw(2) << setfill('0') << date.GetDay();
    
    return os;
}

ostream& operator<<(ostream& os, const pair<Date, string>& entry) {
    os << entry.first << " " << entry.second;
    return os;
}

Date ParseDate(istream& is){
    
    int year, month, day;
    
    is >> year;
    is.ignore();
    is >> month;
    is.ignore();
    is >> day;
    
    return Date(year, month, day);
}