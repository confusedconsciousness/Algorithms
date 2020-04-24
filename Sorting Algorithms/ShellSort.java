package com.company;

import java.util.Arrays;

public class ShellSort {
    // shell sort makes use of insertion sort
    public void sort(int[] a){
        int N = a.length;
        int h = 1;
        while(h < N / 3) // generate increasing sequence
            h = 3 * h + 1;

        while(h > 0){

            for(int i = h; i < N; ++i){

                int curValue = a[i];
                int curIndex = i;

                while(curIndex  - h  > -1 && a[curIndex - h] > curValue){
                    a[curIndex] = a[curIndex - h];
                    curIndex -= h;
                }

                a[curIndex] = curValue;

            }
            h /= 3;

        }

    }
    public static void main(String[] args) {

        ShellSort shellSort = new ShellSort();
        int a[] = {7, 5, 2, 1, 0, 6, 9, 3, 8, 4, 97, -1, 23, 45, 82, -2};
        shellSort.sort(a);
        System.out.println(Arrays.toString(a));

    }
}
