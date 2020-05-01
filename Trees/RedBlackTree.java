package com.company;

public class RedBlackTree {
    private Node root;

    private static final boolean RED = true;
    private static final boolean BLACK = false;

    private class Node{
        int key;
        int value;
        Node left, right;
        boolean color;

        private Node(int k, int v){
            key = k;
            value = v;
            left = null;
            right = null;
            color = RED; // means the color is Red
        }
    }

    private boolean isRed(Node root) {
        if (root == null) return false;
        return root.color == RED;
    }

    private Node rotateLeft(Node h) {
        // if the link is dangling right
        Node x = h.right; // which is going to be the root
        h.right = x.left;
        x.left = h;
        x.color = h.color;
        h.color = RED;
        return x;
    }

    private Node rotateRight(Node h) {
        Node x = h.left;
        h.left = x.right;
        x.right = h;
        x.color = h.color;
        h.color = RED;
        return x;
    }

    private void flipColors(Node h) {
        h.color = RED;
        h.left.color = BLACK;
        h.right.color = BLACK;
    }

    public void put(int k, int v) {
        root = put(root, k, v);
    }

    private Node put(Node root, int k, int v) {
        if (root == null) return new Node(k, v);
        if (root.key > k) root.left = put(root.left, k, v);
        else if (root.key < k) root.right = put(root.right, k, v);
        else root.value = v;

        // apply the flipping
        if(isRed(root.right) && !isRed(root.left)) root = rotateLeft(root); // right link is RED
        if (isRed(root.left) && isRed(root.left.left)) root = rotateRight(root); // we have two consecutive left REDs
        if (isRed(root.left) && isRed(root.right)) flipColors(root); // left and right red
        return root;
    }

    public static void main(String[] args) {
        int[] a = {5, 1, 9, 0, 3, 10, 6, 2, 20};
        RedBlackTree rbTree = new RedBlackTree();

        for (int i = 0; i < a.length; i++) {
            rbTree.put(a[i], i);
        }

    }





}
