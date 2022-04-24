class UndergroundSystem {
public:
    map<int,pair<int,string>> m; 
    map<pair<string,string>,int> m2;
    map<pair<string,string>,int> m3;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        m[id] = {t,stationName}; 
    }
    
    void checkOut(int id, string stationName, int t) {
        m2[{stationName,m[id].second}]+=t-m[id].first;
        m3[{stationName,m[id].second}]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double)((double)m2[{endStation,startStation}]/(double)m3[{endStation,startStation}]);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */