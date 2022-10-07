import java.util.function.Function;
import java.util.stream.Collectors;
import static java.lang.System.out;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;
import java.io.*;
import java.util.*;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int[] dx = {0, 1, 0, -1},dy = {1, 0, -1, 0},dx8 = {0, 1, 1, 1, 0, -1, -1, -1},dy8 = {1, 1, 0, -1, -1, -1, 0, 1};
    int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}},dir8 = {{0, 1}, {1, 0}, {0, -1}, {-1, 0},{1,1},{1,-1},{-1,1},{-1,-1}};
    int INF = 0x3f3f3f3f,MOD = 1000000007, mod = 998244353,maxn = (int)1e5+5,N = 100001;
    <T> List<T> distince(List<T> list, Function<? super T, ?> f) {Set<Object> set = new HashSet<>();return list.stream().filter(t -> set.add(f.apply(t))).collect(Collectors.toList());}
    Comparator<int[]> cmp = (a,b)->{if(a[1] == b[1]) return a[0]-b[0];return a[1]-b[1];};
    boolean check(int x,int[] arr){return x>=0 && x<arr.length;}
    boolean check(int x,int y,int[][] arr){return x>=0 && x<arr.length && y>=0 && y<arr[0].length;}
    <T> int binarySearch(List<T> list, T target, Comparator<? super T> c) {int l = 0, r = list.size() - 1;while (l <= r) {int mid = l + (r - l) / 2;if (c.compare(list.get(mid), target) == 0) {return mid;} else if (c.compare(list.get(mid), target) < 0) {l = mid + 1;} else {r = mid - 1;}}return -1;}
    <T> void prints(Collection<T> list){list.forEach(t->out.print(t.toString()+" "));out.println();}
    <T> boolean nextPermutation(List<T> list, Comparator<? super T> c) {int n = list.size();int i = n - 2;while (i >= 0 && c.compare(list.get(i), list.get(i + 1)) >= 0) {i--;}if (i < 0) {return false;}int j = n - 1;while (j >= 0 && c.compare(list.get(i), list.get(j)) >= 0) {j--;}Collections.swap(list, i, j);Collections.reverse(list.subList(i + 1, n));return true;}
    <T> List<T> deepCopy(List<T> src) {ByteArrayOutputStream byteOut = new ByteArrayOutputStream();try {ObjectOutputStream out = new ObjectOutputStream(byteOut);out.writeObject(src);} catch (IOException e) {e.printStackTrace();}ByteArrayInputStream byteIn = new ByteArrayInputStream(byteOut.toByteArray());try {ObjectInputStream in = new ObjectInputStream(byteIn);return (List<T>) in.readObject();} catch (IOException | ClassNotFoundException e) {e.printStackTrace();}return null;}
    Optional<Integer> poss;

}
//leetcode submit region end(Prohibit modification and deletion)
