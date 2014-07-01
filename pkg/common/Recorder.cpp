// 2009 © Václav Šmilauer <eudoxos@arcig.cz>
#include<yade/pkg/common/Recorder.hpp>
YADE_PLUGIN((Recorder));

Recorder::~Recorder(){}
void Recorder::openAndCheck(){
	assert(!out.is_open());
	
	std::string fileTemp = file;
	if (addIterNum) fileTemp+="-" + boost::lexical_cast<string>(scene->iter);
	
	if(fileTemp.empty()) throw std::ios_base::failure(__FILE__ ": Empty filename.");
	out.open(fileTemp.c_str(), truncate ? std::fstream::trunc : std::fstream::app);
	if(!out.good()) throw std::ios_base::failure(__FILE__ ": I/O error opening file `"+fileTemp+"'.");
}
