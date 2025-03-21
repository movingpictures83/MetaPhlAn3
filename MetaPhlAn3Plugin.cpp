#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "MetaPhlAn3Plugin.h"

void MetaPhlAn3Plugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile, std::ios::in);
 std::string sample;
 ifile >> database;
 while (!ifile.eof()){
    getline(ifile, sample);
    std::cout<< "SAMPLE " << sample << std::endl;
    if (sample.length() != 0)
    samples.push_back(std::string(sample));
 }
}

void MetaPhlAn3Plugin::run() {}

void MetaPhlAn3Plugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand;
 for (int i = 0; i < samples.size(); i++) {
	 myCommand = "metaphlan "+samples[i]+"_R1_001.fastq,"+samples[i]+"_R2_001.fastq --index DB --input_type fastq --no_map --ignore_archaea --ignore_eukaryotes  --bowtie2db "+database+"   -o "+outputfile+"/"+samples[i].substr(samples[i].find_last_of('/')+1)+"_all.txt";
//myCommand += "metaphlan2.py " + inputfile + " --input_type fastq > " + outputfile;

 //myCommand += " ";
 std::cout << myCommand << std::endl;
 system(myCommand.c_str());
 }
}

PluginProxy<MetaPhlAn3Plugin> MetaPhlAn3PluginProxy = PluginProxy<MetaPhlAn3Plugin>("MetaPhlAn3", PluginManager::getInstance());
