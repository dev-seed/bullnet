#pragma once

class CountryCode
{
public:
	CountryCode( int CountryCode = -1 ) : m_CountryCode(CountryCode) {}
	CountryCode( const CountryCode& rhs )
		: m_CountryCode(rhs.m_CountryCode)
	{
	}

	~CountryCode(){}

	void SetcCountryCode( int CountryCode )
	{
		m_CountryCode = CountryCode;
	}

	int	GetCountryCode()
	{
		return m_CountryCode;
	}

private:
	int m_CountryCode;
};

class CountryCodeDictionary : public XMLParser
{
public:
	CountryCodeDictionary();
	~CountryCodeDictionary();

	bool Init(  std::string XMLFileName, std::string outsideTag );

	const CountryCode GetCountryCode( COUNTRYCODE key );

protected:

	void RefindAndRegisterKeyValue( int enumKey, std::string stringKey );

private:
	std::map<COUNTRYCODE, CountryCode> m_CountryCodeMap;
};