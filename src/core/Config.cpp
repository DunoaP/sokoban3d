#include "Config.h"

unsigned int Config::_WINDOWWIDTH = 640;
unsigned int Config::_WINDOWHEIGHT = 480;
bool	     Config::_FULLSCREEN = false;
unsigned int Config::_ANTIALIASING = 0;
bool	     Config::_VSYNC = false;
float        Config::_MASTER_VOL = 1.0;
    

Config::Config(){
}

Config::~Config(){

}


void Config::map(std::map<std::string, std::string> m) {
    //visuals
    _WINDOWWIDTH = atoi(m["width"].c_str());
    _WINDOWHEIGHT = atoi(m["height"].c_str());
    _FULLSCREEN = (atoi(m["fullscreen"].c_str())) != 0;
    _ANTIALIASING = atoi(m["antialiasing"].c_str());
    _VSYNC = (atoi(m["vsync"].c_str())) != 0;

    //audio
    _MASTER_VOL = (float)atof(m["master_volume"].c_str());
}

bool Config::load() {
    std::map<std::string, std::string> m;
    std::ifstream f;
    std::string d, holder;
    f.open( "data/core/base.cfg" );
    if( f.is_open() )
    {
	while( f >> holder )
	{
            if( ( holder == "#" ) || ( holder == "g" ) ) {
		getline(f , d , '\n' );
	    } else {
		f >> d;
		m[holder] = d;
	    }
	}
	f.close();
    } else {
	return false;
    }
    map(m);
    
    return true;
}
