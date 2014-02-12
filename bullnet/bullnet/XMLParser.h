#pragma once

class RawData
{
public :
	RawData( std::string type = "", std::string value = "" ) : m_Type(type), m_Value(value) {}
	RawData( const RawData &rhs )
		: m_Type(rhs.m_Type) , m_Value(rhs.m_Value)
	{
	}
	~RawData(){}

	void	SetType(std::string type)
	{
		m_Type = type;
	}

	void	SetValue(std::string value)
	{
		m_Value = value;
	}

	const std::string & GetType()
	{
		return m_Type;
	}

	const std::string & GetValue()
	{
		return m_Value;
	}

private:
	std::string m_Type;
	std::string m_Value;
};

class XMLParser
{
public :
	XMLParser();
	~XMLParser();

	bool	Init(  std::string &XMLFileName, std::string &outSideTag );

	template<typename RefinedType>
	bool	RefineRawData( std::string &rawDataKey, RefinedType & refinedData );

	void	Done()
	{
		m_RawDataMap.clear(); 
	}

protected:

	virtual void	RefindAndRegisterKeyValue( int enumKey, std::string stringKey ) = 0;			// match string key (of RawDataMap) to enum key (of RefinedDataMap)

private :
	std::map<std::string, RawData> m_RawDataMap;
};

