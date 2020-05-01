package com.company;

import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;

public class BinarySearchTree {
    private Node root;

    public class Node{
        // the datastructure that we are going to use
        int key;
        int value;
        Node left; // left child
        Node right; // right child
        int count;

        public Node(int k, int v, int c) {
            key = k;
            value = v;
            left = null;
            right = null;
            count = c;
        }
    }

    public BinarySearchTree() {
        // what will it do, it will just initialise the root pointer to null
        root = null;
    }

    public int size(Node root) {
        if (root == null) return 0;
        return root.count;
    }

    public int rank(int k) {
        return rank(k, root);
    }

    private int rank(int k, Node root) {
        if(root == null) return 0;

        if (root.key > k) return rank(k, root.left);
        else if (root.key < k) return 1 + size(root.left) + rank(k, root.right);
        else return size(root.left);

    }


    public int get(int k) {
        // search for the key (k)
        Node currentNode = root;
        while (currentNode != null) {
            if(k > currentNode.key) currentNode = currentNode.right;
            else if (k < currentNode.key) currentNode = currentNode.left;
            else return currentNode.value;
        }
        return -1; // of not found
    }

    public void put(int k, int v) {
        // this will be available to the client
        root = put(root, k, v);
    }


    private Node put(Node x, int k, int v) {
        // insert the key k if not present having value v otherwise overwrite it
        if (x == null) return new Node(k, v, 1);

        if(x.key > k) x.left = put(x.left, k, v);
        else if(x.key < k) x.right = put(x.right, k, v);
        else x.value = v;

        x.count = size(x.left) + size(x.right) + 1;
        return x;
    }

    public Iterable<Integer> keys(){

        Queue<Integer> queue = new LinkedList<Integer>();

        inorder(root, queue);
        return queue;
    }

    private void inorder(Node root, Queue<Integer> queue) {
        if (root == null) return;
        inorder(root.left, queue);
        queue.add(root.key);
        inorder(root.right, queue);
    }


    public Node min(Node root) {
        if (root.left == null) return root;
        return min(root.left);
    }


    public void deleteMin() {
        // deletes the minimum key
        root = deleteMin(root);
    }

    private Node deleteMin(Node root) {
        if (root.left == null) return root.right;
        root.left = deleteMin(root.left);
        root.count = size(root.left) + size(root.right) + 1;
        return root;
    }

    public void delete(int key) {
        // given a key delete the node
        root = delete(root, key);
    }

    private Node delete(Node root, int key) {
        if (root == null) return null;
        // first we've to reach at that key
        if(root.key > key) root.left = delete(root.left, key); // search in the left
        else if (root.key < key) root.right = delete(root.right, key); // search in the right
        else {
            // we found the key
            // we have to check if it has one children
            if (root.right == null) return root.left;
            if (root.left == null) return root.right;

            // otherwise replace it with the successor, quite complicated but you'll get use to it
            Node tmp = root;
            root = min(tmp.right);
            root.right = deleteMin(tmp.right);
            root.left = tmp.left;

        }

        root.count = size(root.left) + size(root.right) + 1;
        return root;

    }


    public static void main(String[] args) {
        int[] a = {5, 1, 9, 0, 3, 10, 6, 2, 20};
        // we need to randomise the number so as to avoid building the skewed trees
        BinarySearchTree btree = new BinarySearchTree();
        for (int i = 0; i < a.length; i++) {
            btree.put(a[i], i);
        }

        //System.out.println(btree.get(20));
        btree.delete(2);
        for (Integer i : btree.keys()) {
            System.out.println(i);
        }


    }




}
