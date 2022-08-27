#include<bits/stdc++.h>
using namespace std;
// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.


// "God Ding"-----> "doG gniD"





int e_word(string str, int s)
{
    int count = s;

    while (s < str.length())
    {

        if (str[s] == 32)
        {
            return count;
        }

        s++;
        count++;
    }

    return count;
}
string reverseWords(string s)
{

    int i = 0;
    int count = e_word(s, i);
    int j = count - 1;
    while (count <= s.length())
    {

        while (i <= j )
        {
            swap(s[i], s[j]);
            j--;
            i++;
        }

        i = count + 1;
        count = e_word(s, i);
        j = count-1;
    }
    return s;
}

// string reverseWords(string s){

//   int counter_start{0}, counter_end{0};
//         for (int i=0; i<s.length(); i++){
//             if (s[i] == ' '){
//                 reverse(s.begin()+counter_start, s.begin()+counter_end);
//                 counter_start=counter_end+1;
//                 counter_end=i+1;
//                 continue;
//             }
//             else{
//                 counter_end++;
//             }
//             if (i==s.length()-1){ 
//                 reverse(s.begin()+counter_start, s.end());
//             }
//         }
//         return s;
// }
int main()
{   
    cout<<reverseWords("Let's take LeetCode contest")<<endl;
  
    return 0;
}