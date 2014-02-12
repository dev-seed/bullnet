#pragma once

class LocalizedTextDictionary : public XMLParser
{
public :
	LocalizedTextDictionary();
	~LocalizedTextDictionary();

	bool Init( std::string XMLFileName, std::string outsideTag );

	const std::string GetLocalizedText( LOCALIZEDTEXTKEY key );

protected:

	void RefindAndRegisterKeyValue( int enumKey, std::string stringKey );

private :
	std::map<LOCALIZEDTEXTKEY, std::string> m_LocalizedTextMap;
};