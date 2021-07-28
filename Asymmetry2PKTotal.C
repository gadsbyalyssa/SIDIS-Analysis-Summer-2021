#include <vector>
#include <string>
#include <TCanvas.h>
#include <TPad.h>
#include <TH1F.h>
#include <TF1.h>
#include <fstream>
#include <iostream>



void Asymmetry2PKTotal()
{

////////////////////////////////////////////////////////////////////////////////
TCanvas*c03 = new TCanvas("c03", "Full Asymm", 1600,1000);
c03->Divide(1,1);
c03->Print("FullAsymmetry2PK3.pdf[");

const Int_t n1 = 6; //Moments Method Fall 2018
Double_t x1[n1] = {0.05, 0.15, 0.25, 0.35, 0.45, 0.55};
Double_t y1[n1] = {-0.01448027001210511,-0.014319812040954056, -0.012046525666751323, 0.016198365401310963, -0.0465595001749183, -0.07951837857719678};
Double_t ex1[n1] = {0, 0, 0, 0, 0, 0};
Double_t ey1[n1] = {0.00087543857, 0.000886703384, 0.0012465221046204268, 0.0018805910306408712, 0.002902221909605188, 0.004493249531920615};

const Int_t n2 = 6; //Fit Method Fall 2018
Double_t x2[n2] = {0.052, 0.152, 0.252, 0.352, 0.452, 0.552};
Double_t y2[n2] = {-0.01373, -0.01518, -0.010927, 0.015887, -0.063507, -0.0556577 };
Double_t ex2[n2] = {0, 0, 0, 0, 0, 0};
Double_t ey2[n2] = {0.005241, 0.005683, 0.009488, 0.01848, 0.04077, 0.09338};

const Int_t n3 = 6; //Moments Method Spring 2019
Double_t x3[n3] = {0.054, 0.154, 0.254, 0.354, 0.454, 0.554};
Double_t y3[n3] = {-0.014705050435864257, -0.01996717169818551, -0.01074723952261063, -0.0170808283315638, -0.011057980142055652, -0.09643827566078832};
Double_t ex3[n3] = {0, 0, 0, 0, 0, 0};
Double_t ey3[n3] = {0.00087543857, 0.000886703384, 0.0012465221046204268, 0.001902221909605188, 0.002493249531920615, 0.007085874489312935};

const Int_t n4 = 6; //Fit Method Spring 2019
Double_t x4[n4] = {0.056, 0.156, 0.256, 0.356, 0.456, 0.556};
Double_t y4[n4] = {-0.01491, -0.02036, -0.012853, -0.0101644, -0.03491, 0.02456 };
Double_t ex4[n4] = {0, 0, 0, 0, 0, 0};
Double_t ey4[n4] = {0.004978, 0.005449, 0.00937, 0.01848, 0.04077, 0.176};

const Int_t n5 = 6; //Moments Method Total
Double_t x5[n5] = {0.058, 0.158, 0.258, 0.358, 0.458, 0.558};
Double_t y5[n5] = {-0.011589277833850162, -0.017989948387349392, -0.011708602428614872, -0.016188479226669195, -0.012261093668510667, -0.070254497724239647 };
Double_t ex5[n5] = {0, 0, 0, 0, 0, 0};
Double_t ey5[n5] = {0.0006135, 0.00062102, 0.0008821, 0.0013401041903711103, 0.002080212290603831, 0.005135357927872794};

const Int_t n6 = 6; //Fit Method Total
Double_t x6[n6] = {0.06, 0.16, 0.26, 0.36, 0.46, 0.56};
Double_t y6[n6] = {-0.0115765, -0.0186919, -0.010924, -0.006891, -0.011867, -0.021624 };
Double_t ex6[n6] = {0, 0, 0, 0, 0, 0};
Double_t ey6[n6] = {0.0039779, 0.0039845, 0.006794, 0.013524, 0.029651, 0.06886};

const Int_t n7 = 6; //Difference Method Fall 2018
Double_t x7[n7] = {0.062, 0.162, 0.262, 0.362, 0.462, 0.562};
Double_t y7[n7] = {-0.032779299946827406, -0.02955837675451659, -0.020782783388841403, 0.021411000031802054, -0.08154032791183864, -0.09148939544354545 };
Double_t ex7[n7] = {0, 0, 0, 0, 0, 0};
Double_t ey7[n7] = {0.011568892438224043, 0.011732964432553093, 0.016499230561031676, 0.024960104094749212, 0.038402077958645565, 0.05930416856497757};

const Int_t n8 = 6; //Difference Method Spring 2019
Double_t x8[n8] = {0.064, 0.164, 0.264, 0.364, 0.464, 0.564};
Double_t y8[n8] = {-0.03631616403471906 , -0.03683748708528066 , -0.03081338159300064 , -0.03388514772724299, -0.011625784160482391, 0.011751132159242268  };
Double_t ex8[n8] = {0, 0, 0, 0, 0, 0};
Double_t ey8[n8] = {0.011239489105578055, 0.011416407528195456, 0.01628510196755915, 0.02494932427114443, 0.0389009211317983, 0.06159762629453899};

const Int_t n9 = 6; //Difference Method Total
Double_t x9[n9] = {0.066, 0.166, 0.266, 0.366, 0.466, 0.566};
Double_t y9[n9] = {-0.02855076195328011 , -0.03905220142364765 , -0.026130791837549173 , -0.031174901198235256, -0.018614876945443438, -0.011214378812024434 };
Double_t ex9[n9] = {0, 0, 0, 0, 0, 0};
Double_t ey9[n9] = {0.008082835439322993, 0.00818214675446703, 0.0116203423935433, 0.017646165055885416, 0.027374873506834253, 0.04296760395820643};

TGraphErrors*h2 = new TGraphErrors(n1,x1,y1,ex1,ey1);
h2->SetName("h2");
TGraphErrors*h4 = new TGraphErrors(n3,x3,y3,ex3,ey3);
h4->SetName("h4");
TGraphErrors*h7 = new TGraphErrors(n2,x2,y2,ex2,ey2);
h7->SetName("h7");
TGraphErrors*h1 = new TGraphErrors(n4,x4,y4,ex4,ey4);
h1->SetName("h1");
TGraphErrors*h8 = new TGraphErrors(n5,x5,y5,ex5,ey5);
h8->SetName("h8");
TGraphErrors*h9 = new TGraphErrors(n6,x6,y6,ex6,ey6);
h9->SetName("h9");
TGraphErrors*h10 = new TGraphErrors(n7,x7,y7,ex7,ey7);
h10->SetName("h10");
TGraphErrors*h11 = new TGraphErrors(n8,x8,y8,ex8,ey8);
h11->SetName("h11");
TGraphErrors*h12 = new TGraphErrors(n9,x9,y9,ex9,ey9);
h12->SetName("h12");

TMultiGraph*h3 = new TMultiGraph();

////////////////////////////////////////////////////////////////////////////
 
h1->SetName("h1");
h1->GetXaxis()->SetTitle("pTpT");
h1->GetXaxis()->SetTitleSize(0.05);
h1->GetXaxis()->SetLabelSize(0.05);
h1->GetXaxis()->SetTitleOffset(1);
h1->GetYaxis()->SetTitle("Asymmetry Value");
h1->GetYaxis()->SetTitleSize(0.05);
h1->GetYaxis()->SetLabelSize(0.02);

h1->SetMarkerStyle(20);
h1->SetMarkerSize(5);
h1->SetMarkerColor(4);
h1->Draw("AP");

////////////////////////////////////////////////////////////////////////////////
h2->SetName("h2");
h2->GetXaxis()->SetTitle("pTpT");
h2->GetXaxis()->SetTitleSize(0.05);
h2->GetXaxis()->SetLabelSize(0.05);
h2->GetXaxis()->SetTitleOffset(0.8);
h2->GetYaxis()->SetTitle("Asymmetry Value");
h2->GetYaxis()->SetTitleSize(0.05);
h2->GetYaxis()->SetLabelSize(0.02);

h2->SetMarkerStyle(24);
h2->SetMarkerSize(5);
h2->SetMarkerColor(2);
h2->Draw("AP");

h4->SetMarkerStyle(29);
h4->SetMarkerSize(5);
h4->SetMarkerColor(1);

h7->SetMarkerStyle(33);
h7->SetMarkerSize(5);
h7->SetMarkerColor(6);

h8->SetMarkerStyle(22);
h8->SetMarkerSize(5);
h8->SetMarkerColor(9);

h9->SetMarkerStyle(23);
h9->SetMarkerSize(5);
h9->SetMarkerColor(49);

h10->SetMarkerStyle(28);
h10->SetMarkerSize(5);
h10->SetMarkerColor(38);

h11->SetMarkerStyle(8);
h11->SetMarkerSize(5);
h11->SetMarkerColor(49);

h12->SetMarkerStyle(30);
h12->SetMarkerSize(5);
h12->SetMarkerColor(29);

////////////////////////////////////////////////////////////////////////////////
c03->cd(1); 
h3->Add(h1);
h3->Add(h2);
h3->Add(h4);
h3->Add(h7);
h3->Add(h8);
h3->Add(h9);
h3->Add(h10);
h3->Add(h11);
h3->Add(h12);

h3->Draw("AP");
h3->GetXaxis()->SetTitle("pTpT");
h3->GetXaxis()->SetTitleSize(0.06);
h3->GetXaxis()->SetTitleOffset(0.4);
h3->GetXaxis()->SetLabelSize(0.03);
h3->GetXaxis()->SetTitleOffset(0.8);
h3->GetYaxis()->SetTitle("Asymmetry Value");
h3->GetYaxis()->SetTitleSize(0.07);
h3->GetYaxis()->SetTitleOffset(0.6);
h3->GetYaxis()->SetLabelSize(0.03);


TLegend*legend = new TLegend(0.1,0.63,0.5,1);

legend->AddEntry("h2", "Moments Method (Fall 2018)","p");
legend->AddEntry("h4", "Moments Method (Spring 2019)", "p");
legend->AddEntry("h8", "Moments Method (Total)", "p");
legend->AddEntry("h7", "Fit Method (Fall 2018)", "p");
legend->AddEntry("h1", "Fit Method (Spring 2019)", "p");
legend->AddEntry("h9", "Fit Method (Total)", "p");
legend->AddEntry("h10", "Difference Method (Fall 2018)", "p");
legend->AddEntry("h11", "Difference Method (Spring 2019)", "p");
legend->AddEntry("h12", "Difference Method (Total)", "p");

legend->SetBorderSize(7);
legend->Draw();
c03->Update();

c03->Print("FullAsymmetry2PK3.pdf");
c03->Print("FullAsymmetry2PK3.pdf]");



}
