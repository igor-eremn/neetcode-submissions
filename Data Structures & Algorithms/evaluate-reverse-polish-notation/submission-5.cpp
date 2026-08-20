class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> s{};
        unordered_set<string> op{"+", "-", "*", "/"};
        
        for (int i=0; i<tokens.size(); i++){
            string to_check = tokens[i];
            if (op.contains(to_check)){
                int temp1 = s.back(); s.pop_back();
                int temp2 = s.back(); s.pop_back();

                if (to_check == "+"){ temp2 = temp2 + temp1;} 
                else if (to_check == "-"){ temp2 = temp2 - temp1; } 
                else if (to_check == "*"){ temp2 = temp2 * temp1; } 
                else { temp2 = temp2 / temp1; }

                s.push_back(temp2);
            } else {
                s.push_back(stoi(to_check));
            }
        }

        return s.back(); 
    }
};
