package com.company;

import java.util.Arrays;

public class QuickSelect {
    // this program helps us in finding the kth smallest element using the idea of quick sort and it has
    // almost average running time equal to linear
    private int partition(int[] a, int low, int high) {
        int i = low + 1, j = high;

        while(true) {

            while(a[i] < a[low]) {
                i++;
                if(i == high) {
                    break;
                }
            }
            while(a[j] > a[low]) {
                j--;
                if(j == low) {
                    break;
                }
            }
            if(i >= j) break;
            swap(a, i, j);
        }
        swap(a, low, j);
        return j;
    }

    public int select(int[] a, int k) {
        int low = 0, high = a.length - 1;
        while (high > low) {
            int p = partition(a, low, high);
            if(p > k) high = p - 1;
            else if (p < k) low = p + 1;
            else return a[k];
        }
        return a[k];
    }

    private void swap(int[] a, int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    public static void main(String[] args) {
        int[] a = {5, 6, 8, 0, 1, 3, 9, 10};
        QuickSelect quickSelect = new QuickSelect();
        int k = 3; // 3 smallest number
        System.out.println(quickSelect.select(a, k - 1));
    }

}
