import java.util.*;
import java.io.*;

public class Main {

  public static int find(int[]arr, int n, int m) {
    //write your code here
    int ans = Integer.MAX_VALUE;
    Arrays.sort(arr);
    if(m == n)return arr[n-1] - arr[0];
    int i = 0 ,j = m - 1;
    while(j < n){
        int min = arr[i];
        int max = arr[j];
        int diff = max - min;
        ans = Math.min(ans,diff);
        i++;j++;
    }
    return ans;
  }

  public static void main(String[]args) {
    Scanner scn = new Scanner(System.in);
    //input work
    int n = scn.nextInt();
    int[]arr = new int[n];

    for (int i = 0; i < n; i++) {
      arr[i] = scn.nextInt();
    }

    int m = scn.nextInt();
    int ans = find(arr, n, m);

    System.out.println(ans);
  }
}