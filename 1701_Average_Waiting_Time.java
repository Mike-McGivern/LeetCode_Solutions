class Solution {
    public double averageWaitingTime(int[][] customers) {
        int i = 0;
        double t = 0, wt = 0;
        while (i < customers.length) {
            double ct = customers[i][1];
            if (customers[i][0] >= t) {
                t = customers[i][0] + ct;
                wt += ct;
            } else {
                wt += t - customers[i][0] + ct;
                t += ct;
            }
            i++;
        }
        return wt / customers.length;
    }
}
