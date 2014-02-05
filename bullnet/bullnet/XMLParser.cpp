#include "stdafx.h"

XMLParser::XMLParser()
{
	m_RawDataMap.clear();
}

XMLParser::~XMLParser()
{
	m_RawDataMap.clear();
}

bool XMLParser::Init( std::string XMLFileName, std::string OutsideTag )
{
	std::ifstream InputStream;

	InputStream.open(XMLFileName.c_str());
	if ( !InputStream.is_open() )
	{
		return false;
	}

	using boost::property_tree::ptree;

	ptree PropertyTree;
	read_xml(InputStream, PropertyTree);


}

