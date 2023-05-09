#define pb push_back
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> list;
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0 ;
        int bottom = m -1;
        int left = 0;
        int right = n - 1;
        int dir = 0;
        while(top <= bottom && left <= right){
            if(dir == 0){
                for(int i = left ; i <= right ;i++ ){
                    list.pb(matrix[top][i]);
                    //System.out.println(matrix[top][i]);
                }
                top++;
                if(top > bottom) break;
                dir = 1; 
            }
            if(dir == 1){
                for(int i = top ; i <= bottom ;i++){
                    list.pb(matrix[i][right]);
                    //System.out.println(matrix[i][right]);
                }
                right--;
                if(right < left) break;
                dir = 2;
            }
            if(dir == 2){
                for(int i = right ; i >= left ; i--){
                    list.pb(matrix[bottom][i]);
                    //System.out.println(matrix[bottom][i]);
                }
                bottom--;
                if(bottom < top) break;
                dir = 3;
            }
            if(dir == 3){
                for(int i = bottom ; i >= top ;i--){
                    list.pb(matrix[i][left]);
                    //System.out.println(matrix[i][left]);
                }
                left++;
                if(left > right) break;
                dir = 0;
            }
        }
        return list;

    }
};