import java.util.Scanner;

class sample
{
    int n;
    public void input()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Value of n:");
        n=sc.nextInt();
        System.out.println("Displaying the value of n:"+n);
    }


public static void main(String[] args)
{
    sample s= new sample();
    s.input();
}
}