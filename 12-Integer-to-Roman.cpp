class Solution {
public:
    string intToRoman(int num) {
        int dg = 1;
        int num1 = num;
        while(num1 > 10){
            num1 = num1/10;
            dg++;
        }

        map<int, string> table;
        table[1] = "I";
        table[2] = "II";
        table[3] = "III";
        table[4] = "IV";
        table[5] = "V";
        table[6] = "VI";
        table[7] = "VII";
        table[8] = "VIII";
        table[9] = "IX";
        table[10] = "X";
        table[20] = "XX";
        table[30] = "XXX";
        table[40] = "XL";
        table[50] = "L";
        table[60] = "LX";
        table[70] = "LXX";
        table[80] = "LXXX";
        table[90] = "XC";
        table[100] = "C";
        table[200] = "CC";
        table[300] = "CCC";
        table[400] = "CD";
        table[500] = "D";
        table[600] = "DC";
        table[700] = "DCC";
        table[800] = "DCCC";
        table[900] = "CM";
        table[1000] = "M";
        table[2000] = "MM";
        table[3000] = "MMM";

        string ans = "";

        for(int i=1; i<=dg+1; i++){
            int currnum = num%int(pow(10, i));
            num -= num%int(pow(10, i));
            cout << currnum << endl;
            
            ans = table[currnum] + ans;

        }

        // cout << dg << endl;
        return ans;
    }
};