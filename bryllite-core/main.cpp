#include <stdio.h>

#include <string>
#include <iostream>

#include <boost/program_options.hpp>
#include <boost/program_options/errors.hpp>

#include "utils/singleton.hpp"
#include "utils/string.hpp"
#include "version.hpp"


class CServiceManager : public bryllite::Singleton<CServiceManager>
{
	friend class bryllite::Singleton<CServiceManager> ;
protected:
	CServiceManager() {};
	virtual ~CServiceManager() {};

public:
	void say_hello( void ) {
		
		hello_bryllite() ;
	};
};

int main( int argc, char** argv ) 
{
	namespace opts = boost::program_options;

	opts::options_description desc("allowed options");
	desc.add_options()
		("help,h", "usage")
		("version,v", "Version")
		("port,p", opts::value<int>()->default_value(8585), "jsonrpc port to use");

	opts::variables_map vm ;
	opts::store( opts::parse_command_line(argc, argv, desc ), vm ) ;
	opts::notify( vm ) ;

	if ( vm.count("help") ) {
		std::cout << desc << std::endl ;
		return 1 ;
	}

	if ( vm.count("version") ) {
		std::cout << "Bryllite Version: " << BRYLLITE_VERSION << std::endl ;
		return 1 ;
	}

	CServiceManager::getInstance()->say_hello() ;

	return 0 ;
}
