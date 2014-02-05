#pragma once

class CountryCode
{
public:
	CountryCode( int CountryCode = -1 ) : m_CountryCode(CountryCode) {}
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

	bool Init(  std::string &XMLFileName, std::string &OutsideTag );

protected:

	void RegisterKeyValue( int EnumKey, std::string StringKey );

private:
	std::map<int, CountryCode> m_CountryCodeMap;
};