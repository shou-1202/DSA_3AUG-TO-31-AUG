class Solution {
public:
    bool evaluatePrefix(string expression){
        stack<int>s;
        int n = expression.length();

        for(int i = n-1; i>=0;i--){
            char token = expression[i];
            if(token == ')' || token =='t' || token == 'f'){
                s.push(token);
            }
            else if(token == '(' || token == ','){
                continue;
            }
            else {
            // token is an operator: '&', '|', or '!'
            bool ans = (token == '&'); // default true for AND, false for OR
            if (token == '!') ans = false; // logic placeholder for NOT
            
            // Process operands inside the current parenthesis block
            while (!s.empty() && s.top() != ')') {
                char currentOperand = s.top();
                s.pop(); // Pop immediately to avoid infinite loops

                bool a = (currentOperand == 't');
                
                if (token == '&') {
                    ans = ans && a;
                } else if (token == '|') {
                    ans = ans || a;
                } else if (token == '!') {
                    ans = !a; 
                }
            }
            
            // Pop the matching closing parenthesis ')'
            if (!s.empty() && s.top() == ')') {
                s.pop();
            }
            
            // Push the calculated result back onto the stack as a char
            s.push(ans ? 't' : 'f');
        }
        }
        return !s.empty() && s.top() == 't';
    }
    bool parseBoolExpr(string expression) {
        return evaluatePrefix(expression);
    }
};