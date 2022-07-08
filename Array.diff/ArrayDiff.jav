import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
public class Kata {

  public static int[] arrayDiff(int[] a, int[] b) {
	
	List<Integer> list = Arrays.stream(a).boxed().collect(Collectors.toList());
	List<Integer> list2 = Arrays.stream(b).boxed().collect(Collectors.toList());
	list.removeAll(list2);
	System.out.println(list);
	
	int[] ret = list.stream().mapToInt(Integer::intValue).toArray();
    return ret;

  }

}
