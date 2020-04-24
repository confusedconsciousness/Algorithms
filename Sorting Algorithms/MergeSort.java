package com.company;

import java.util.Arrays;

public class MergeSort {

    private void merge(int[] a, int low, int mid, int high){
        int[] aux = new int[a.length];
        // make a copy
        for(int k = 0; k < a.length; ++k){
            aux[k] = a[k];
        }

        int i = low, j = mid + 1;
        for(int k = low; k <= high; ++k) {
            // also take care of one thing if one index gets exhausted
            if (i > mid)
                a[k] = aux[j++];
            else if (j > high)
                a[k] = aux[i++];
            else if (aux[i] > aux[j])
                a[k] = aux[j++];
            else
                a[k] = aux[i++];
        }
    }

    public void sort(int[] a, int low, int high){
        if(low >= high)
            return;

        int mid = low + (high - low) / 2;
        sort(a, low, mid);
        sort(a, mid + 1, high);

        merge(a, low, mid, high);

    }

    public static void main(String[] args) {
        MergeSort mergeSort = new MergeSort();
        int[] a = {6, 45, 5, 3, 7, 8, 1, 2, 0, 82, 4, 23, -1, 97, 9, 2};
        mergeSort.sort(a, 0, a.length - 1);
        System.out.println(Arrays.toString(a));
    }


}
