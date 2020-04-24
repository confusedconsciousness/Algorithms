package com.company;

import java.util.Arrays;

public class SelectionSort{
    public void sort(int[] a){
        int N = a.length;
        for(int i = 0; i < N; ++i){
            int min = i;
            for(int j = i + 1; j < N; ++j){
                if(a[min] > a[j])
                    min = j;
            }
            exchange(a, min, i);
        }
    }
    private void exchange(int[] a, int min, int i) {
        int swap = a[min];
        a[min] = a[i];
        a[i] = swap;
    }

    public static void main(String[] args) {
        SelectionSort selectionSort = new SelectionSort();
        int[] a = {1, 7, 0, 4, 2, 8, 3};
        selectionSort.sort(a);
        System.out.println(Arrays.toString(a));

    }

}
