#include "stdafx.h"

CountryCodeDictionary::CountryCodeDictionary()
{
	m_CountryCodeMap.clear();
}

CountryCodeDictionary::~CountryCodeDictionary()
{
	m_CountryCodeMap.clear();
}

bool CountryCodeDictionary::Init( std::string &XMLFileName, std::string &OutsideTag )
{
	XMLParser::Init( XMLFileName, OutsideTag );

	RegisterKeyValue( COUNTRYCODE::KOREA, "korea" );
	RegisterKeyValue( COUNTRYCODE::JAPAN, "japan" );

	Done();

	return true;
}

void CountryCodeDictionary::RegisterKeyValue( int EnumKey, std::string StringKey )
{
	int TempCountryCode = -1;

	RefineRawData<int>( StringKey, TempCountryCode );

	m_CountryCodeMap.insert( std::map<int, CountryCode>::value_type( EnumKey, CountryCode(TempCountryCode) ) );
}