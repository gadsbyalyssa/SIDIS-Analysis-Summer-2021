#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TBrowser.h"
#include "TH2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <TH1F.h>
#include <TMath.h>
#include <fstream>
#include <iostream>

void FitMethodTreeFall(){
Float_t runnum, evnum, helicity,  e_px, e_py, e_pz, e_phi, p1_px, p1_py, p1_pz, p2_px, p2_py, p2_pz, Q2, W, phi2, phi1, Delta_phi, x, y, z, xF, pTpT, pT1, pT2, z1, z2, xF1, xF2, Mx1, Mx2, Mx3, Mx;

FILE *fp = fopen("PKFall2018Skim8.txt","r");
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
TCut pTkT1a = ("0<pTpT&&pTpT<0.1");
TCut pTkT2a = ("0.1<pTpT&&pTpT<0.2");
TCut pTkT3a = ("0.2<pTpT&&pTpT<0.3");
TCut pTkT4a = ("0.3<pTpT&&pTpT<0.4");
TCut pTkT5a = ("0.4<pTpT&&pTpT<0.5");
TCut pTkT6a = ("0.5<pTpT&&pTpT<0.6");
///////////////////////////////////////////////////////////////
TH1F*h26 = new TH1F("h26","h26",20, 0, 6.4);
outTree->Draw("Delta_phi>>h26");
///////////////////////////////////////////////////////////////
TCanvas*c01 = new TCanvas("c01", "PKplus", 1600,1100);
c01->Divide(2,1);
c01->Print("FitMethodTreeBin1.pdf[");
TH1F*h1 = new TH1F("h1","h1",20, 0, 6.4);
c01->cd(1);
h1->GetXaxis()->SetTitle("[0<pTpT<0.1]");
h1->GetXaxis()->SetTitleSize(0.03);
h1->GetXaxis()->SetLabelSize(0.02);
h1->GetXaxis()->SetTitleOffset(1);
h1->GetYaxis()->SetTitle("Counts");
h1->GetYaxis()->SetTitleSize(0.035);
h1->GetYaxis()->SetLabelSize(0.02);
h1->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw("Delta_phi>>h1", PosHeli && pTkT1a && Mxg1);
///////////////////////////////////////////////////////////////
TH1F*h2 = new TH1F("h2","h2",20, 0, 6.4);
c01->cd(2);
h2->GetXaxis()->SetTitle("[0<pTpT<0.1]");
h2->GetXaxis()->SetTitleSize(0.03);
h2->GetXaxis()->SetLabelSize(0.02);
h2->GetXaxis()->SetTitleOffset(1);
h2->GetYaxis()->SetTitle("Counts");
h2->GetYaxis()->SetTitleSize(0.035);
h2->GetYaxis()->SetLabelSize(0.02);
h2->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw("Delta_phi>>h2", NegHeli && pTkT1a && Mxg1);
///////////////////////////////////////////////////////////////
TCanvas*c02 = new TCanvas("c02", "PKplus", 1600,1100);
c02->Divide(2,1);
c02->Print("FitMethodTreeBin2.pdf[");
TH1F*h3 = new TH1F("h3","h3",20, 0, 6.4);
c02->cd(1);
h3->GetXaxis()->SetTitle("[0.1<pTpT<0.2]");
h3->GetXaxis()->SetTitleSize(0.03);
h3->GetXaxis()->SetLabelSize(0.02);
h3->GetXaxis()->SetTitleOffset(1);
h3->GetYaxis()->SetTitle("Counts");
h3->GetYaxis()->SetTitleSize(0.035);
h3->GetYaxis()->SetLabelSize(0.02);
h3->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw("Delta_phi>>h3", PosHeli && pTkT2a && Mxg1);
///////////////////////////////////////////////////////////////
TH1F*h4 = new TH1F("h4","h4",20, 0, 6.4);
c02->cd(2);
h4->GetXaxis()->SetTitle("[0.1<pTpT<0.2]");
h4->GetXaxis()->SetTitleSize(0.03);
h4->GetXaxis()->SetLabelSize(0.02);
h4->GetXaxis()->SetTitleOffset(1);
h4->GetYaxis()->SetTitle("Counts");
h4->GetYaxis()->SetTitleSize(0.035);
h4->GetYaxis()->SetLabelSize(0.02);
h4->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw("Delta_phi>>h4", NegHeli && pTkT2a && Mxg1);
///////////////////////////////////////////////////////////////
TCanvas*c03 = new TCanvas("c03", "PKplus", 1600,1100);
c03->Divide(2,1);
c03->Print("FitMethodTreeBin3.pdf[");
TH1F*h5 = new TH1F("h5","h5",20, 0, 6.4);
c03->cd(1);
h5->GetXaxis()->SetTitle("[0.2<pTpT<0.3]");
h5->GetXaxis()->SetTitleSize(0.03);
h5->GetXaxis()->SetLabelSize(0.02);
h5->GetXaxis()->SetTitleOffset(1);
h5->GetYaxis()->SetTitle("Counts");
h5->GetYaxis()->SetTitleSize(0.035);
h5->GetYaxis()->SetLabelSize(0.02);
h5->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw("Delta_phi>>h5", PosHeli && pTkT3a && Mxg1);
///////////////////////////////////////////////////////////////
TH1F*h6 = new TH1F("h6","h6",20, 0, 6.4);
c03->cd(2);
h6->GetXaxis()->SetTitle("[0.2<pTpT<0.3]");
h6->GetXaxis()->SetTitleSize(0.03);
h6->GetXaxis()->SetLabelSize(0.02);
h6->GetXaxis()->SetTitleOffset(1);
h6->GetYaxis()->SetTitle("Counts");
h6->GetYaxis()->SetTitleSize(0.035);
h6->GetYaxis()->SetLabelSize(0.02);
h6->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw("Delta_phi>>h6", NegHeli && pTkT3a && Mxg1);
///////////////////////////////////////////////////////////////
TCanvas*c04 = new TCanvas("c04", "PKplus", 1600,1100);
c04->Divide(2,1);
c04->Print("FitMethodTreeBin4.pdf[");
TH1F*h7 = new TH1F("h7","h7",20, 0, 6.4);
c04->cd(1);
h7->GetXaxis()->SetTitle("[0.3<pTpT<0.4]");
h7->GetXaxis()->SetTitleSize(0.03);
h7->GetXaxis()->SetLabelSize(0.02);
h7->GetXaxis()->SetTitleOffset(1);
h7->GetYaxis()->SetTitle("Counts");
h7->GetYaxis()->SetTitleSize(0.035);
h7->GetYaxis()->SetLabelSize(0.02);
h7->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw("Delta_phi>>h7", PosHeli && pTkT4a && Mxg1);
///////////////////////////////////////////////////////////////
TH1F*h8 = new TH1F("h8","h8",20, 0, 6.4);
c04->cd(2);
h8->GetXaxis()->SetTitle("[0.3<pTpT<0.4]");
h8->GetXaxis()->SetTitleSize(0.03);
h8->GetXaxis()->SetLabelSize(0.02);
h8->GetXaxis()->SetTitleOffset(1);
h8->GetYaxis()->SetTitle("Counts");
h8->GetYaxis()->SetTitleSize(0.035);
h8->GetYaxis()->SetLabelSize(0.02);
h8->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw("Delta_phi>>h8", NegHeli && pTkT4a && Mxg1);
///////////////////////////////////////////////////////////////
TCanvas*c05 = new TCanvas("c05", "PKplus", 1600,1100);
c05->Divide(2,1);
c05->Print("FitMethodTreeBin5.pdf[");
TH1F*h9 = new TH1F("h9","h9",20, 0, 6.4);
c05->cd(1);
h9->GetXaxis()->SetTitle("[0.4<pTpT<0.5]");
h9->GetXaxis()->SetTitleSize(0.03);
h9->GetXaxis()->SetLabelSize(0.02);
h9->GetXaxis()->SetTitleOffset(1);
h9->GetYaxis()->SetTitle("Counts");
h9->GetYaxis()->SetTitleSize(0.035);
h9->GetYaxis()->SetLabelSize(0.02);
h9->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw("Delta_phi>>h9", PosHeli && pTkT5a && Mxg1);
///////////////////////////////////////////////////////////////
TH1F*h10 = new TH1F("h10","h10",20, 0, 6.4);
c05->cd(2);
h10->GetXaxis()->SetTitle("[0.4<pTpT<0.5]");
h10->GetXaxis()->SetTitleSize(0.03);
h10->GetXaxis()->SetLabelSize(0.02);
h10->GetXaxis()->SetTitleOffset(1);
h10->GetYaxis()->SetTitle("Counts");
h10->GetYaxis()->SetTitleSize(0.035);
h10->GetYaxis()->SetLabelSize(0.02);
h10->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw("Delta_phi>>h10", NegHeli && pTkT5a && Mxg1);
///////////////////////////////////////////////////////////////
TCanvas*c06 = new TCanvas("c06", "PKplus", 1600,1100);
c06->Divide(2,1);
c06->Print("FitMethodTreeBin6.pdf[");
TH1F*h11 = new TH1F("h11","h11",20, 0, 6.4);
c06->cd(1);
h11->GetXaxis()->SetTitle("[0.5<pTpT<0.6]");
h11->GetXaxis()->SetTitleSize(0.03);
h11->GetXaxis()->SetLabelSize(0.02);
h11->GetXaxis()->SetTitleOffset(1);
h11->GetYaxis()->SetTitle("Counts");
h11->GetYaxis()->SetTitleSize(0.035);
h11->GetYaxis()->SetLabelSize(0.02);
h11->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw("Delta_phi>>h11", PosHeli && pTkT6a && Mxg1);
///////////////////////////////////////////////////////////////
TH1F*h12 = new TH1F("h12","h12",20, 0, 6.4);
c06->cd(2);
h12->GetXaxis()->SetTitle("[0.5<pTpT<0.6]");
h12->GetXaxis()->SetTitleSize(0.03);
h12->GetXaxis()->SetLabelSize(0.02);
h12->GetXaxis()->SetTitleOffset(1);
h12->GetYaxis()->SetTitle("Counts");
h12->GetYaxis()->SetTitleSize(0.035);
h12->GetYaxis()->SetLabelSize(0.02);
h12->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw("Delta_phi>>h12", NegHeli && pTkT6a && Mxg1);
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
ofstream outputfile("FitMethodBin6.txt");
int N = h1->GetNbinsX() + 1; 
for(int i=0; i<N; ++i){
outputfile << "\t" << h26->GetBinLowEdge(i)+h26->GetBinWidth(i)/2  << "\t" << h11->GetBinContent(i) << "\t" << h12->GetBinContent(i) << endl; }
outputfile.close();


c01->Print("FitMethodBin1.pdf");
c01->Print("FitMethodBin1.pdf]");
c02->Print("FitMethodBin2.pdf");
c02->Print("FitMethodBin2.pdf]");
c03->Print("FitMethodBin3.pdf");
c03->Print("FitMethodBin3.pdf]");
c04->Print("FitMethodBin4.pdf");
c04->Print("FitMethodBin4.pdf]");
c05->Print("FitMethodBin5.pdf");
c05->Print("FitMethodBin5.pdf]");
c06->Print("FitMethodBin6.pdf");
c06->Print("FitMethodBin6.pdf]");



}





