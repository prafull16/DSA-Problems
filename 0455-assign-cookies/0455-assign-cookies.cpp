
class Solution {
public:
    int findContentChildren(vector<int>& Student, vector<int>& Cookie) {
       sort(Student.begin() , Student.end());
       sort(Cookie.begin() , Cookie.end());
       int cnt = 0;
       
       int i = 0;
       int j = 0;

         while( i<Student.size() && j<Cookie.size() ){
              
            if(Cookie[j] >= Student[i]){
                cnt++;
                i++;
                j++;
              }
              else{
                 j++;
              }
         }

         return cnt;
    }
};