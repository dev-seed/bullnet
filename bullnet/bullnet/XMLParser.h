#pragma once

class RawData
{
public :
	RawData( std::string Type, std::string Value ) : m_Type(Type), m_Value(m_Value) {}
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

	bool	Init(  std::string XMLFileName, std::string OutsideTag );
	
protected:

	virtual void	RegisterKeyValue() = 0;

private :
	std::map<std::string, RawData> m_RawDataMap;
};