import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.FileOutputStream;

public class Asymmetry2Spring
{
  public static void main(String args[])
  {
    Scanner inputStream = null;
    
    double[][] n1 = new double[200][200];
    double[][] n2 = new double[200][200];
    double[][] n3 = new double[200][200];
    double[][] n4 = new double[200][200];
    double[][] pTpT = new double[200][200];
    double[][] a = new double[200][200];
    double[][] errA = new double[200][200];
    int[] count = new int[200];
    int[] sum = new int[200];
    
        
    double p = 0.85;
    double pi = 3.1416;
    
    
    
    
    try //Table 1
    {
      inputStream =
        new Scanner(new FileInputStream("NewAsymmetrySpring.txt"));
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
    
    while(inputStream.hasNextDouble())
    {
      pTpT[0][count[0]] = inputStream.nextDouble();
      n1[0][count[0]] = inputStream.nextDouble();
      n2[0][count[0]] = inputStream.nextDouble();
      n3[0][count[0]] = inputStream.nextDouble();
      n4[0][count[0]] = inputStream.nextDouble();
      count[0]++;
    }
    inputStream.close();

    
    
    
    PrintWriter outputStream = null;
    try //Output Table 1
    {
      outputStream =
        new PrintWriter(new FileOutputStream("NewAsymmetrySpring-Out.txt")); 
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
   sum[0] = 0;
   sum[1] = 0;
   sum[2] = 0;
   sum[3] = 0;
   while (sum[0] < count[0])
    {
      a[0][sum[0]]= (pi/(2*p))*(((n1[0][sum[0]]-n2[0][sum[0]])/(n1[0][sum[0]]+n2[0][sum[0]]))-((n3[0][sum[0]]-n4[0][sum[0]])/(n3[0][sum[0]]+n4[0][sum[0]])));
      errA[0][sum[0]]= (pi/p)*Math.sqrt(((n1[0][sum[0]]*n2[0][sum[0]])/(Math.pow(n1[0][sum[0]]+n2[0][sum[0]],3)))+((n3[0][sum[0]]*n4[0][sum[0]])/(Math.pow(n3[0][sum[0]]+n4[0][sum[0]],3))));
      outputStream.println(pTpT[0][sum[0]] + "    " + a[0][sum[0]] + "    " + errA[0][sum[0]]);
      sum[0]++;
    }
   outputStream.close();
   
    

  }
}