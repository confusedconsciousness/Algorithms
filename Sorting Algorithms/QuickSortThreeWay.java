package com.company;


import java.util.Arrays;

public class QuickSortThreeWay {
    // used when we have way more duplicates, here we are maintaining three things (subarray that is having value less than the
    // partition value, a subarray having values equal and a subarray having values greater
    // this is way more easier than the real implementation of the quick sort
    // use this in all situation
    private void swap(int[] a, int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    public void sort(int[] a, int low, int high) {
        if(low >= high) return;

        int lt = low, gt = high;
        int i = low;
        int v = a[low];
        while (i <= gt) {
            if(a[i] < v) {
                swap(a, i, lt);
                ++i;
                ++lt;
            }else if (a[i] > v) {
                swap(a, i, gt);
                --gt;
            }else{
                ++i;
            }
        }
        sort(a, low, lt - 1);
        sort(a, gt + 1, high);
    }


    public static void main(String[] args) {
        int a[] = {7, 3, 4, 9, 6, 8, 6, 1, 2, 6, 5, 6};

        QuickSortThreeWay quickSortThreeWay = new QuickSortThreeWay();

        quickSortThreeWay.sort(a, 0, a.length - 1);
        System.out.println(Arrays.toString(a));
    }
}
