class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        string res;
        for(int i=0;i<path.length();i++){
            string temp;
            if(path[i]=='/'){
                continue;
            }
            while(i<path.length() && path[i]!= '/'){
                temp+=path[i];
                i++;
            }
            if(temp=="."){
                continue;
            }
            else if(temp==".."){
                if(!stk.empty()){
                    stk.pop();
                }
            }
            else{
                stk.push(temp);
            }



        }

        while(!stk.empty()){
           res= "/"+stk.top()+res; 
           stk.pop();
        }

        if(res.size() == 0)
            return "/";

        return res;
    }
};