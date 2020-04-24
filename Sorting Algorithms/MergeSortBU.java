package com.company;

import java.util.Arrays;

public class MergeSortBU {

    private void merge(int[] a, int low, int mid, int high){
        int[] aux = new int[a.length];
        // copy the content
        for(int k = 0; k < a.length; ++k){
            aux[k] = a[k];
        }
        int i = low, j = mid + 1;
        for(int k = low; k <= high; ++k){
            if(i > mid)
                a[k] = aux[j++];
            else if(j > high)
                a[k] = aux[i++];
            else if(aux[i] > aux[j])
                a[k] = aux[j++];
            else
                a[k] = aux[i++];

        }
    }
    public void sort(int[] a){
        int N = a.length;
        for(int size = 1; size < N; size = size * 2){
            for(int lo = 0; lo < N - size; lo += size + size) {
                merge(a, lo, lo + size - 1, Math.min(lo + size + size - 1, N - 1));
            }
        }

    }

    public static void main(String[] args) {
        MergeSortBU mergeSortBU = new MergeSortBU();
        int[] a = {6, 45, 5, 3, 7, 8, 1, 2, 0, 82, 4, 23, -1, 97, 9, 2};
        mergeSortBU.sort(a);
        System.out.println(Arrays.toString(a));

    }
}
