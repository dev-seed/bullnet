#include "stdafx.h"

XMLParser::XMLParser()
{
	m_RawDataMap.clear();
}

XMLParser::~XMLParser()
{
	m_RawDataMap.clear();
}

bool XMLParser::Init( std::string &XMLFileName, std::string &OutsideTag )
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

	BOOST_FOREACH( ptree::value_type const &Element, PropertyTree.get_child(OutsideTag) )
	{
		if ( Element.first == "item" )
		{
			RawData TempRawData;
			std::string TempKey = Element.second.get( "<xmlattr>.key" , "invalid_key" );
			if ( TempKey == "invalid_key" )
			{
				return false;
			}

			TempRawData.SetType( Element.second.get( "<xmlattr>.type" , "string") );
			TempRawData.SetValue( Element.second.get( "<xmlattr>.value" , "value" ) );

			m_RawDataMap.insert( std::map<std::string, RawData>::value_type( TempKey, TempRawData ) );
		}
	}

	return true;
}

