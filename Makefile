all: 
	g++ -o NoiseTPC ./SN.cpp `root-config --cflags` `root-config --glibs`
