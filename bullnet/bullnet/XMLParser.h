#pragma once

class RawData
{
public :
	RawData( std::string type = "", std::string value = "" ) : m_Type(type), m_Value(value) {}
	RawData( RawData &rhs )
	{
		m_Type = rhs.GetType();
		m_Value = rhs.GetValue();
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
