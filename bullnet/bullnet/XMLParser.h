#pragma once

class RawData
{
public :
	RawData( std::string Type = "", std::string Value = "" ) : m_Type(Type), m_Value(m_Value) {}
	RawData( RawData &rhs )
	{
		m_Type = rhs.GetType();
		m_Value = rhs.GetValue();
	}
	~RawData(){}

	void	SetType(std::string Type)
	{
		m_Type = Type;
	}

	void	SetValue(std::string Value)
	{
		m_Value = Value;
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

	bool	Init(  std::string &XMLFileName, std::string &OutsideTag );

	template<class T>
	bool	RefineRawData( std::string &RawDataKey, T & RefinedData );

	void	Done()
	{
		m_RawDataMap.clear(); 
	}

protected:

	virtual void	RegisterKeyValue( int EnumKey, std::string StringKey ) = 0;			// match string key (of RawDataMap) to enum key (of RefinedDataMap)

private :
	std::map<std::string, RawData> m_RawDataMap;
};


template<class T>
bool XMLParser::RefineRawData( std::string &RawDataKey, T & RefinedData )
{
	auto Iter = m_RawDataMap.find(RawDataKey);
	if ( Iter == m_RawDataMap.end() )
	{
		return false;
	}

	RawData RawDataToRefine = Iter->second;

	std::string RawDataType = RawDataToRefine.GetType();
	std::string RawDataValue = RawDataToRefine.GetValue();
	if ( RawDataType == "string" )
	{
		// in case of string, no need to refine
		RefinedData = RawDataValue;
	}
	else if ( RawDataType == "int" )
	{
		try
		{
			RefinedData = boost::lexical_cast<int>(RawDataValue);
		}
		catch (boost::bad_lexical_cast)
		{
			// bad lexical

			return false;
		}
	}
	else if ( RawDataType == "float" )
	{
		try
		{
			RefinedData = boost::lexical_cast<float>(RawDataValue);
		}
		catch (boost::bad_lexical_cast)
		{
			// bad lexical

			return false;
		}
	}
	else if ( RawDataType == "double" )
	{
		try
		{
			RefinedData = boost::lexical_cast<double>(RawDataValue);
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