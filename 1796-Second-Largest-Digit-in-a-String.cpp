class Solution {
public:
    int secondHighest(string s) {
        int first_l = int('0')-1;
        int second_l = int('0')-1;

        for (char i:s)
        {
            if(i >= '0' &&  i <= '9'){
                if (i>first_l)
                {
                    second_l = first_l;
                    first_l = i;
                }

                if (i>second_l && i<first_l)
                {
                    second_l = i;
                }
            }
        }

        return int(second_l) == int('0')-1 ? -1 : int(second_l) - int('0');
    }
};