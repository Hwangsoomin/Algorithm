import java.util.*;
import java.io.*;

public class Main {
    public static String changeRight(String str) {
        String str1 = str.substring(0, 1);
        String str2 = str.substring(1);
        str1 = str1.toUpperCase();
        str2 = str2.toLowerCase();

        return str1 + str2;
    }
    public static void main(String[] args) throws  IOException {
        String s = "3people unFollowed me";
        String str = "";
        String answer = "";
        for(int i=0; i<=s.length(); i++) {
            if(i == s.length() || s.charAt(i)==' ') {
                if(str.length() != 0) answer += changeRight(str);
                str = "";
                if(i != s.length())answer += ' ';
            }
            else str += s.charAt(i);
        }

        System.out.println(answer);
    }
}
