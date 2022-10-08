#ifndef RESOURCE_H
#define RESOURCE_H
#include "ResourceType.h"

using namespace std;

namespace SoftUni {

	class Resource {
		int id = -1;
		ResourceType type = ResourceType::DEMO;
		string link = "";

	public:

		int getID() const { return id; }
		const string& getLink() const { return link; }
		ResourceType getType() const { return type; }

		bool operator < (const Resource& other) const
		{
			return id < other.id;
		}

		friend istream& operator >> (istream& str, Resource& r);
		//friend ostream& operator << (ostream& ostr, const Resource& r);

	};

	istream& operator >> (istream& str, Resource& r)
	{
		string strType;
		str >> r.id >> strType >> r.link;

		if (strType == "Demo")
		{
			r.type = ResourceType::DEMO;
		}
		else if (strType == "Presentation")
		{
			r.type = ResourceType::PRESENTATION;
		}
		else if (strType == "Video")
		{
			r.type = ResourceType::VIDEO;
		}


		return str;
	}

	ostream& operator << (ostream& ostr, const Resource& r)
	{
		ostr << r.getID() << " " << r.getType() << " " << r.getLink();


		return ostr;
	}


};


#endif