import java.util.Scanner;

public class PalinStar {
    static String[] sub = new String[50];

    public static int isPalindrome(String wrd){
        String rev = "";
        for(int j = (wrd.length()-1); j >= 0 ; j--)
            rev += wrd.charAt(j);
        if (wrd.equals(rev))
            return 1;
        return 0;
    }
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter The String: ");
        String str = s.nextLine();

        sub = str.split(" ");

        for(int i = 0; i < sub.length; i++){
            int result = isPalindrome(sub[i]);
            if (result == 1){
                sub[i] = "*".repeat(sub[i].length());
            }
        }

        System.out.println("Final Output: ");
        for(int i = 0; i < sub.length; i++){
            System.out.print(sub[i] + " ");
        }
    }
}
