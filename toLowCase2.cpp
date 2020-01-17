class Solution {
public:
    string toLowerCase(string str) {
        for (int i = 0; i <str.size(); i++){
            str[i] |= 32; // 将大写字母转换成小写
        }
        return str;

    }
};
