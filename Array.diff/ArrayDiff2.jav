import java.util.stream.IntStream;

public class Kata {

  public static int[] arrayDiff(int[] a, int[] b) {
    return IntStream.of(a).filter(x -> IntStream.of(b).noneMatch(y -> y == x)).toArray();
  }

}
