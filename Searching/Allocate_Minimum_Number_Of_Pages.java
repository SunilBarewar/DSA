import java.util.*;
import java.io.*;

public class Main {

  public static int minPages(int[]arr, int m) {
    int max = 0; 
    int sum = 0; 
    for(int i = 0; i< arr.length;i++){
        sum = sum+arr[i];
        max = Math.max(max,arr[i]);
    }
    if(arr.length == m) return max;
    int lo = max;
    int hi = sum;
    
    
    int ans = 0; 
    
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(isPossible(arr,mid,m)){
            hi = mid-1;
            ans = mid;
        }
        else{
            lo = mid+1;
        }
    }
    
    return ans;
  }


    public static boolean isPossible(int[] arr, int mid ,int m){
        
        int s =1;
        int sum = 0;
        
        for(int i = 0; i< arr.length;i++){
            sum += arr[i];
            if(sum > mid){
                s++;
                sum = arr[i];
            }
        }
        return s <= m;
    }
  public static void main(String[]args) {
    //input work
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();

    int[]arr = new int[n];

    for (int i = 0; i < n; i++) {
      arr[i] = scn.nextInt();
    }

    int m = scn.nextInt();

    int ans = minPages(arr, m);
    System.out.println(ans);
  }
}