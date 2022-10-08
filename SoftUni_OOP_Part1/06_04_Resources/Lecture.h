#ifndef LECTURE_H
#define LECTURE_H

#include "ResourceType.h"
#include "Resource.h"

#include <map>
#include <set>
#include <vector>
using namespace std;

namespace SoftUni {

	class Lecture {
	public:

		typedef  set<Resource> ResourceMap;
		typedef  map<ResourceType, size_t > ResourceTypes;

	private:


		ResourceMap res;
		ResourceTypes resTypes;
	public:
		Lecture& operator << (const Resource& r)
		{
			ResourceMap::iterator itExisting = res.find(r);
			if (itExisting == res.end()) //// the element does not exist
			{
				resTypes[r.getType()]--;
				if (resTypes[r.getType()] == 0)
				{
					resTypes.erase(r.getType());
				}
				res.erase(r);
			}
			


			res.insert(r);
			resTypes[r.getType()]++;
			return *this;
		}

		int operator[](ResourceType rType) const
		{
			ResourceTypes::const_iterator itRt = resTypes.find(rType);
			if (itRt == resTypes.end())
			{
				return 0;
			}
			else
			{
				return itRt -> second;
			}

		}

		ResourceMap::iterator begin(void) { return res.cbegin(); }
		ResourceMap::iterator end(void) { return res.cend(); }

		const ResourceTypes getResourceTypes(void) const { return resTypes; }

	};

	
	void operator << (std::vector<ResourceType>& vec, Lecture& l)
	{
		set<ResourceType> rt;

		for (auto r : l.getResourceTypes())
		{
			rt.insert(r.first);

		}
	}
		
		

};


#endif
