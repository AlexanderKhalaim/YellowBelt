#include "database.h"

using namespace std;
    
    void Database::Add(const Date& date, const string& event){
        if (!Iterarators[date].count(event)) {
            base[date].push_back(event);

            auto it = prev(base[date].end());
            Iterarators[date][event] = it;
        }
    }
    
    void Database::Print(ostream& os) const {
        for(const auto& item : base){
            const Date& date = item.first;
            list<string> events = item.second;
            for (const auto& event : events) {
                os << date << " " << event << endl;
            }
        }
    }
    
    int Database::RemoveIf(function<bool(const Date& date, const string& event)> predicate){

        vector<pair<Date, string>> finded = FindIf(predicate);

        for (const auto& element : finded) {
            const auto& date = element.first;
            const auto& event = element.second;

            auto curIt = Iterarators[date][event];
            base[date].erase(curIt);
            Iterarators[date].erase(event);
            if (base[date].empty()) {
                base.erase(date);
            }
        }
        
        return finded.size();
    }
    
    vector<pair<Date, string>> Database::FindIf(function<bool(const Date& date, const string& event)> predicate) const {

        vector<pair<Date, string>> res;
        
        for(const auto& item : base){
            const auto& date = item.first;
            list<string> events = item.second;
            for (const auto& event : events) {
                if (predicate(date, event)) {
                    res.push_back(make_pair(date, event));
                }
            }
        }
        
        return res;
    }
    
    pair<Date, string> Database::Last(const Date& date) const{
        auto it = base.upper_bound(date);
        if(it == base.begin()){
            throw invalid_argument("");
        }
        
        --it;
        const Date& res = it->first;
        const list<string>& events = it->second;
        
        const string& event = events.back();
        
        return make_pair(res, event);
    }