import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.FileOutputStream;

public class AsymMMTotal
{
  public static void main(String args[])
  {
    Scanner inputStream = null;
    
    double[][] xa = new double [14][1000];
    double[][] xb = new double [14][1000];
    double[][] ya = new double [14][1000];
    double[][] yb = new double [14][1000];
    double[][] sin = new double [14][1000];
    double[][] x2 = new double [14][1000];
    double[][] y2 = new double [14][1000];
    
    double[] erA = new double [14];
    double[] a = new double [14];
    double[] sum = new double [14];
    double[] sum1 = new double [14];
    double[] sum2 = new double [14];
    double[] sumYa = new double [14];
    double[] sumYb = new double [14];
    double[] sumY2 = new double [14];
    
    int t=0, u=0, v=0, w=0, x=0, y=0, z=0, n=0, l=0, q=0;
    double p = 0.8575;     
    
   
    try //Table 1
    {
      inputStream =
        new Scanner(new FileInputStream("MomentsMethodBin1.txt"));
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
    
    while(inputStream.hasNextDouble())
    {
      xa[0][t] = inputStream.nextDouble();
      ya[0][t] = inputStream.nextDouble();
      xb[0][t] = inputStream.nextDouble();
      yb[0][t] = inputStream.nextDouble();
      x2[0][t] = inputStream.nextDouble();
      y2[0][t] = inputStream.nextDouble();
      
      sum[0]=sum[0]+(xa[0][t]*ya[0][t]); //Sum(xa*ya)
      sum1[0]=sum1[0]+(yb[0][t]*xb[0][t]); //Sum(xb*yb)
      sum2[0]=sum2[0]+(x2[0][t]*y2[0][t]);
      
      sumYa[0]=sumYa[0]+ya[0][t];
      sumYb[0]=sumYb[0]+yb[0][t];
      sumY2[0]=sumY2[0]+y2[0][t];
      
      t++;
    }
    inputStream.close();
    
    try //Table 2
    {
      inputStream =
        new Scanner(new FileInputStream("MomentsMethodBin2.txt"));
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
    
    while(inputStream.hasNextDouble())
    {
      xa[1][u] = inputStream.nextDouble();
      ya[1][u] = inputStream.nextDouble();
      xb[1][u] = inputStream.nextDouble();
      yb[1][u] = inputStream.nextDouble();
      x2[1][u] = inputStream.nextDouble();
      y2[1][u] = inputStream.nextDouble();
      
      sum[1]=sum[1]+(xa[1][u]*ya[1][u]); //Sum(xa*ya)
      sum1[1]=sum1[1]+(yb[1][u]*xb[1][u]); //Sum(xb*yb)
      sum2[1]=sum2[1]+(x2[1][u]*y2[1][u]);
      
      sumYa[1]=sumYa[1]+ya[1][u];
      sumYb[1]=sumYb[1]+yb[1][u];
      sumY2[1]=sumY2[1]+y2[1][u];
      
      u++;
    }
    inputStream.close();
    
    try //Table 3
    {
      inputStream =
        new Scanner(new FileInputStream("MomentsMethodBin3.txt"));
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
    
    while(inputStream.hasNextDouble())
    {
      xa[2][v] = inputStream.nextDouble();
      ya[2][v] = inputStream.nextDouble();
      xb[2][v] = inputStream.nextDouble();
      yb[2][v] = inputStream.nextDouble();
      x2[2][v] = inputStream.nextDouble();
      y2[2][v] = inputStream.nextDouble();
      
      sum[2]=sum[2]+(xa[2][v]*ya[2][v]); //Sum(xa*ya)
      sum1[2]=sum1[2]+(yb[2][v]*xb[2][v]); //Sum(xb*yb)
      sum2[2]=sum2[2]+(x2[2][v]*y2[2][v]);
      
      sumYa[2]=sumYa[2]+ya[2][v];
      sumYb[2]=sumYb[2]+yb[2][v];
      sumY2[2]=sumY2[2]+y2[2][v];
      
      v++;
    }
    inputStream.close();
    
    try //Table 4
    {
      inputStream =
        new Scanner(new FileInputStream("MomentsMethodBin4.txt"));
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
    
    while(inputStream.hasNextDouble())
    {
      xa[3][w] = inputStream.nextDouble();
      ya[3][w] = inputStream.nextDouble();
      xb[3][w] = inputStream.nextDouble();
      yb[3][w] = inputStream.nextDouble();
      x2[3][w] = inputStream.nextDouble();
      y2[3][w] = inputStream.nextDouble();
      
      sum[3]=sum[3]+(xa[3][w]*ya[3][w]); //Sum(xa*ya)
      sum1[3]=sum1[3]+(yb[3][w]*xb[3][w]); //Sum(xb*yb)
      sum2[3]=sum2[3]+(x2[3][w]*y2[3][w]);
      
      sumYa[3]=sumYa[3]+ya[3][w];
      sumYb[3]=sumYb[3]+yb[3][w];
      sumY2[3]=sumY2[3]+y2[3][w];
      
      w++;
    }
    inputStream.close();
  
    try //Table 5
    {
      inputStream =
        new Scanner(new FileInputStream("MomentsMethodBin5.txt"));
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
    
    while(inputStream.hasNextDouble())
    {
      xa[4][x] = inputStream.nextDouble();
      ya[4][x] = inputStream.nextDouble();
      xb[4][x] = inputStream.nextDouble();
      yb[4][x] = inputStream.nextDouble();
      x2[4][x] = inputStream.nextDouble();
      y2[4][x] = inputStream.nextDouble();
      
      sum[4]=sum[4]+(xa[4][x]*ya[4][x]); //Sum(xa*ya)
      sum1[4]=sum1[4]+(yb[4][x]*xb[4][x]); //Sum(xb*yb)
      sum2[4]=sum2[4]+(x2[4][x]*y2[4][x]);
      
      sumYa[4]=sumYa[4]+ya[4][x];
      sumYb[4]=sumYb[4]+yb[4][x];
      sumY2[4]=sumY2[4]+y2[4][x];
      
      x++;
    }
    inputStream.close();
      

 try //Table 6
    {
      inputStream =
        new Scanner(new FileInputStream("MomentsMethodBin6.txt"));
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
    
    while(inputStream.hasNextDouble())
    {
      xa[5][l] = inputStream.nextDouble();
      ya[5][l] = inputStream.nextDouble();
      xb[5][l] = inputStream.nextDouble();
      yb[5][l] = inputStream.nextDouble();
      x2[5][l] = inputStream.nextDouble();
      y2[5][l] = inputStream.nextDouble();
      
      sum[5]=sum[5]+(xa[5][l]*ya[5][l]); //Sum(xa*ya)
      sum1[5]=sum1[5]+(yb[5][l]*xb[5][l]); //Sum(xb*yb)
      sum2[5]=sum2[5]+(x2[5][l]*y2[5][l]);
      
      sumYa[5]=sumYa[5]+ya[5][l];
      sumYb[5]=sumYb[5]+yb[5][l];
      sumY2[5]=sumY2[5]+y2[5][l];
      
      l++;
    }
    inputStream.close();

     
    PrintWriter outputStream = null;
    try //Output 
    {
      outputStream =
        new PrintWriter(new FileOutputStream("OutputsMMTotal.txt")); 
    }
    catch(FileNotFoundException e)
    {
      System.exit(0);
    }
   while (n < 7)
    {
      a[n]= (sum[n]-sum1[n])/sum2[n];
      erA[n]= (1/(2*p))*Math.sqrt((sumYa[n]*sumYb[n])/Math.pow(sumY2[n],3));
      outputStream.println("Bin " + (n+1)); 
      outputStream.println("A = " + a[n]);
      outputStream.println("A/P = " + a[n]/p);
      outputStream.println("Error = " + erA[n]);
      n++;
    }
   outputStream.close();
    
  }
}
