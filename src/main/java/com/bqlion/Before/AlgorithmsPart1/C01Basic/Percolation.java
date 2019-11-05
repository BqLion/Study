/**
package com.bqlion.Before.AlgorithmsPart1.C01Basic;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
    private final WeightedQuickUnionUF relationship;
    private final WeightedQuickUnionUF backWashRelationship;
    private boolean[] condition;    //测试完改回private
    private int openNumbers = 0;
    private final int n;

    public Percolation(int n) {
        if (n < 1)
            throw new java.lang.IllegalArgumentException();

        this.n = n;
        condition = new boolean[n * n];

        relationship = new WeightedQuickUnionUF(n * n + 2);
        for (int i = 0; i < n; i++) relationship.union(i, n * n);
        for (int j = n * (n - 1); j < n * n; j++) relationship.union(j, n * n + 1);

        backWashRelationship = new WeightedQuickUnionUF(n * n + 1);
        for (int i = 0; i < n; i++) backWashRelationship.union(i, n * n);
    }

    public void open(int row, int col) {
        if (row < 1 || row > n || col < 1 || col > n)
            throw new IllegalArgumentException();

        int middle = twoDimenToOneDimen(row, col, "middle");
        int up = twoDimenToOneDimen(row, col, "up");
        int down = twoDimenToOneDimen(row, col, "down");
        int left = twoDimenToOneDimen(row, col, "left");
        int right = twoDimenToOneDimen(row, col, "right");

        if (condition[middle]) return;
        else if (!condition[middle])condition[middle] = true;

        if (validate(up))relationship.union(middle, up);
        if (validate(down))relationship.union(middle, down);
        if (validate(left) && notEndlNeibor(middle, "left"))relationship.union(middle, left);
        if (validate(right) && notEndlNeibor(middle, "right"))relationship.union(middle, right);

        if (validate(up))backWashRelationship.union(middle, up);
        if (validate(down))backWashRelationship.union(middle, down);
        if (validate(left) && notEndlNeibor(middle, "left"))backWashRelationship.union(middle, left);
        if (validate(right) && notEndlNeibor(middle, "right"))backWashRelationship.union(middle, right);

        openNumbers++;
    }

    private boolean notEndlNeibor(int middle, String dist) {
        if (dist.equals("left"))
            return (middle % n != 0);
        if (dist.equals("right"))
            return ((middle + 1) % n != 0);
        else return false;
    }

    private int twoDimenToOneDimen(int row, int col, String direciton) {     //测试完改回private
        if (row < 1 || row > n || col < 1 || col > n)
            throw new IllegalArgumentException();

        if (direciton.equals("middle"))
            return ((row - 1) * n + col - 1);
        else if (direciton.equals("up"))
            return ((row - 2) * n + col - 1);
        else if (direciton.equals("down"))
            return (row * n + col - 1);
        else if (direciton.equals("left"))
            return ((row - 1) * n + col - 2);
        else if (direciton.equals("right"))
            return ((row - 1) * n + col);
        else
            return 0;

    }
    private boolean validate(int i) {
        return (i >= 0 && i < n * n && condition[i]);
    }

    public boolean isOpen(int row, int col) {
        if (row < 1 || row > n || col < 1 || col > n)
            throw new IllegalArgumentException();
        return (condition[twoDimenToOneDimen(row, col, "middle")]);
    }

    public boolean isFull(int row, int col) {
        if (row < 1 || row > n || col < 1 || col > n)
            throw new IllegalArgumentException();

        return (isOpen(row, col) && isBackWash(row,col) && relationship.connected(n * n, twoDimenToOneDimen(row, col, "middle")));
    }

    private boolean isBackWash(int row,int col){
        return (backWashRelationship.connected((twoDimenToOneDimen(row,col,"middle")), n*n));
    }

    public int numberOfOpenSites() { return openNumbers;
    }

    public boolean percolates() {
        if (n == 1)
            return (isOpen(1, 1));
        else
            return (relationship.connected(n * n, n * n + 1));
    }
}
 */
