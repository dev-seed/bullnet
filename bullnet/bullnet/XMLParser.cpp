#include "stdafx.h"

XMLParser::XMLParser()
{
	m_RawDataMap.clear();
}

XMLParser::~XMLParser()
{
	m_RawDataMap.clear();
}

bool XMLParser::Init( std::string &XMLFileName, std::string &outSideTag )
{
	std::ifstream inputStream;

	inputStream.open(XMLFileName.c_str());
	if ( !inputStream.is_open() )
	{
		return false;
	}

	using boost::property_tree::ptree;

	ptree propertyTree;
	read_xml(inputStream, propertyTree);

	BOOST_FOREACH( ptree::value_type const &element, propertyTree.get_child(outSideTag) )
	{
		if ( element.first == "item" )
		{
			RawData rawData;
			std::string key = element.second.get( "<xmlattr>.key" , "invalid_key" );
			if ( key == "invalid_key" )
			{
				return false;
			}

			rawData.SetType( element.second.get( "<xmlattr>.type" , "string") );
			rawData.SetValue( element.second.get( "<xmlattr>.value" , "value" ) );

			m_RawDataMap.insert( std::map<std::string, RawData>::value_type( key, rawData ) );
		}
	}

	return true;
}

