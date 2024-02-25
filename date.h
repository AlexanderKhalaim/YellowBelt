#pragma once

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Date {

public:
    Date(int year, int month, int day);
    
    int GetYear() const;
    
    int GetMonth() const;
    
    int GetDay() const;
  
private:
    int Year, Month, Day;
};

bool operator <(const Date& lhs, const Date& rhs);

bool operator <=(const Date& lhs, const Date& rhs);

bool operator >(const Date& lhs, const Date& rhs);

bool operator >=(const Date& lhs, const Date& rhs);

bool operator ==(const Date& lhs, const Date& rhs);

bool operator !=(const Date& lhs, const Date& rhs);

ostream& operator<<(ostream& os, const Date& date);

ostream& operator<<(ostream& os, const pair<Date, string>& entry);

Date ParseDate(istream& is);

