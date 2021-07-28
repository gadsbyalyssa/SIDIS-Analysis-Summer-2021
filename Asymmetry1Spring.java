import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.FileOutputStream;

public class Asymmetry1Spring
{
  public static void main(String args[])
  {
    Scanner inputStream = null;
    
    double[][] n1 = new double[100][100];
    double[][] n2 = new double[100][100];
    double[][] phi = new double[100][100];
    double[][] a = new double[100][100];
    double[][] error = new double[100][100];
    int[] count = new int[100];
    int[] sum = new int[100];
    
    int x = 0;    
    double p = 0.85;
    
    
    
    
    try //Table 1
    {
      inputStream =
        new Scanner(new FileInputStream("FitMethodBin1.txt"));
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
    
    while(inputStream.hasNextDouble())
    {
      phi[0][count[0]] = inputStream.nextDouble();
      n1[0][count[0]] = inputStream.nextDouble();
      n2[0][count[0]] = inputStream.nextDouble();
      count[0]++;
    }
    inputStream.close();
    


    try //Table 2
    {
      inputStream =
        new Scanner(new FileInputStream("FitMethodBin2.txt"));
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
    
    while(inputStream.hasNextDouble())
    {
      phi[1][count[1]] = inputStream.nextDouble();
      n1[1][count[1]] = inputStream.nextDouble();
      n2[1][count[1]] = inputStream.nextDouble();
      count[1]++;
    }
    inputStream.close();
    
    
    try //Table 3
    {
      inputStream =
        new Scanner(new FileInputStream("FitMethodBin3.txt"));
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
    
    while(inputStream.hasNextDouble())
    {
      phi[2][count[2]] = inputStream.nextDouble();
      n1[2][count[2]] = inputStream.nextDouble();
      n2[2][count[2]] = inputStream.nextDouble();
      count[2]++;
    }
    inputStream.close();
    
    
    try //Table 4
    {
      inputStream =
        new Scanner(new FileInputStream("FitMethodBin4.txt"));
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
 
    while(inputStream.hasNextDouble())
    {
      phi[3][count[3]] = inputStream.nextDouble();
      n1[3][count[3]] = inputStream.nextDouble();
      n2[3][count[3]] = inputStream.nextDouble();
      count[3]++;
    }
    inputStream.close();
    
    try //Table 5
    {
      inputStream =
        new Scanner(new FileInputStream("FitMethodBin5.txt"));
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
    
    while(inputStream.hasNextDouble())
    {
      phi[4][count[4]] = inputStream.nextDouble();
      n1[4][count[4]] = inputStream.nextDouble();
      n2[4][count[4]] = inputStream.nextDouble();
      count[4]++;
    }
    inputStream.close();
    


    try //Table 6
    {
      inputStream =
        new Scanner(new FileInputStream("FitMethodBin6.txt"));
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
    
    while(inputStream.hasNextDouble())
    {
      phi[5][count[5]] = inputStream.nextDouble();
      n1[5][count[5]] = inputStream.nextDouble();
      n2[5][count[5]] = inputStream.nextDouble();
      count[5]++;
    }
    inputStream.close();
    
    
    try //Table 7
    {
      inputStream =
        new Scanner(new FileInputStream("FitMethodBin7.txt"));
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
    
    while(inputStream.hasNextDouble())
    {
      phi[6][count[6]] = inputStream.nextDouble();
      n1[6][count[6]] = inputStream.nextDouble();
      n2[6][count[6]] = inputStream.nextDouble();
      count[6]++;
    }
    inputStream.close();
    
    
    try //Table 8
    {
      inputStream =
        new Scanner(new FileInputStream("FitMethodBin8.txt"));
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
 
    while(inputStream.hasNextDouble())
    {
      phi[7][count[7]] = inputStream.nextDouble();
      n1[7][count[7]] = inputStream.nextDouble();
      n2[7][count[7]] = inputStream.nextDouble();
      count[7]++;
    }
    inputStream.close();
    
    
    
    
    PrintWriter outputStream = null;
    try //Output Table 1
    {
      outputStream =
        new PrintWriter(new FileOutputStream("bin1-Out.txt")); 
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
   while (x < 8)
   {
   sum[x] = 1;
   x++;
   }
   while (sum[0] < count[0])
    {
      a[0][sum[0]]= (1/p)*(n1[0][sum[0]]-n2[0][sum[0]])/(n1[0][sum[0]]+n2[0][sum[0]]);
      error[0][sum[0]]= (2/p)*Math.sqrt((n1[0][sum[0]]*n2[0][sum[0]])/(Math.pow(n1[0][sum[0]]+n2[0][sum[0]],3)));
      outputStream.println(phi[0][sum[0]] + "    " + a[0][sum[0]] + "    " + error[0][sum[0]]);
      sum[0]++;
    }
   outputStream.close();
   
    try //Output Table 2
    {
      outputStream =
        new PrintWriter(new FileOutputStream("bin2-Out.txt")); 
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
   while (sum[1] < count[1])
    {
      a[1][sum[1]]= (1/p)*(n1[1][sum[1]]-n2[1][sum[1]])/(n1[1][sum[1]]+n2[1][sum[1]]);
      error[1][sum[1]]= (2/p)*Math.sqrt((n1[1][sum[1]]*n2[1][sum[1]])/(Math.pow(n1[1][sum[1]]+n2[1][sum[1]],3)));
      outputStream.println(phi[1][sum[1]] + "    " + a[1][sum[1]] + "    " + error[1][sum[1]]);
      sum[1]++;
    }
   outputStream.close();
   
    try //Output Table 3
    {
      outputStream =
        new PrintWriter(new FileOutputStream("bin3-Out.txt")); 
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
   while (sum[2] < count[2])
    {
      a[2][sum[2]]= (1/p)*(n1[2][sum[2]]-n2[2][sum[2]])/(n1[2][sum[2]]+n2[2][sum[2]]);
      error[2][sum[2]]= (2/p)*Math.sqrt((n1[2][sum[2]]*n2[2][sum[2]])/(Math.pow(n1[2][sum[2]]+n2[2][sum[2]],3)));
      outputStream.println(phi[2][sum[2]] + "    " + a[2][sum[2]] + "    " + error[2][sum[2]]);
      sum[2]++;
    }
   outputStream.close();
   
    try //Output Table 4
    {
      outputStream =
        new PrintWriter(new FileOutputStream("bin4-Out.txt")); 
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
   while (sum[3] < count[3])
    {
      a[3][sum[3]]= (1/p)*(n1[3][sum[3]]-n2[3][sum[3]])/(n1[3][sum[3]]+n2[3][sum[3]]);
      error[3][sum[3]]= (2/p)*Math.sqrt((n1[3][sum[3]]*n2[3][sum[3]])/(Math.pow(n1[3][sum[3]]+n2[3][sum[3]],3)));
      outputStream.println(phi[3][sum[3]] + "    " + a[3][sum[3]] + "    " + error[3][sum[3]]);
      sum[3]++;
    }
   outputStream.close();
   
   
   try //Output Table 5
    {
      outputStream =
        new PrintWriter(new FileOutputStream("bin5-Out.txt")); 
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
   
   while (sum[4] < count[4])
    {
      a[4][sum[4]]= (1/p)*(n1[4][sum[4]]-n2[4][sum[4]])/(n1[4][sum[4]]+n2[4][sum[4]]);
      error[4][sum[4]]= (2/p)*Math.sqrt((n1[4][sum[4]]*n2[4][sum[4]])/(Math.pow(n1[4][sum[4]]+n2[4][sum[4]],3)));
      outputStream.println(phi[4][sum[4]] + "    " + a[4][sum[4]] + "    " + error[4][sum[4]]);
      sum[4]++;
    }
   outputStream.close();
   
    try //Output Table 6
    {
      outputStream =
        new PrintWriter(new FileOutputStream("bin6-Out.txt")); 
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
   while (sum[5] < count[5])
    {
      a[5][sum[5]]= (1/p)*(n1[5][sum[5]]-n2[5][sum[5]])/(n1[5][sum[5]]+n2[5][sum[5]]);
      error[5][sum[5]]= (2/p)*Math.sqrt((n1[5][sum[5]]*n2[5][sum[5]])/(Math.pow(n1[5][sum[5]]+n2[5][sum[5]],3)));
      outputStream.println(phi[5][sum[5]] + "    " + a[5][sum[5]] + "    " + error[5][sum[5]]);
      sum[5]++;
    }
   outputStream.close();
   
    try //Output Table 7
    {
      outputStream =
        new PrintWriter(new FileOutputStream("bin7-Out.txt")); 
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
   while (sum[6] < count[6])
    {
      a[6][sum[6]]= (1/p)*(n1[6][sum[6]]-n2[6][sum[6]])/(n1[6][sum[6]]+n2[6][sum[6]]);
      error[6][sum[6]]= (2/p)*Math.sqrt((n1[6][sum[6]]*n2[6][sum[6]])/(Math.pow(n1[6][sum[6]]+n2[6][sum[6]],3)));
      outputStream.println(phi[6][sum[6]] + "    " + a[6][sum[6]] + "    " + error[6][sum[6]]);
      sum[6]++;
    }
   outputStream.close();
   
    try //Output Table 8
    {
      outputStream =
        new PrintWriter(new FileOutputStream("bin8-Out.txt")); 
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
   while (sum[7] < count[7])
    {
      a[7][sum[7]]= (1/p)*(n1[7][sum[7]]-n2[7][sum[7]])/(n1[7][sum[7]]+n2[7][sum[7]]);
      error[7][sum[7]]= (2/p)*Math.sqrt((n1[7][sum[7]]*n2[7][sum[7]])/(Math.pow(n1[7][sum[7]]+n2[7][sum[7]],3)));
      outputStream.println(phi[7][sum[7]] + "    " + a[7][sum[7]] + "    " + error[7][sum[7]]);
      sum[7]++;
    }
   outputStream.close();

  }
}