import java.util.*;
import java.io.*;

public class Main {

    public static double find(int[] a1, int[] a2) {
	int len = a1.length + a2.length;
        int[] merged = new int[len];
        int i = 0, j = 0, k = 0;
        while (i < a1.length && j < a2.length) {
            if (a1[i] <= a2[j]) {
                merged[k] = a1[i];
                i++;
                k++;
            } else {
                merged[k] = a2[j];
                j++;
                k++;
            }
        }
        while (i < a1.length) {
            merged[k] = a1[i];
            i++;
            k++;
        }
        while (j < a2.length) {
            merged[k] = a2[j];
            j++;
            k++;
        }
        int mid = len / 2;
        double median = 0.0;

        if (len % 2 == 1) {
            median = merged[mid];

        } else {
            median = (double) (merged[mid] + merged[mid - 1]) / 2.0;
        }

        return median;
    }

    public static double findMedian(int[] a, int[] b) {
        if (a.length > b.length) {
            int[] temp = a;
            a = b;
            b = temp;
        }
        int totalLen = a.length + b.length;
        int lo = 0;
        int hi = a.length;
        while (lo <= hi) {
            int aleft = (lo + hi) / 2;
            int bleft = (totalLen + 1) / 2 - aleft;

            int alm1 = (aleft == 0) ? Integer.MIN_VALUE : a[aleft - 1];
            int al = (aleft == a.length) ? Integer.MAX_VALUE : a[aleft];
            int blm1 = (bleft == 0) ? Integer.MIN_VALUE : b[bleft - 1];
            int bl = (bleft == b.length) ? Integer.MAX_VALUE : b[bleft];

            if (alm1 <= bl && blm1 <= al) {
                double median = 0.0;
                if (totalLen % 2 == 1) {
                    median = Math.max(alm1, blm1);
                } else {
                    int lmax = Math.max(alm1, blm1);
                    int rmin = Math.min(al, bl);
                    median = (lmax + rmin) / 2.0;

                }
                return median;
            } else if (blm1 > al) {
                lo = aleft + 1;
            } else if (alm1 > bl) {
                hi = aleft - 1;
            }

        }
        return 0;

    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        // input work
        int n1 = scn.nextInt();
        int[] a = new int[n1];

        for (int i = 0; i < n1; i++) {
            a[i] = scn.nextInt();
        }

        int n2 = scn.nextInt();
        int[] b = new int[n2];

        for (int i = 0; i < n2; i++) {
            b[i] = scn.nextInt();
        }

        // double median = find(a, b);
        double median = findMedian(a, b);
        System.out.println(median);
    }
}