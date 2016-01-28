class MinStack {
public:
    vector<long long int> a;
    map<int,int> b;
    void push(int x) {
        a.push_back(x);
        // b.insert(x);
        auto it = b.find(x);
        if(it == b.end()){
            b[x] = 1;
        }
        else{
            b[x] ++;
        }
    }

    void pop() {
        // auto it = b.begin();
        // for(it; it != b.end(); it++){
        //     if(*it == a.back()){
        //         b.erase(it);
        //         break;
        //     }
        // }
        auto it = b.find(a.back());
        b[it->first] --;
        if(b[it->first] == 0){
            b.erase(it);
        }
        a.pop_back();
    }

    int top() {
        return a.back();
    }

    int getMin() {
        auto it = b.begin();
        return it->first;
    }
};
