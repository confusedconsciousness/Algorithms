package com.company;

import java.util.Arrays;
import java.util.Random;

public class Shuffling {

    public void shuffle(int[] a){
        int N = a.length;
        Random random = new Random();

        for(int i = 1; i < N; ++i){
            int randomIndex = random.nextInt(i + 1);
            swap(a, randomIndex, i);
        }
    }

    private void swap(int[] a, int i, int j){
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    public static void main(String[] args) {
        // the hypothesis is that the shuffling done is uniform and cover all the n! cases
        Shuffling shuffling = new Shuffling();
        int[] a = {2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 23, 45, 82, 97};
        shuffling.shuffle(a);
        System.out.println(Arrays.toString(a));

    }
}
