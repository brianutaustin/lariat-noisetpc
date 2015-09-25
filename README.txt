A. How to compile the code?
    - Run "thisroot.sh" from the $ROOTSYS/bin to setup the environment variables for ROOT.
    - Run "make" in the code directory to compile.

B. How to run the code?
    - Download the DQM files that you want to analyze to a local directory.
      (Here I put them in ./data)
    - Then using bash script (or typing by hand if you want) to make a text file
      that contain the list of the DQM files. The content of the list should look like this

      ./data/dqm_run_006000_spill_0001.root    0
      ./data/dqm_run_006001_spill_0001.root    1
      ./data/dqm_run_006002_spill_0001.root    0
      ./data/dqm_run_006003_spill_0001.root    0
      ./data/dqm_run_006005_spill_0001.root    0
      ./data/dqm_run_006006_spill_0001.root    0
      ./data/dqm_run_006007_spill_0001.root    1
      ./data/dqm_run_006008_spill_0001.root    0

      The first column is the file name, the second column is the event number
      of the events that we are interested in in a DQM. Because a DQM file contains
      many events but we (in this analysis) care only about the empty events.

      This means that after downloading the DQM files, you should open it with
      event viewer (Johny can help with how to install event viewer on local computer,
      if he's busy, I can help you on this.)

      - Remember to change the location of the list in the "SN.cpp", line 56.

C. Make changes to the code
    - So, everything that you want to change should be in "SN.h". The class
      WireAnalysis contains data structures and functions to analyze an individual
      wire.

      It's kind of dumb design in overall, but the idea is that if I don't want to
      analyze the whole 480 wires in the TPC, I just need to change a line of code
      in the "SN.cpp".

    - The function "MakeWireHistogram" creates the histogram of charge collect on
      a wire in all the event in the list. Because the list we consider here only
      contains empty events, the histogram contains just pedestal. So if your look
      at the histogram and see two peaks, that means we've seen a pedestal drift of
      the TPC wire.

    - The function "PlotWireVsRun" creates the plot that you suggested to me: to see
      at which runs number the drift in the pedestal happened.

D. Example Data
    - I already create the ./data folder and the list file. You can try to run the
      code now.

    - I commented out the lines from 54-60 in "SN.cpp" and added two line under it.
      This means, now, I analyze only the wire number 13, which is the Induction wire
      number 13. Then I make the histogram for that wire.

    - The data list now contains only one empty event, so there will be no other peak.
      You can add more data.


ENJOY IT! I will try to make it more elaborated next time.
