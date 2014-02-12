#include "stdafx.h"


LocalizedCode::LocalizedCode()
	: m_LocalizedCodeValue(0)
{

}

LocalizedCode::~LocalizedCode()
{

}

bool LocalizedCode::Init( std::string XMLFileName, std::string outsideTag )
{
	if ( !XMLParser::Init(XMLFileName, outsideTag) )
	{
		assert(false);
	}

	int localizedCodeValue = 0;
	std::string key("target");

	if ( !RefineRawData<int>( key, localizedCodeValue) )
	{
		assert(false);
	}

	m_LocalizedCodeValue = localizedCodeValue;

	return true;
}

const LocalizedCodeValue & LocalizedCode::GetLocalizedCode()
{
	return m_LocalizedCodeValue;
}