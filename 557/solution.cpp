class Solution {
public:
    string reverseWords(string s) {
        string result;
        char space = ' ';
        int start=0, end=0;
        /* Reverse Directly */
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == space)
            {
                end = i-1;
                swap(s, start, end);
                start = i+1;
            }
        }
        swap(s,start,s.length()-1);
        return s;
    }

    void swap(string &s, int start, int end)
    {
        char temp;
        int mid = (end-start+1)/2;
        for(int i=0;i<mid;i++)
        {
            temp = s[start + i];
            s[start+i] = s[end - i];
            s[end - i] = temp;
        }

    }
};