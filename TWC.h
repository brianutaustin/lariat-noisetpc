#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TH2.h"
#include "TH1.h"
#include "TStyle.h"
#include "TCanvas.h"

#include <string>
#include <cstring>
#include <vector>

class TWC {
public :
   // Controlling variables
   std::vector<int> 	SelectedWire;					// Containing the sampling values of WireID
   int             	EventNumber;					// Event number in a spill (DQM)
   std::string     	DataFileName;					// Name of the spill (DQM)
   int             	WireID;							// Wire number in consideration

   TTree          *fChain;   									//!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; 									//!current Tree number in a TChain

   // Declaration of leaf types
   UInt_t          run;
   UInt_t          spill;
   UInt_t          fragment;
   UInt_t          event_counter;
   UInt_t          board_id;
   UInt_t          trigger_time_tag;
   UShort_t        channel_0[3072];
   UShort_t        channel_1[3072];
   UShort_t        channel_2[3072];
   UShort_t        channel_3[3072];
   UShort_t        channel_4[3072];
   UShort_t        channel_5[3072];
   UShort_t        channel_6[3072];
   UShort_t        channel_7[3072];
   UShort_t        channel_8[3072];
   UShort_t        channel_9[3072];
   UShort_t        channel_10[3072];
   UShort_t        channel_11[3072];
   UShort_t        channel_12[3072];
   UShort_t        channel_13[3072];
   UShort_t        channel_14[3072];
   UShort_t        channel_15[3072];
   UShort_t        channel_16[3072];
   UShort_t        channel_17[3072];
   UShort_t        channel_18[3072];
   UShort_t        channel_19[3072];
   UShort_t        channel_20[3072];
   UShort_t        channel_21[3072];
   UShort_t        channel_22[3072];
   UShort_t        channel_23[3072];
   UShort_t        channel_24[3072];
   UShort_t        channel_25[3072];
   UShort_t        channel_26[3072];
   UShort_t        channel_27[3072];
   UShort_t        channel_28[3072];
   UShort_t        channel_29[3072];
   UShort_t        channel_30[3072];
   UShort_t        channel_31[3072];
   UShort_t        channel_32[3072];
   UShort_t        channel_33[3072];
   UShort_t        channel_34[3072];
   UShort_t        channel_35[3072];
   UShort_t        channel_36[3072];
   UShort_t        channel_37[3072];
   UShort_t        channel_38[3072];
   UShort_t        channel_39[3072];
   UShort_t        channel_40[3072];
   UShort_t        channel_41[3072];
   UShort_t        channel_42[3072];
   UShort_t        channel_43[3072];
   UShort_t        channel_44[3072];
   UShort_t        channel_45[3072];
   UShort_t        channel_46[3072];
   UShort_t        channel_47[3072];
   UShort_t        channel_48[3072];
   UShort_t        channel_49[3072];
   UShort_t        channel_50[3072];
   UShort_t        channel_51[3072];
   UShort_t        channel_52[3072];
   UShort_t        channel_53[3072];
   UShort_t        channel_54[3072];
   UShort_t        channel_55[3072];
   UShort_t        channel_56[3072];
   UShort_t        channel_57[3072];
   UShort_t        channel_58[3072];
   UShort_t        channel_59[3072];
   UShort_t        channel_60[3072];
   UShort_t        channel_61[3072];
   UShort_t        channel_62[3072];
   UShort_t        channel_63[3072];

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_spill;   //!
   TBranch        *b_fragment;   //!
   TBranch        *b_event_counter;   //!
   TBranch        *b_board_id;   //!
   TBranch        *b_trigger_time_tag;   //!
   TBranch        *b_channel_0;   //!
   TBranch        *b_channel_1;   //!
   TBranch        *b_channel_2;   //!
   TBranch        *b_channel_3;   //!
   TBranch        *b_channel_4;   //!
   TBranch        *b_channel_5;   //!
   TBranch        *b_channel_6;   //!
   TBranch        *b_channel_7;   //!
   TBranch        *b_channel_8;   //!
   TBranch        *b_channel_9;   //!
   TBranch        *b_channel_10;   //!
   TBranch        *b_channel_11;   //!
   TBranch        *b_channel_12;   //!
   TBranch        *b_channel_13;   //!
   TBranch        *b_channel_14;   //!
   TBranch        *b_channel_15;   //!
   TBranch        *b_channel_16;   //!
   TBranch        *b_channel_17;   //!
   TBranch        *b_channel_18;   //!
   TBranch        *b_channel_19;   //!
   TBranch        *b_channel_20;   //!
   TBranch        *b_channel_21;   //!
   TBranch        *b_channel_22;   //!
   TBranch        *b_channel_23;   //!
   TBranch        *b_channel_24;   //!
   TBranch        *b_channel_25;   //!
   TBranch        *b_channel_26;   //!
   TBranch        *b_channel_27;   //!
   TBranch        *b_channel_28;   //!
   TBranch        *b_channel_29;   //!
   TBranch        *b_channel_30;   //!
   TBranch        *b_channel_31;   //!
   TBranch        *b_channel_32;   //!
   TBranch        *b_channel_33;   //!
   TBranch        *b_channel_34;   //!
   TBranch        *b_channel_35;   //!
   TBranch        *b_channel_36;   //!
   TBranch        *b_channel_37;   //!
   TBranch        *b_channel_38;   //!
   TBranch        *b_channel_39;   //!
   TBranch        *b_channel_40;   //!
   TBranch        *b_channel_41;   //!
   TBranch        *b_channel_42;   //!
   TBranch        *b_channel_43;   //!
   TBranch        *b_channel_44;   //!
   TBranch        *b_channel_45;   //!
   TBranch        *b_channel_46;   //!
   TBranch        *b_channel_47;   //!
   TBranch        *b_channel_48;   //!
   TBranch        *b_channel_49;   //!
   TBranch        *b_channel_50;   //!
   TBranch        *b_channel_51;   //!
   TBranch        *b_channel_52;   //!
   TBranch        *b_channel_53;   //!
   TBranch        *b_channel_54;   //!
   TBranch        *b_channel_55;   //!
   TBranch        *b_channel_56;   //!
   TBranch        *b_channel_57;   //!
   TBranch        *b_channel_58;   //!
   TBranch        *b_channel_59;   //!
   TBranch        *b_channel_60;   //!
   TBranch        *b_channel_61;   //!
   TBranch        *b_channel_62;   //!
   TBranch        *b_channel_63;   //!

	// Methods
   TWC(std::string, int, int);
   virtual 							~TWC();
	virtual void     				Init(TTree *tree);
	virtual Long64_t 				LoadTree(Long64_t entry);
   virtual Int_t    				GetEntry(Long64_t entry);
   virtual std::vector<int> 	Loop();
};

TWC::TWC(std::string ndfn, int nevn, int nwid) : fChain(0) {

	TTree* tree = new TTree();

	EventNumber = nevn;
	DataFileName = ndfn;
	WireID = nwid;

	TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(ndfn.c_str());
   if (!f || !f->IsOpen()) {           // If opening, don't try open anymore!
		f = new TFile(ndfn.c_str());
   }

	std::string str_dummy = ndfn + ":/DataQuality";
	TDirectory * dir = (TDirectory*)f->Get(str_dummy.c_str());
	dir->GetObject("v1740", tree);

	Init(tree);
}

TWC::~TWC() {
   delete fChain->GetCurrentFile();
}

void TWC::Init(TTree *tree) {

   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("spill", &spill, &b_spill);
   fChain->SetBranchAddress("fragment", &fragment, &b_fragment);
   fChain->SetBranchAddress("event_counter", &event_counter, &b_event_counter);
   fChain->SetBranchAddress("board_id", &board_id, &b_board_id);
   fChain->SetBranchAddress("trigger_time_tag", &trigger_time_tag, &b_trigger_time_tag);
   fChain->SetBranchAddress("channel_0", channel_0, &b_channel_0);
   fChain->SetBranchAddress("channel_1", channel_1, &b_channel_1);
   fChain->SetBranchAddress("channel_2", channel_2, &b_channel_2);
   fChain->SetBranchAddress("channel_3", channel_3, &b_channel_3);
   fChain->SetBranchAddress("channel_4", channel_4, &b_channel_4);
   fChain->SetBranchAddress("channel_5", channel_5, &b_channel_5);
   fChain->SetBranchAddress("channel_6", channel_6, &b_channel_6);
   fChain->SetBranchAddress("channel_7", channel_7, &b_channel_7);
   fChain->SetBranchAddress("channel_8", channel_8, &b_channel_8);
   fChain->SetBranchAddress("channel_9", channel_9, &b_channel_9);
   fChain->SetBranchAddress("channel_10", channel_10, &b_channel_10);
   fChain->SetBranchAddress("channel_11", channel_11, &b_channel_11);
   fChain->SetBranchAddress("channel_12", channel_12, &b_channel_12);
   fChain->SetBranchAddress("channel_13", channel_13, &b_channel_13);
   fChain->SetBranchAddress("channel_14", channel_14, &b_channel_14);
   fChain->SetBranchAddress("channel_15", channel_15, &b_channel_15);
   fChain->SetBranchAddress("channel_16", channel_16, &b_channel_16);
   fChain->SetBranchAddress("channel_17", channel_17, &b_channel_17);
   fChain->SetBranchAddress("channel_18", channel_18, &b_channel_18);
   fChain->SetBranchAddress("channel_19", channel_19, &b_channel_19);
   fChain->SetBranchAddress("channel_20", channel_20, &b_channel_20);
   fChain->SetBranchAddress("channel_21", channel_21, &b_channel_21);
   fChain->SetBranchAddress("channel_22", channel_22, &b_channel_22);
   fChain->SetBranchAddress("channel_23", channel_23, &b_channel_23);
   fChain->SetBranchAddress("channel_24", channel_24, &b_channel_24);
   fChain->SetBranchAddress("channel_25", channel_25, &b_channel_25);
   fChain->SetBranchAddress("channel_26", channel_26, &b_channel_26);
   fChain->SetBranchAddress("channel_27", channel_27, &b_channel_27);
   fChain->SetBranchAddress("channel_28", channel_28, &b_channel_28);
   fChain->SetBranchAddress("channel_29", channel_29, &b_channel_29);
   fChain->SetBranchAddress("channel_30", channel_30, &b_channel_30);
   fChain->SetBranchAddress("channel_31", channel_31, &b_channel_31);
   fChain->SetBranchAddress("channel_32", channel_32, &b_channel_32);
   fChain->SetBranchAddress("channel_33", channel_33, &b_channel_33);
   fChain->SetBranchAddress("channel_34", channel_34, &b_channel_34);
   fChain->SetBranchAddress("channel_35", channel_35, &b_channel_35);
   fChain->SetBranchAddress("channel_36", channel_36, &b_channel_36);
   fChain->SetBranchAddress("channel_37", channel_37, &b_channel_37);
   fChain->SetBranchAddress("channel_38", channel_38, &b_channel_38);
   fChain->SetBranchAddress("channel_39", channel_39, &b_channel_39);
   fChain->SetBranchAddress("channel_40", channel_40, &b_channel_40);
   fChain->SetBranchAddress("channel_41", channel_41, &b_channel_41);
   fChain->SetBranchAddress("channel_42", channel_42, &b_channel_42);
   fChain->SetBranchAddress("channel_43", channel_43, &b_channel_43);
   fChain->SetBranchAddress("channel_44", channel_44, &b_channel_44);
   fChain->SetBranchAddress("channel_45", channel_45, &b_channel_45);
   fChain->SetBranchAddress("channel_46", channel_46, &b_channel_46);
   fChain->SetBranchAddress("channel_47", channel_47, &b_channel_47);
   fChain->SetBranchAddress("channel_48", channel_48, &b_channel_48);
   fChain->SetBranchAddress("channel_49", channel_49, &b_channel_49);
   fChain->SetBranchAddress("channel_50", channel_50, &b_channel_50);
   fChain->SetBranchAddress("channel_51", channel_51, &b_channel_51);
   fChain->SetBranchAddress("channel_52", channel_52, &b_channel_52);
   fChain->SetBranchAddress("channel_53", channel_53, &b_channel_53);
   fChain->SetBranchAddress("channel_54", channel_54, &b_channel_54);
   fChain->SetBranchAddress("channel_55", channel_55, &b_channel_55);
   fChain->SetBranchAddress("channel_56", channel_56, &b_channel_56);
   fChain->SetBranchAddress("channel_57", channel_57, &b_channel_57);
   fChain->SetBranchAddress("channel_58", channel_58, &b_channel_58);
   fChain->SetBranchAddress("channel_59", channel_59, &b_channel_59);
   fChain->SetBranchAddress("channel_60", channel_60, &b_channel_60);
   fChain->SetBranchAddress("channel_61", channel_61, &b_channel_61);
   fChain->SetBranchAddress("channel_62", channel_62, &b_channel_62);
   fChain->SetBranchAddress("channel_63", channel_63, &b_channel_63);
}

Long64_t TWC::LoadTree(Long64_t entry) {
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
   }

   return centry;
}

Int_t TWC::GetEntry(Long64_t entry) { return fChain->GetEntry(entry); }

std::vector<int> TWC::Loop() {

   // Set-up code HERE
	SelectedWire.clear();
	int BoardID = (WireID/64);
	int ChannelID = WireID - BoardID*64 - 1;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

		// Loop code HERE
		UShort_t dummyChannel[3072];
      if ((event_counter == EventNumber) && (board_id == BoardID)) {
			switch (ChannelID) {
				case 0: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_0[j];} break; };
				case 1: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_1[j];} break;};
				case 2: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_2[j];} break;};
				case 3: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_3[j];} break;};
				case 4: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_4[j];} break;};
				case 5: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_5[j];} break;};
				case 6: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_6[j];} break;};
				case 7: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_7[j];} break;};
				case 8: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_8[j];} break;};
				case 9: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_9[j];} break;};
				case 10: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_10[j];} break;};
				case 11: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_11[j];} break;};
				case 12: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_12[j];} break;};
				case 13: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_13[j];} break;};
				case 14: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_14[j];} break;};
				case 15: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_15[j];} break;};
				case 16: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_16[j];} break;};
				case 17: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_17[j];} break;};
				case 18: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_18[j];} break;};
				case 19: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_19[j];} break;};
				case 20: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_20[j];} break;};
				case 21: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_21[j];} break;};
				case 22: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_22[j];} break;};
				case 23: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_23[j];} break;};
				case 24: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_24[j];} break;};
				case 25: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_25[j];} break;};
				case 26: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_26[j];} break;};
				case 27: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_27[j];} break;};
				case 28: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_28[j];} break;};
				case 29: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_29[j];} break;};
				case 30: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_30[j];} break;};
				case 31: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_31[j];} break;};
				case 32: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_32[j];} break;};
				case 33: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_33[j];} break;};
				case 34: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_34[j];} break;};
				case 35: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_35[j];} break;};
				case 36: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_36[j];} break;};
				case 37: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_37[j];} break;};
				case 38: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_38[j];} break;};
				case 39: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_39[j];} break;};
				case 40: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_40[j];} break;};
				case 41: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_41[j];} break;};
				case 42: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_42[j];} break;};
				case 43: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_43[j];} break;};
				case 44: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_44[j];} break;};
				case 45: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_45[j];} break;};
				case 46: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_46[j];} break;};
				case 47: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_47[j];} break;};
				case 48: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_48[j];} break;};
				case 49: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_49[j];} break;};
				case 50: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_50[j];} break;};
				case 51: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_51[j];} break;};
				case 52: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_52[j];} break;};
				case 53: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_53[j];} break;};
				case 54: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_54[j];} break;};
				case 55: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_55[j];} break;};
				case 56: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_56[j];} break;};
				case 57: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_57[j];} break;};
				case 58: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_58[j];} break;};
				case 59: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_59[j];} break;};
				case 60: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_60[j];} break;};
				case 61: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_61[j];} break;};
				case 62: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_62[j];} break;};
				case 63: {for (int j = 0; j < 3072; j++) {dummyChannel[j] = channel_63[j];} break;};
			}
         for (int i = 0; i < (sizeof(dummyChannel)/sizeof(*dummyChannel)); i++) {
				SelectedWire.push_back(dummyChannel[i]);
         }
      }

   }
   // Wrap-up code HERE

   return SelectedWire;
}
