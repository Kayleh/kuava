package template.数论.马尔科夫链;

import java.util.Random;

public class MarkovChain {
    int NUM_STATES = 3; // 状态数，用于初始化转移矩阵，
    double[][] TRANSITION_MATRIX = new double[][]{ // 转移矩阵，用于初始化状态转移概率
            {0.1, 0.7, 0.2},
            {0.2, 0.1, 0.7},
            {0.7, 0.2, 0.1}
    };
    int NUM_ITERATIONS = 100000; // 迭代次数

    MarkovChain(int numStates, double[][] transitionMatrix, int numIterations) {
        NUM_STATES = numStates;
        TRANSITION_MATRIX = transitionMatrix;
        NUM_ITERATIONS = numIterations;
    }

    public int[] getStatus() {
        int[] status = new int[NUM_STATES];
        int currentState = 0;
        Random random = new Random();
        for (int i = 0; i < NUM_ITERATIONS; i++) {
            double randomValue = random.nextDouble(); // 生成一个[0, 1)之间的随机数
            double[] transitionRow = TRANSITION_MATRIX[currentState]; // 获取当前状态的转移概率
            double cumulativeProbability = 0.0; // 累计概率
            for (int j = 0; j < NUM_STATES; j++) {  // 遍历转移概率，找到对应的状态
                cumulativeProbability += transitionRow[j];
                if (randomValue <= cumulativeProbability) {
                    currentState = j; // 更新当前状态
                    break;
                }
            }
            //System.out.println("Current state: " + currentState);   // 输出当前状态
            status[currentState]++;
        }
        return status;
    }

    public static void main(String[] args) {
        //例子： 病毒传播,如果一个人感染了病毒，
        // 0：健康，1：潜伏期，2：患病
        // 0->1: 0.1, 1->2: 0.7, 2->0: 0.2
        MarkovChain markovChain = new MarkovChain(3, new double[][]{
                {0.1, 0.7, 0.2},
                {0.2, 0.1, 0.7},
                {0.7, 0.2, 0.1}
        }, 1000);
        int[] status = markovChain.getStatus();
        String[] statusName = new String[]{"健康", "潜伏期", "患病"};
        for (int i = 0; i < status.length; i++) {
            System.out.println(statusName[i] + "：" + status[i]);
        }
    }

}
