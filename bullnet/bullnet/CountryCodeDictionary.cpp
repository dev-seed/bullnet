#include "stdafx.h"

CountryCodeDictionary::CountryCodeDictionary()
{
	m_CountryCodeMap.clear();
}

CountryCodeDictionary::~CountryCodeDictionary()
{
	m_CountryCodeMap.clear();
}

bool CountryCodeDictionary::Init( std::string XMLFileName, std::string outSideTag )
{
	if( !XMLParser::Init( XMLFileName, outSideTag ) )
	{
		assert(false);
	}

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
	}

	m_CountryCodeMap.insert( std::map<COUNTRYCODE, CountryCode>::value_type( (COUNTRYCODE)enumKey, CountryCode(countryCode) ) );
}

const CountryCode CountryCodeDictionary::GetCountryCode( COUNTRYCODE key )
{
	auto iter_ = m_CountryCodeMap.find(key);

	if ( iter_ != m_CountryCodeMap.end() )
	{
		return iter_->second;
	}
	else
	{
		return CountryCode();
	}
}
