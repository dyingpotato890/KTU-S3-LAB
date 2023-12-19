import java.util.*;

public class palindromeString {
    public static void main(String[] args) {
        Scanner obj = new Scanner(System.in);

        System.out.print("Enter The Word: ");
        String word = (obj.nextLine()).toLowerCase();
        String rev = "";
        
        for(int i = word.length()-1; i >= 0; i--)
            rev += word.charAt(i);

        if (word.equals(rev))
            System.out.println("The Given Word Is A Palindrome");
        else
            System.out.println("The Given Word Is Not A Palindrome");
    }
}