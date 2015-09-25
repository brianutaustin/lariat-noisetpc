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
