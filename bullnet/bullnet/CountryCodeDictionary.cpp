#include "stdafx.h"

CountryCodeDictionary::CountryCodeDictionary()
{
	m_CountryCodeMap.clear();
}

CountryCodeDictionary::~CountryCodeDictionary()
{
	m_CountryCodeMap.clear();
}

bool CountryCodeDictionary::Init( std::string &XMLFileName, std::string &outSideTag )
{
	XMLParser::Init( XMLFileName, outSideTag );

	RefindAndRegisterKeyValue( COUNTRYCODE_KOREA , "korea" );
	RefindAndRegisterKeyValue( COUNTRYCODE_JAPAN , "japan" );

	Done();

	return true;
}

void CountryCodeDictionary::RefindAndRegisterKeyValue( int enumKey, std::string stringKey )
{
	int countryCode = -1;

	if ( !RefineRawData<int>( stringKey, countryCode ) )
	{
		assert(false);

		return;
	}

	m_CountryCodeMap.insert( std::map<COUNTRYCODE, CountryCode>::value_type( (COUNTRYCODE)enumKey, CountryCode(countryCode) ) );
}