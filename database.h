#pragma once

#include <string>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <ostream>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <functional>
#include <typeinfo>
#include <list>

#include "date.h"
#include "node.h"
#include "condition_parser.h"

using namespace std;

class Database {

public:
    
    void Add(const Date& date, const string& event);
    
    void Print(ostream& os) const;
    
    int RemoveIf(function<bool(const Date& date, const string& event)> predicate);
    
    vector<pair<Date, string>> FindIf(function<bool(const Date& date, const string& event)> predicate) const;
    
    pair<Date, string> Last(const Date& date) const;
    
private:
    map<Date, list<string>> base;
    map<Date, map<string, list<string>::iterator>> Iterarators;
};