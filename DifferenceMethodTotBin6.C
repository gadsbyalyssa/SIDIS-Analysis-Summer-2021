#include <vector>
#include <string>
#include <TCanvas.h>
#include <TPad.h>
#include <TNamed.h>
#include <TH1F.h>
#include <TF1.h>
#include <TMath.h>
#include <fstream>
#include <iostream>
#include <cmath>



void DifferenceMethodTotBin6()
{
Float_t runnum, evnum, helicity,  e_px, e_py, e_pz, e_phi, p1_px, p1_py, p1_pz, p2_px, p2_py, p2_pz, Q2, W, phi2, phi1, Delta_phi, x, y, z, xF, pTpT, pT1, pT2, z1, z2, xF1, xF2, Mx1, Mx2, Mx3, Mx;

FILE *fp = fopen("PKTotalSkim8.txt","r");
TFile *hfile = hfile = TFile::Open("PKplus2.root","RECREATE");

TTree *outTree = new TTree("T","kinematics tree");

outTree->Branch("runnum",&runnum,"runnum/F");
outTree->Branch("evnum",&evnum,"evnum/F");
outTree->Branch("helicity", &helicity,"helicity/F");
outTree->Branch("e_px",&e_px,"e_px/F");
outTree->Branch("e_py",&e_py,"e_py/F");
outTree->Branch("e_pz",&e_pz,"e_pz/F");
outTree->Branch("e_phi",&e_phi,"e_phi/F");
outTree->Branch("p1_px",&p1_px,"p1_px/F");
outTree->Branch("p1_py",&p1_py,"p1_py/F");
outTree->Branch("p1_pz",&p1_pz,"p1_pz/F");
outTree->Branch("p2_px",&p2_px,"p2_px/F");
outTree->Branch("p2_py",&p2_py,"p2_py/F");
outTree->Branch("p2_pz",&p2_pz,"p2_pz/F");
outTree->Branch("Q2",&Q2,"Q2/F");
outTree->Branch("W",&W,"W/F");
outTree->Branch("phi2",&phi2,"phi2/F");
outTree->Branch("phi1",&phi1,"phi1/F");
outTree->Branch("Delta_phi",&Delta_phi,"Delta_phi/F");
outTree->Branch("x",&x,"x/F");
outTree->Branch("y",&y,"y/F");
outTree->Branch("z",&z,"y/F");
outTree->Branch("xF",&xF,"xF/F");
outTree->Branch("pTpT",&pTpT,"pTpT/F");
outTree->Branch("pT1",&pT1,"pT1/F");
outTree->Branch("pT2",&pT2,"pT2/F");
outTree->Branch("z1",&z1,"z1/F");
outTree->Branch("z2",&z2,"z2/F");
outTree->Branch("xF1",&xF1,"xF1/F");
outTree->Branch("xF2",&xF2,"xF2/F");
outTree->Branch("Mx1",&Mx1,"Mx1/F");
outTree->Branch("Mx2",&Mx2,"Mx2/F");
outTree->Branch("Mx3",&Mx3,"Mx3/F");
outTree->Branch("Mx",&Mx,"Mx/F");

char line[450];
while (fgets(&line,450,fp) ){ 

fscanf(fp, "%f %f %f %f %f %f %f ", &runnum, &evnum, &helicity, &e_px, &e_py, &e_pz, &e_phi);

fscanf(fp, " %f %f %f %f %f %f %f %f %f ", &p1_px, &p1_py, &p1_pz, &p2_px, &p2_py, &p2_pz, &Q2, &W, &phi2);

fscanf(fp, " %f %f %f %f %f %f %f %f %f ", &phi1, &Delta_phi, &x, &y, &z, &xF, &pTpT, &pT1, &pT2);

fscanf(fp, " %f %f %f %f %f %f %f %f ", &z1, &z2, &xF1, &xF2, &Mx1, &Mx2, &Mx3, &Mx);	

outTree->Fill();

}

//outTree->Print();
outTree->Write();
fclose(fp);
hfile->Write();
///////////////////////////////////////////////////////////////
TCut NegHeli = ("helicity == -1");
TCut PosHeli = ("helicity == 1");
TCut Mxg1 = ("Mx>1");
TCut pTkT1 = ("0<pTpT&&pTpT<0.1");
TCut pTkT2 = ("0.1<pTpT&&pTpT<0.2");
TCut pTkT3 = ("0.2<pTpT&&pTpT<0.3");
TCut pTkT4 = ("0.3<pTpT&&pTpT<0.4");
TCut pTkT5 = ("0.4<pTpT&&pTpT<0.5");
TCut pTkT6 = ("0.5<pTpT&&pTpT<0.6");
TCut pTkT7 = ("0.6<pTpT&&pTpT<0.7");
TCut pTkT8 = ("0.7<pTpT&&pTpT<0.8");
TCut zp = ("0<Delta_phi&&Delta_phi<3.14159");
TCut p2 = ("3.14159<Delta_phi&&Delta_phi<6.28318");
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
TCanvas*c01 = new TCanvas("c01", "PKplus", 1600,1100);
c01->Divide(2,2);
c01->Print("DifferenceMethodBin6.pdf[");
TH1F*h1 = new TH1F("h1","h1",100, 0, 4);
c01->cd(1);
h1->GetXaxis()->SetTitle("[0.5<pTpT<0.6]");
h1->GetXaxis()->SetTitleSize(0.03);
h1->GetXaxis()->SetLabelSize(0.02);
h1->GetXaxis()->SetTitleOffset(1);
h1->GetYaxis()->SetTitle("Counts");
h1->GetYaxis()->SetTitleSize(0.035);
h1->GetYaxis()->SetLabelSize(0.02);
h1->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw("Delta_phi>>h1", PosHeli && pTkT6 && Mxg1 && zp);
TH1F*h2 = new TH1F("h2","h2",100, 0, 7);
c01->cd(2);
h2->GetXaxis()->SetTitle("[0.5<pTpT<0.6]");
h2->GetXaxis()->SetTitleSize(0.03);
h2->GetXaxis()->SetLabelSize(0.02);
h2->GetXaxis()->SetTitleOffset(1);
h2->GetYaxis()->SetTitle("Counts");
h2->GetYaxis()->SetTitleSize(0.035);
h2->GetYaxis()->SetLabelSize(0.02);
h2->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw("Delta_phi>>h2", PosHeli && pTkT6 && Mxg1 && p2);
TH1F*h3 = new TH1F("h3","h3",100, 0, 4);
c01->cd(3);
h3->GetXaxis()->SetTitle("[0.5<pTpT<0.6]");
h3->GetXaxis()->SetTitleSize(0.03);
h3->GetXaxis()->SetLabelSize(0.02);
h3->GetXaxis()->SetTitleOffset(1);
h3->GetYaxis()->SetTitle("Counts");
h3->GetYaxis()->SetTitleSize(0.035);
h3->GetYaxis()->SetLabelSize(0.02);
h3->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw("Delta_phi>>h3", NegHeli && pTkT6 && Mxg1 && zp);
TH1F*h4 = new TH1F("h4","h4",100, 0, 7);
c01->cd(4);
h4->GetXaxis()->SetTitle("[0.5<pTpT<0.6]");
h4->GetXaxis()->SetTitleSize(0.03);
h4->GetXaxis()->SetLabelSize(0.02);
h4->GetXaxis()->SetTitleOffset(1);
h4->GetYaxis()->SetTitle("Counts");
h4->GetYaxis()->SetTitleSize(0.035);
h4->GetYaxis()->SetLabelSize(0.02);
h4->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw("Delta_phi>>h4", NegHeli && pTkT6 && Mxg1 && p2);

h1->Print("all");
h2->Print("all");
h3->Print("all");
h4->Print("all");

c01->Print("DifferenceMethodBin6.pdf");
c01->Print("DifferenceMethodBin6.pdf]");


}
