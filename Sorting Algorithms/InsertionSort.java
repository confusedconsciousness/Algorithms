package com.company;

import java.util.Arrays;

public class InsertionSort {

    public void sort(int[] a){
        int N = a.length;
        for(int i = 1; i < N; ++i){
            int curValue = a[i];
            int curIndex = i;

            while(curIndex > 0 && a[curIndex - 1] > curValue){
                a[curIndex] = a[curIndex - 1];
                curIndex--;
            }
            a[curIndex] = curValue;
        }
    }

    public static void main(String[] args) {
        InsertionSort insertionSort = new InsertionSort();
        int[] a = {5, 2, 1, 0, 6, 9};
        insertionSort.sort(a);
        System.out.println(Arrays.toString(a));
    }
}
