/*
#include <cstdio>
#include <cstdlib>
#include <string>
*/

#include <iostream>
#include <cmath>
#include <sstream>
#include <cstring>
#include <vector>
#include <typeinfo>
#include <numeric>

#include "TWC.h"

#include "TFile.h"
#include "TH1.h"
#include "TF1.h"
#include "TCanvas.h"
#include "Riostream.h"
#include "TGraph.h"

/********************************************************************************************
Define new Data structure
********************************************************************************************/

struct struct_DqmInput {
	std::string 	DQMFileName;
	int 				EventNumber;
	int 				RunNumber;
	int 				SpillNumber;
};

struct struct_WaveformSampling {
	std::vector<int> 	SamplingVector;
	int 					RunNumber;
	int 					SpillNumber;
	int 					EventNumber;
};

class WireAnalysis {
public:
	WireAnalysis(std::string, int);
	~WireAnalysis();
	void PlotWireVsRun();
	void PlotWaveform();
	void PlotWaveform(int, int, int);
	void MakeWireHistogram();

	int												fWireID;
	std::string										fList;
	std::string										fWireName;
	std::vector<struct_DqmInput>				fDQMInput;
	std::vector<struct_WaveformSampling> 	fWaveformSampling;

private:
	void DQMImport();
	void WaveformSampling();
	void GetWireName();
};

/********************************************************************************************
Define Important Functions in the class
********************************************************************************************/

WireAnalysis::WireAnalysis(std::string ListTXT, int WireID) {
	/*	CLASS CONSTRUCTOR
			ListTXT: 	The path to a text file containing the names of the dqm files (data) used for the analysis.
			WireID: 		The number that identify the wire to be analyzed. The WireID is then store in data member fWireID.
							*ID 1-240: 		Induction wires.
							*ID 241-480:		Collection wires.

	*/
	fList 					= ListTXT;
	fWireID					= WireID;
	this->GetWireName();
	this->DQMImport();
	this->WaveformSampling();
}

WireAnalysis::~WireAnalysis() {}

void WireAnalysis::GetWireName() {
	std::stringstream str_stream;
	if (fWireID > 240) {
		str_stream << fWireID - 240;
		fWireName = "Collection_" + str_stream.str();
	} else {
		str_stream << fWireID;
		fWireName = "Induction_" + str_stream.str();
	}
}

void WireAnalysis::DQMImport() {
	/*	DQMImport
			This method making a structure containing a detailed list of data that will be used. Data are organized in files,
			each with a scpecific RUN number and SPILL number and will likely to contain several EVENTS (or triggers). So,
			this method will extract these information and allow users to specify exactly the events they want to use for
			their analysis.

			To specify the events, users need to create a text file, the so-called LIST. The LIST will need to have 2 columns.
			The first column is the name of DQM files, the second column is the event number contained in the corresponding
			DQM file. Example for the LIST:

					#	LIST.TXT

					./data/dqm_run_006000_spill_0001.root    0
					./data/dqm_run_006001_spill_0001.root    1
					./data/dqm_run_006002_spill_0001.root    0
					./data/dqm_run_006003_spill_0001.root    0
					./data/dqm_run_006005_spill_0001.root    0
					./data/dqm_run_006006_spill_0001.root    0
					./data/dqm_run_006007_spill_0001.root    1
					./data/dqm_run_006008_spill_0001.root    0
					./data/dqm_run_006009_spill_0001.root    0
					./data/dqm_run_006010_spill_0001.root    0
					./data/dqm_run_006011_spill_0001.root    0
					./data/dqm_run_006012_spill_0001.root    0
					./data/dqm_run_006013_spill_0001.root    0
					./data/dqm_run_006014_spill_0001.root    0
					./data/dqm_run_006015_spill_0001.root    0
					./data/dqm_run_006016_spill_0001.root    0
					./data/dqm_run_006017_spill_0001.root    3
					./data/dqm_run_006018_spill_0001.root    0
					./data/dqm_run_006019_spill_0001.root    0
					./data/dqm_run_006020_spill_0001.root    0
					./data/dqm_run_006021_spill_0001.root    0
					./data/dqm_run_006022_spill_0001.root    0
	*/
	std::ifstream list;
	list.open(fList.c_str());

	struct_DqmInput 	dummystruct;
	std::string 				str_dummy;
	int					i_dummy;
	unsigned int countfile(0);

	while (1) {
		list >> str_dummy >> i_dummy;
		if (!list.good()) break;

		// Parsing info from the DQM file name
		dummystruct.RunNumber = atoi(str_dummy.substr(4 + str_dummy.find("run_"), 6).c_str());
		dummystruct.SpillNumber = atoi(str_dummy.substr(6 + str_dummy.find("spill_"), 4).c_str());
		dummystruct.DQMFileName = str_dummy;
		dummystruct.EventNumber = i_dummy;

		fDQMInput.push_back(dummystruct);
		countfile++;
	}
	std::cout << "Processed " << countfile << " DQM files." << std::endl;
	list.close();
}

void WireAnalysis::WaveformSampling() {
	/*	WaveformSampling
			This method creates a structure to store the the waveform of the wire specified by fWireID. This waveform
			will be a vector of integers. Each waveform is also associated with its corresponding RUN number, SPILL
			number and EVENT number. All these information is wrapped in data member fWaveformSampling.

			For most of analysis, uers will only need to use the data member fWaveformSampling.
	*/
	std::vector<int> SelectedWire;
	struct_WaveformSampling dummystruct;
	for (int k = 0; k < fDQMInput.size(); k++) {
		TWC* TWChannel = new TWC(fDQMInput.at(k).DQMFileName, fDQMInput.at(k).EventNumber, fWireID);
		SelectedWire.clear();
		SelectedWire = TWChannel->Loop();

		dummystruct.SamplingVector = SelectedWire;
		dummystruct.RunNumber		= fDQMInput.at(k).RunNumber;
		dummystruct.SpillNumber		= fDQMInput.at(k).SpillNumber;
		dummystruct.EventNumber		= fDQMInput.at(k).EventNumber;
		fWaveformSampling.push_back(dummystruct);
	}
}


/********************************************************************************************
Define Analysis Utilities in the class
********************************************************************************************/

// Making Quality Plot
void WireAnalysis::PlotWireVsRun() {
	TCanvas* canvas = new TCanvas();
	int N = fWaveformSampling.size();
	float WaveformSamplingMean[N];
	float RunNumberForMean[N];

	float Mean = 0;
	int Ngood = 0;
	for (int i = 0; i < N; i++) {
		Mean = accumulate(fWaveformSampling.at(i).SamplingVector.begin(), fWaveformSampling.at(i).SamplingVector.end(), 0.0)/3072;
		if (Mean != 0) {
			WaveformSamplingMean[Ngood] = Mean;
			RunNumberForMean[Ngood] = (float) fWaveformSampling.at(i).RunNumber;
			Ngood++;
		}
	}

	TGraph* graph = new TGraph(Ngood, RunNumberForMean, WaveformSamplingMean);
	graph->Draw("AP*");
	std::string str_dummy = "Noise Pedestal for " + fWireName;
	graph->SetTitle(str_dummy.c_str());
	graph->GetXaxis()->SetTitle("Run Number");
	graph->GetXaxis()->CenterTitle();
	graph->GetYaxis()->SetTitle("ADC Count");
	graph->GetYaxis()->CenterTitle();
	graph->GetYaxis()->SetTitleOffset(1.3);
	canvas->SetGrid();
	str_dummy = "NoisePedestalvsRun_" + fWireName + ".eps";
	canvas->SaveAs(str_dummy.c_str());
}

// Plot Waveform
void WireAnalysis::PlotWaveform(int RunNumber, int SpillNumber, int EventNumber) {
	TCanvas* canvas = new TCanvas();

	std::stringstream str_stream_run;
	str_stream_run << RunNumber;
	std::string str_RunNumber = str_stream_run.str();

	std::stringstream str_stream_spill;
	str_stream_spill << SpillNumber;
	std::string str_SpillNumber = str_stream_spill.str();

	std::stringstream str_stream_event;
	str_stream_event << EventNumber;
	std::string str_EventNumber = str_stream_event.str();

	int TimeSlice[3072];
	for (int i = 0; i < 3072; i++) {
		TimeSlice[i] = i;
	}

	int SamplingValue[3072];
	int N = fWaveformSampling.size();
	for (int i = 0; i < N; i++) {
		if (fWaveformSampling.at(i).RunNumber == RunNumber) {
			if (fWaveformSampling.at(i).RunNumber == RunNumber) {
				if (fWaveformSampling.at(i).RunNumber == RunNumber) {
					for (int j = 0; j < 3072; j++) {
						SamplingValue[j] = fWaveformSampling.at(i).SamplingVector.at(j);
					}
					i = N;
				}
			}
		}
	}

	TGraph* graph = new TGraph(3072, TimeSlice, SamplingValue);
	graph->Draw();
	graph->GetXaxis()->SetRangeUser(0, 3072);
	graph->GetXaxis()->SetTitle("Sample number");
	graph->GetXaxis()->CenterTitle();
	graph->GetYaxis()->SetTitle("ADC Count");
	graph->GetYaxis()->SetTitleOffset(1.3);
	graph->GetYaxis()->CenterTitle();
	std::string str_dummy = "Waveform for " + fWireName + " Run " + str_RunNumber + " Spill " + str_SpillNumber + " Event " + str_EventNumber;
	graph->SetTitle(str_dummy.c_str());
	str_dummy = fWireName + "_Run_" + str_RunNumber + "_Spill_" + str_SpillNumber + "_Event_" + str_EventNumber + ".eps";
	canvas->SaveAs(str_dummy.c_str());

	str_dummy = "Histogram for " + fWireName + " Run " + str_RunNumber + " Spill " + str_SpillNumber + " Event " + str_EventNumber;
	TH1D* hWire = new TH1D("hWire", str_dummy.c_str(), 200, 2000, 2200);
	for (int i = 0; i < 3072; i++) {
		hWire->Fill(SamplingValue[i]);
	}
	hWire->GetXaxis()->SetTitle("ADC");
	hWire->GetXaxis()->CenterTitle();
	hWire->GetYaxis()->CenterTitle();
	hWire->GetYaxis()->SetTitle("Counts");
	hWire->GetYaxis()->SetTitleOffset(1.3);
	hWire->Draw();
	str_dummy = "Hist_" + fWireName + "_Run_" + str_RunNumber + "_Spill_" + str_SpillNumber + "_Event_" + str_EventNumber + ".eps";
	canvas->SaveAs(str_dummy.c_str());
}

void WireAnalysis::MakeWireHistogram() {
	std::string str_dummy = "Histogram of " + fWireName + " over empty events.";
	TH1D* hWireOverRuns = new TH1D("hWireOverRuns", str_dummy.c_str(), 200, 2000, 2200);
	TCanvas* canvas = new TCanvas();
	for (int i = 1; i < fWaveformSampling.size(); i++) {
		for (int j = 0; j < 3072; j++) {
			hWireOverRuns->Fill(fWaveformSampling.at(i).SamplingVector.at(j));
		}
	}
	hWireOverRuns->SetTitle(str_dummy.c_str());
	hWireOverRuns->GetXaxis()->SetTitle("ADC");
	hWireOverRuns->GetYaxis()->SetTitle("Counts");
	hWireOverRuns->GetXaxis()->CenterTitle();
	hWireOverRuns->GetYaxis()->CenterTitle();
	hWireOverRuns->GetYaxis()->SetTitleOffset(1.3);
	hWireOverRuns->Draw();
	str_dummy = str_dummy + ".eps";
	canvas->SaveAs(str_dummy.c_str());
}
