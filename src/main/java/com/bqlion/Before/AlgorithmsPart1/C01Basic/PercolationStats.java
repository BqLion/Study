package com.bqlion.Before.AlgorithmsPart1.C01Basic;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

public class PercolationStats {
    private final double[] result;
    private final double m;
    private final double confidence;
    public PercolationStats(int n, int trials) {
        m = n;
        confidence = 1.96;
        result = new double[trials];
        int j = 0;
        for (int i = 0; i < trials; i++) {
            Percolation p = new Percolation(n);
            while (!p.percolates()) {
                p.open(StdRandom.uniform(n) + 1, StdRandom.uniform(n) + 1);
                j++;
            }
            result[i] = j / (m * m);
        }
    }    // perform trials independent experiments on an n-by-n grid

    public double mean() { return StdStats.mean(result); }                          // sample mean of percolation threshold
    public double stddev() { return StdStats.stddev(result); }                        // sample standard deviation of percolation threshold
    public double confidenceLo() { return mean() - confidence * stddev() / Math.sqrt(m); }                  // low  endpoint of 95% confidence interval
    public double confidenceHi() { return mean() + confidence * stddev() / Math.sqrt(m); }                  // high endpoint of 95% confidence interval

    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        int t = Integer.parseInt(args[1]);
        PercolationStats p = new PercolationStats(n, t);
        StdOut.println("mean" + p.mean());
        StdOut.println("stddev" + p.stddev());
        StdOut.println("95% confidence interval" + "[" + p.confidenceLo() + "," + p.confidenceHi() + "]");
    }
}
