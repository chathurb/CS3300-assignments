import syntaxtree.*;
import visitor.*;
import java.util.*;

public class P1 {
   public static void main(String [] args) {
      try {
         Node root = new MiniJavaParser(System.in).Goal();
         GJDepthFirst df = new GJDepthFirst();
         Object value = root.accept(df, null); // Your assignment part is invoked here.
         System.out.println("Program type checked successfully");
      }
      catch (ParseException e) {
         System.out.println(e.toString());
      }
   }
}
