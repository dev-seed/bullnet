#include "stdafx.h"


LocalizedTextDictionary::LocalizedTextDictionary()
{
	m_LocalizedTextMap.clear();
}

LocalizedTextDictionary::~LocalizedTextDictionary()
{
	m_LocalizedTextMap.clear();
}

bool LocalizedTextDictionary::Init( std::string XMLFileName, std::string outsideTag )
{
	if ( !XMLParser::Init(XMLFileName, outsideTag) )
	{
		assert(false);
	}

	RefindAndRegisterKeyValue( LOCALIZEDTEXTKEY_MENU, "menu" );

	Done();

	return true;
}

const std::string LocalizedTextDictionary::GetLocalizedText( LOCALIZEDTEXTKEY key )
{
	auto iter_ = m_LocalizedTextMap.find(key);

	if ( iter_ != m_LocalizedTextMap.end() )
	{
		return iter_->second;
	}
	else
	{
		return "";
	}
}

void LocalizedTextDictionary::RefindAndRegisterKeyValue( int enumKey, std::string stringKey )
{
	std::string localizedText;
	if ( !RefineRawData<std::string>( stringKey, localizedText ) )
	{
		assert(false);
	}

	m_LocalizedTextMap.insert( std::map<LOCALIZEDTEXTKEY, std::string>::value_type( (LOCALIZEDTEXTKEY)enumKey, localizedText ) );
}