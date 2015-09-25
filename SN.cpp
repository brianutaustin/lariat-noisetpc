
/*
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <typeinfo>

#include "TWC.h"

#include "TFile.h"
#include "TH1.h"
#include "TF1.h"
#include "TCanvas.h"
#include "Riostream.h"
*/

#include "SN.h"

/*
int main(int argc, char* argv[]) {


	std::string list = argv[1];
	int wireid = atoi(argv[2]);
	std::string opt = argv[3];
	std::string opttoken[4];
	size_t pos = 0;
	int count = 0;
	while ((pos = opt.find(":")) != std::string::npos) {
   	opttoken[count] = opt.substr(0, pos);
   	opt.erase(0, pos + 1);
		count++;
	}
	opttoken[count] = opt;

	WireAnalysis* NoiseWireAnalysis = new WireAnalysis(list.c_str(), wireid);

	if (opttoken[0] == "--quality") {
		std::cout << "Plotting the quality monitor plot for the wire number " << wireid << "..." << std::endl;
		NoiseWireAnalysis->PlotWireVsRun();
	} else if (opttoken[0] == "--waveform") {
		std::cout << "Plotting waveform for wire " << wireid << " in run " << opttoken[1] << ", spill " << opttoken[2] << ", event " << opttoken[3] << "..." << std::endl;
		NoiseWireAnalysis->PlotWaveform(atoi(opttoken[1].c_str()), atoi(opttoken[2].c_str()), atoi(opttoken[3].c_str()));
	}

	return 0;
}
*/

int main() {
/*
	for (int i = 320; i < 481; i++) {
		WireAnalysis* NoiseWireAnalysis = new WireAnalysis("./list.txt", i);
	//	NoiseWireAnalysis->PlotWireVsRun();
		NoiseWireAnalysis->MakeWireHistogram();
	}
*/
	WireAnalysis* NoiseWireAnalysis = new WireAnalysis("./list.txt", i);
	NoiseWireAnalysis->MakeWireHistogram();

	return 0;
}
