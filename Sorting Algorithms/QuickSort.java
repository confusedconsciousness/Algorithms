package com.company;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;

public class QuickSort {


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

    public void sort(int[] a, int low, int high) {
        if(low >= high) return;
        // first find the partition
        int p = partition(a, low, high);
        sort(a, low, p - 1);
        sort(a, p + 1, high);
    }

    private void swap(int[] a, int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    public static void main(String[] args) {
        QuickSort quickSort = new QuickSort();
        int[] a = {5, 6, 8, 0, 1, 3, 9, 10};

        quickSort.sort(a, 0, a.length - 1);

        System.out.println(Arrays.toString(a));

    }
}
