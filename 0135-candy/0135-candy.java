class Solution {
    public int candy(int[] ratings) {
        int len = ratings.length;
        int arr[] = new int[len];
        for(int i = 0 ; i < len ; i++) arr[i] = 1;
        
        for(int i = 1 ; i < len ; i++){
            if(ratings[i] > ratings[i-1])
            {
                arr[i] = arr[i-1] + 1;
            }
        }
        // right
        for(int i = len - 2 ; i >= 0 ;i--){
            if(ratings[i] > ratings[i+1]){
                if(arr[i] <=  arr[i+1]){
                    arr[i] = arr[i+1] + 1;
                }
            }
        }
        int sum = 0;
        for(int i =  0; i <  len ; i++){
            sum += arr[i];
        }
        return sum;
    }
}