#include <vector>
#include <string>
#include <TCanvas.h>
#include <TPad.h>
#include <TH1F.h>
#include <TF1.h>
#include <fstream>
#include <iostream>



void FitMethod2Fall()
{
double phi1, asym1, err1, phi2, asym2, err2, phi3, asym3, err3, phi4, asym4, err4, phi5, asym5, err5, phi6, asym6, err6, phi7, asym7, err7, phi8, asym8, err8;

FILE * fp1 = fopen("bin1-Out.txt", "r"); 
FILE * fp2 = fopen("bin2-Out.txt", "r"); 
FILE * fp3 = fopen("bin3-Out.txt", "r"); 
FILE * fp4 = fopen("bin4-Out.txt", "r"); 
FILE * fp5 = fopen("bin5-Out.txt", "r"); 
FILE * fp6 = fopen("bin6-Out.txt", "r"); 
FILE * fp7 = fopen("bin7-Out.txt", "r"); 
FILE * fp8 = fopen("bin8-Out.txt", "r"); 


int n=0;
int m=0;
int o=0;
int p=0;
int q=0;
int r=0;
int s=0;
int t=0;

////////////////////////////////////////////////////////////////////////////////
TCanvas*c01 = new TCanvas("c01", "Bin 1 Asymm", 1600,1000);
c01->Divide(1,1);
c01->Print("FitMethod2Bin1.pdf[");
TGraphErrors*h1 = new TGraphErrors();

for(int k=0; k<20; k++){ 
fscanf(fp1, "%lf %lf %lf ", &phi1, &asym1, &err1);

n = h1->GetN();

h1->SetPoint(n, phi1, asym1);
h1->SetPointError(n ,0, err1);

}
fclose(fp1);

////////////////////////////////////////////////////////////////////////////////
TCanvas*c02 = new TCanvas("c02", "Bin 2 Asymm", 1600,1000);
c02->Divide(1,1);
c02->Print("FitMethod2Bin2.pdf[");
TGraphErrors*h2 = new TGraphErrors(); 

for(int k=0; k<20; k++){ 
fscanf(fp2, "%lf %lf %lf ", &phi2, &asym2, &err2);

m = h2->GetN();

h2->SetPoint(m, phi2, asym2);
h2->SetPointError(m ,0, err2);

}
fclose(fp2);
////////////////////////////////////////////////////////////////////////////////
TCanvas*c03 = new TCanvas("c03", "Bin 3 Asymm", 1600,1000);
c03->Divide(1,1);
c03->Print("FitMethod2Bin3.pdf[");
TGraphErrors*h3 = new TGraphErrors(); 

for(int k=0; k<20; k++){ 
fscanf(fp3, "%lf %lf %lf ", &phi3, &asym3, &err3);

o = h3->GetN();

h3->SetPoint(o, phi3, asym3);
h3->SetPointError(o ,0, err3);

}
fclose(fp3);
////////////////////////////////////////////////////////////////////////////////
TCanvas*c04 = new TCanvas("c04", "Bin 4 Asymm", 1600,1000);
c04->Divide(1,1);
c04->Print("FitMethod2Bin4.pdf[");
TGraphErrors*h4 = new TGraphErrors(); 

for(int k=0; k<20; k++){ 
fscanf(fp4, "%lf %lf %lf ", &phi4, &asym4, &err4);

p = h4->GetN();

h4->SetPoint(p, phi4, asym4);
h4->SetPointError(p ,0, err4);

}
fclose(fp4);
////////////////////////////////////////////////////////////////////////////////
TCanvas*c05 = new TCanvas("c05", "Bin 5 Asymm", 1600,1000);
c05->Divide(1,1);
c05->Print("FitMethod2Bin5.pdf[");
TGraphErrors*h5 = new TGraphErrors(); 

for(int k=0; k<20; k++){ 
fscanf(fp5, "%lf %lf %lf ", &phi5, &asym5, &err5);

q = h5->GetN();

h5->SetPoint(q, phi5, asym5);
h5->SetPointError(q ,0, err5);

}
fclose(fp5);
////////////////////////////////////////////////////////////////////////////////
TCanvas*c06 = new TCanvas("c06", "Bin 6 Asymm", 1600,1000);
c06->Divide(1,1);
c06->Print("FitMethod2Bin6.pdf[");
TGraphErrors*h6 = new TGraphErrors(); 

for(int k=0; k<20; k++){ 
fscanf(fp6, "%lf %lf %lf ", &phi6, &asym6, &err6);

r = h6->GetN();

h6->SetPoint(r, phi6, asym6);
h6->SetPointError(r ,0, err6);

}
fclose(fp6);
/*
////////////////////////////////////////////////////////////////////////////////
TCanvas*c07 = new TCanvas("c07", "Bin 7 Asymm", 1600,1000);
c07->Divide(1,1);
c07->Print("FitMethod2Bin7.pdf[");
TGraphErrors*h7 = new TGraphErrors(); 

for(int k=0; k<20; k++){ 
fscanf(fp7, "%lf %lf %lf ", &phi7, &asym7, &err7);

s = h7->GetN();

h7->SetPoint(s, phi7, asym7);
h7->SetPointError(s ,0, err7);

}
fclose(fp7);
////////////////////////////////////////////////////////////////////////////////
TCanvas*c08 = new TCanvas("c08", "Bin 8 Asymm", 1600,1000);
c08->Divide(1,1);
c08->Print("FitMethod2Bin8.pdf[");
TGraphErrors*h8 = new TGraphErrors(); 

for(int k=0; k<20; k++){ 
fscanf(fp8, "%lf %lf %lf ", &phi8, &asym8, &err8);

t = h8->GetN();

h7->SetPoint(t, phi8, asym8);
h7->SetPointError(t ,0, err8);

}
fclose(fp8);
////////////////////////////////////////////////////////////////////////////////
*/
TF1 *f2= new TF1("f2","[0]+([1]*sin(x))+([2]*(sin(2*x)))",0,6.4); 

////////////////////////////////////////////////////////////////////////////////
c01->cd(1);
gStyle->SetOptStat(0);
gStyle->SetOptFit(); 
h1->GetXaxis()->SetTitle("Delta Phi");
h1->GetXaxis()->SetTitleSize(0.05);
h1->GetXaxis()->SetLabelSize(0.05);
h1->GetXaxis()->SetTitleOffset(1);
h1->GetYaxis()->SetTitle("Asymmetry Value (0<pTpT<0.1)");
h1->GetYaxis()->SetTitleSize(0.05);
h1->GetYaxis()->SetLabelSize(0.02);
h1->SetLineWidth(1.5);

h1->Fit("f2");
h1->SetLineWidth(1.5);
h1->SetMarkerStyle(20);
h1->SetMarkerColor(4);
cout << "Chi2: " << h1->GetFunction("f2")->GetChisquare(); 
cout << " Reduced Chi2: " << h1->GetFunction("f2")->GetChisquare()/(17); 
h1->Draw("AP");

////////////////////////////////////////////////////////////////////////////////
c02->cd(1);
gStyle->SetOptStat(0);
gStyle->SetOptFit(); 
h2->GetXaxis()->SetTitle("Delta Phi");
h2->GetXaxis()->SetTitleSize(0.05);
h2->GetXaxis()->SetLabelSize(0.05);
h2->GetXaxis()->SetTitleOffset(1);
h2->GetYaxis()->SetTitle("Asymmetry Value (0.1<pTpT<0.2)");
h2->GetYaxis()->SetTitleSize(0.05);
h2->GetYaxis()->SetLabelSize(0.02);
h2->SetLineWidth(1.5);

h2->Fit("f2");
h2->SetLineWidth(1.5);
h2->SetMarkerStyle(20);
h2->SetMarkerColor(4);
cout << "Chi2: " << h2->GetFunction("f2")->GetChisquare(); 
cout << " Reduced Chi2: " << h2->GetFunction("f2")->GetChisquare()/(17); 
h2->Draw("AP");
////////////////////////////////////////////////////////////////////////////////
c03->cd(1);
gStyle->SetOptStat(0);
gStyle->SetOptFit(); 
h3->GetXaxis()->SetTitle("Delta Phi");
h3->GetXaxis()->SetTitleSize(0.05);
h3->GetXaxis()->SetLabelSize(0.05);
h3->GetXaxis()->SetTitleOffset(1);
h3->GetYaxis()->SetTitle("Asymmetry Value (0.2<pTpT<0.3)");
h3->GetYaxis()->SetTitleSize(0.05);
h3->GetYaxis()->SetLabelSize(0.02);
h3->SetLineWidth(1.5);

h3->Fit("f2");
h3->SetLineWidth(1.5);
h3->SetMarkerStyle(20);
h3->SetMarkerColor(4);
cout << "Chi2: " << h3->GetFunction("f2")->GetChisquare(); 
cout << " Reduced Chi2: " << h3->GetFunction("f2")->GetChisquare()/(17); 
h3->Draw("AP");
////////////////////////////////////////////////////////////////////////////////
c04->cd(1);
gStyle->SetOptStat(0);
gStyle->SetOptFit(); 
h4->GetXaxis()->SetTitle("Delta Phi");
h4->GetXaxis()->SetTitleSize(0.05);
h4->GetXaxis()->SetLabelSize(0.05);
h4->GetXaxis()->SetTitleOffset(1);
h4->GetYaxis()->SetTitle("Asymmetry Value (0.3<pTpT<0.4)");
h4->GetYaxis()->SetTitleSize(0.05);
h4->GetYaxis()->SetLabelSize(0.02);
h4->SetLineWidth(1.5);

h4->Fit("f2");
h4->SetLineWidth(1.5);
h4->SetMarkerStyle(20);
h4->SetMarkerColor(4);
cout << "Chi2: " << h4->GetFunction("f2")->GetChisquare(); 
cout << " Reduced Chi2: " << h4->GetFunction("f2")->GetChisquare()/(17); 
h4->Draw("AP");
////////////////////////////////////////////////////////////////////////////////
c05->cd(1);
gStyle->SetOptStat(0);
gStyle->SetOptFit(); 
h5->GetXaxis()->SetTitle("Delta Phi");
h5->GetXaxis()->SetTitleSize(0.05);
h5->GetXaxis()->SetLabelSize(0.05);
h5->GetXaxis()->SetTitleOffset(1);
h5->GetYaxis()->SetTitle("Asymmetry Value (0.4<pTpT<0.5)");
h5->GetYaxis()->SetTitleSize(0.05);
h5->GetYaxis()->SetLabelSize(0.02);
h5->SetLineWidth(1.5);

h5->Fit("f2");
h5->SetLineWidth(1.5);
h5->SetMarkerStyle(20);
h5->SetMarkerColor(4);
cout << "Chi2: " << h5->GetFunction("f2")->GetChisquare(); 
cout << " Reduced Chi2: " << h5->GetFunction("f2")->GetChisquare()/(17); 
h5->Draw("AP");
////////////////////////////////////////////////////////////////////////////////
c06->cd(1);
gStyle->SetOptStat(0);
gStyle->SetOptFit(); 
h6->GetXaxis()->SetTitle("Delta Phi");
h6->GetXaxis()->SetTitleSize(0.05);
h6->GetXaxis()->SetLabelSize(0.05);
h6->GetXaxis()->SetTitleOffset(1);
h6->GetYaxis()->SetTitle("Asymmetry Value (0.5<pTpT<0.6)");
h6->GetYaxis()->SetTitleSize(0.05);
h6->GetYaxis()->SetLabelSize(0.02);
h6->SetLineWidth(1.5);

h6->Fit("f2");
h6->SetLineWidth(1.5);
h6->SetMarkerStyle(20);
h6->SetMarkerColor(4);
cout << "Chi2: " << h6->GetFunction("f2")->GetChisquare(); 
cout << " Reduced Chi2: " << h6->GetFunction("f2")->GetChisquare()/(17); 
h6->Draw("AP");
/*
////////////////////////////////////////////////////////////////////////////////
c07->cd(1);
gStyle->SetOptStat(0);
gStyle->SetOptFit(); 
h7->GetXaxis()->SetTitle("Delta Phi");
h7->GetXaxis()->SetTitleSize(0.05);
h7->GetXaxis()->SetLabelSize(0.05);
h7->GetXaxis()->SetTitleOffset(1);
h7->GetYaxis()->SetTitle("Asymmetry Value (0.6<pTpT<0.7)");
h7->GetYaxis()->SetTitleSize(0.05);
h7->GetYaxis()->SetLabelSize(0.02);
h7->SetLineWidth(1.5);

h7->Fit("f2");
h7->SetLineWidth(1.5);
h7->SetMarkerStyle(20);
h7->SetMarkerColor(4);
cout << "Chi2: " << h7->GetFunction("f2")->GetChisquare(); 
cout << " Reduced Chi2: " << h7->GetFunction("f2")->GetChisquare()/(17); 
h7->Draw("AP");
////////////////////////////////////////////////////////////////////////////////
c08->cd(1);
gStyle->SetOptStat(0);
gStyle->SetOptFit(); 
h8->GetXaxis()->SetTitle("Delta Phi");
h8->GetXaxis()->SetTitleSize(0.05);
h8->GetXaxis()->SetLabelSize(0.05);
h8->GetXaxis()->SetTitleOffset(1);
h8->GetYaxis()->SetTitle("Asymmetry Value (0.7<pTpT<0.8)");
h8->GetYaxis()->SetTitleSize(0.05);
h8->GetYaxis()->SetLabelSize(0.02);
h8->SetLineWidth(1.5);

h8->Fit("f2");
h8->SetLineWidth(1.5);
h8->SetMarkerStyle(20);
h8->SetMarkerColor(4);
cout << "Chi2: " << h8->GetFunction("f2")->GetChisquare(); 
cout << " Reduced Chi2: " << h8->GetFunction("f2")->GetChisquare()/(17); 
h8->Draw("AP");
*/
////////////////////////////////////////////////////////////////////////////////
gPad->Modified();
gPad->Update();

c01->Print("FitMethod2Bin1.pdf");
c01->Print("FitMethod2Bin1.pdf]");
c02->Print("FitMethod2Bin2.pdf");
c02->Print("FitMethod2Bin2.pdf]");
c03->Print("FitMethod2Bin3.pdf");
c03->Print("FitMethod2Bin3.pdf]");
c04->Print("FitMethod2Bin4.pdf");
c04->Print("FitMethod2Bin4.pdf]");
c05->Print("FitMethod2Bin5.pdf");
c05->Print("FitMethod2Bin5.pdf]");
c06->Print("FitMethod2Bin6.pdf");
c06->Print("FitMethod2Bin6.pdf]");
/*c07->Print("FitMethod2Bin7.pdf");
c07->Print("FitMethod2Bin7.pdf]");
c08->Print("FitMethod2Bin8.pdf");
c08->Print("FitMethod2Bin8.pdf]");
*/
}
