class Solution {
public:

    void track(string s, vector<string>& ans, vector<int> & pos, int pointer){
        if(pointer > s.size() || pos.size() > 3){
            return;
        }

        if(pos.size() == 3){
            // for(auto x:pos){
            //     cout << x << " ";
            // }
            // cout << endl;

            string c1 = s.substr(0, pos[0]);
            string c2 = s.substr(pos[0], pos[1]-pos[0]);
            string c3 = s.substr(pos[1], pos[2]-pos[1]);
            string c4 = s.substr(pos[2], s.size()-pos[2]);

            if((c1.size() > 1 && c1[0] == '0') || (c2.size() > 1 && c2[0] == '0') || (c3.size() > 1 && c3[0] == '0') || (c4.size() > 1 && c4[0] == '0')){
                return;
            }else if(c1.size() > 3 || c2.size() > 3 || c3.size() > 3 || c4.size() > 3){
                return;
            }else  if(stoi(c1)>255 || stoi(c2) > 255 || stoi(c3) > 255 || stoi(c4) > 255){
                return;
            }


            // cout << c1 << "." << c2 << "." << c3 << "." << c4 << endl;
            ans.push_back(c1+"."+c2+"."+c3+"."+c4);

            return;
        }

        pos.push_back(pointer);
        track(s, ans, pos, pointer+1);
        pos.pop_back();
        track(s, ans, pos, pointer+1);
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<int> pos;
        track(s, ans, pos, 1);
        
        return ans;
    }
};