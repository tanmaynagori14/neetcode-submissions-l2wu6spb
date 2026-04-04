class CountSquares {
private:
    vector<pair<int,int>> points;
    map<pair<int,int>,int> freq;
public:
    CountSquares() {

    }
    
    void add(vector<int> point) {
        points.push_back({point[0], point[1]});
        freq[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int countsqs = 0;
        for(auto &p: points) {
            int x1 = p.first, y1 = p.second; // check if this are diagonal points
            if(x1==x || y1==y || abs(x1-x) != abs(y1-y) || x1-x==0 || y1-y==0) 
                continue;

            countsqs += freq[{x, y1}] * freq[{x1, y}];
        }

        return countsqs;
    }
};
