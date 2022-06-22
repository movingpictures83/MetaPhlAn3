#ifndef METAPHLAN3PLUGIN_H
#define METAPHLAN3PLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>

class MetaPhlAn3Plugin : public Plugin
{
public: 
 std::string toString() {return "MetaPhlAn3";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::string database;
 std::vector<std::string> samples;
};

#endif
