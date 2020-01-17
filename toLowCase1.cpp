class Solution {
public:
    string toLowerCase(string str) {

        for(auto& e: str)
        {
            if(isupper(e))
                e += 32;
        }

        return str;
    }
};