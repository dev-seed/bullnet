#include "stdafx.h"
#include "XMLParser.h"

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

			rawData.SetType( element.second.get( "<xmlattr>.type" , "invalid_type") );
			rawData.SetValue( element.second.get( "<xmlattr>.value" , "invalid_value" ) );

			if ( rawData.GetType() == "invalid_type" || rawData.GetValue() == "invalid_value" )
			{
				return false;
			}

			m_RawDataMap.insert( std::map<std::string, RawData>::value_type( key, rawData ) );
		}
	}

	return true;
}

template<typename RefinedType>
bool XMLParser::RefineRawData( std::string &rawDataKey, RefinedType & refinedData )
{
	auto iter_ = m_RawDataMap.find(rawDataKey);
	if ( iter_ == m_RawDataMap.end() )
	{
		return false;
	}

	RawData rawDataToRefine = iter_->second;

	std::string rawDataType = rawDataToRefine.GetType();
	std::string rawDataValue = rawDataToRefine.GetValue();

	if ( typeid(RefinedType) == typeid(std::string) && rawDataType == "string" )
	{
		try
		{
			refinedData = boost::lexical_cast<RefinedType>(rawDataValue);
		}
		catch (boost::bad_lexical_cast)
		{
			// bad lexical

			return false;
		}
	}
	else if ( typeid(RefinedType) == typeid(int) && rawDataType == "int" )
	{
		try
		{
			refinedData = boost::lexical_cast<RefinedType>(rawDataValue);
		}
		catch (boost::bad_lexical_cast)
		{
			// bad lexical

			return false;
		}
	}
	else if ( typeid(RefinedType) == typeid(float) && rawDataType == "float" )
	{
		try
		{
			refinedData = boost::lexical_cast<RefinedType>(rawDataValue);
		}
		catch (boost::bad_lexical_cast)
		{
			// bad lexical

			return false;
		}
	}
	else if ( typeid(RefinedType) == typeid(double) && rawDataType == "double" )
	{
		try
		{
			refinedData = boost::lexical_cast<RefinedType>(rawDataValue);
		}
		catch (boost::bad_lexical_cast)
		{
			// bad lexical

			return false;
		}
	}
	else
	{
		// undefined type

		return false;
	}

	return true;
}
