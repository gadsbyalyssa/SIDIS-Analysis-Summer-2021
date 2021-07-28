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

void MomentsMethodbin3Total(){
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
TString sinposneg("sin(Delta_phi)");
TString sinsquare("pow (sin(Delta_phi),2)");
TString divide("(sin(Delta_phi))/(pow (sin(Delta_phi),2))");
TCut Mxg1 = ("Mx>1");
//TString pT3("pT1*pT2");
/*TCut pTpTx = ("0<pTpT&&pTpT<0.1");

TCut pTpTx = ("0.1<pTpT&&pTpT<0.2");
*/

TCut pTpTx = ("0.2<pTpT&&pTpT<0.3");
/*
TCut pTpTx = ("0.3<pTpT&&pTpT<0.4");
TCut pTpTx = ("0.4<pTpT&&pTpT<0.5");
TCut pTpTx = ("0.5<pTpT&&pTpT<0.6");
TCut pTpTx = ("0.6<pTpT&&pTpT<0.7");
TCut pTpTx = ("0.7<pTpT&&pTpT<0.8");
*/

///////////////////////////////////////////////////////////////
TCanvas*c04 = new TCanvas("c04", "PKplus", 1000,600);
c04->Divide(1,1);
c04->Print("SinPosDP1.pdf[");
TH1F*SinPosDP1 = new TH1F("SinPosDP1","SinPosDP1",1000, -1, 1);
c04->cd(1);
SinPosDP1->GetXaxis()->SetTitle("Sin(deltaphi+)");
SinPosDP1->GetXaxis()->SetTitleSize(0.03);
SinPosDP1->GetXaxis()->SetLabelSize(0.02);
SinPosDP1->GetXaxis()->SetTitleOffset(1);
SinPosDP1->GetYaxis()->SetTitle("Counts");
SinPosDP1->GetYaxis()->SetTitleSize(0.035);
SinPosDP1->GetYaxis()->SetLabelSize(0.02);
SinPosDP1->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw(sinposneg+">>SinPosDP1", PosHeli && pTpTx && Mxg1);
///////////////////////////////////////////////////////////////
TCanvas*c05 = new TCanvas("c05", "PKplus", 1000,600);
c05->Divide(1,1);
c05->Print("SinNegDP1.pdf[");
TH1F*SinNegDP1 = new TH1F("SinNegDP1","SinNegDP1",1000, -1, 1);
c05->cd(1);
SinNegDP1->GetXaxis()->SetTitle("Sin(deltaphi-)");
SinNegDP1->GetXaxis()->SetTitleSize(0.03);
SinNegDP1->GetXaxis()->SetLabelSize(0.02);
SinNegDP1->GetXaxis()->SetTitleOffset(1);
SinNegDP1->GetYaxis()->SetTitle("Counts");
SinNegDP1->GetYaxis()->SetTitleSize(0.035);
SinNegDP1->GetYaxis()->SetLabelSize(0.02);
SinNegDP1->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw(sinposneg+">>SinNegDP1", NegHeli && pTpTx && Mxg1);
///////////////////////////////////////////////////////////////
TCanvas*c06 = new TCanvas("c06", "PKplus", 1000,600);
c06->Divide(1,1);
c06->Print("SinSqrDP1.pdf[");
TH1F*SinSqrDP1 = new TH1F("SinSqrDP1","SinSqrDP1",1000, 0, 1);
c06->cd(1);
SinSqrDP1->GetXaxis()->SetTitle("Sin^{2}(deltaphi)");
SinSqrDP1->GetXaxis()->SetTitleSize(0.03);
SinSqrDP1->GetXaxis()->SetLabelSize(0.02);
SinSqrDP1->GetXaxis()->SetTitleOffset(1);
SinSqrDP1->GetYaxis()->SetTitle("Counts");
SinSqrDP1->GetYaxis()->SetTitleSize(0.035);
SinSqrDP1->GetYaxis()->SetLabelSize(0.02);
SinSqrDP1->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw(sinsquare+">>SinSqrDP1", pTpTx && Mxg1);

ofstream outputfile("MomentsMethodBin3.txt");
int N = SinSqrDP1->GetNbinsX() + 1; 
for(int i=0; i<N; ++i){
outputfile << "\t" << SinPosDP1->GetBinLowEdge(i)+SinPosDP1->GetBinWidth(i)/2  << "\t" << SinPosDP1->GetBinContent(i) << "\t" << SinNegDP1->GetBinLowEdge(i)+SinNegDP1->GetBinWidth(i)/2  << "\t" << SinNegDP1->GetBinContent(i) << "\t" << SinSqrDP1->GetBinLowEdge(i)+SinSqrDP1->GetBinWidth(i)/2  << "\t" << SinSqrDP1->GetBinContent(i) << endl; }
outputfile.close();

/*
c04->Print("SinPosDP1.pdf");
c04->Print("SinPosDP1.pdf]");
c05->Print("SinNegDP1.pdf");
c05->Print("SinNegDP1.pdf]");
c06->Print("SinSqrDP1.pdf");
c06->Print("SinSqrDP1.pdf]");
*/

}





