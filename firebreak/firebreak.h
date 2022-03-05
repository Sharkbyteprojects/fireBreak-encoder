#pragma once
#ifndef vectori
#include <vector>
#define vectori
#endif
namespace firebreak {
	typedef std::vector<bool*> vbool;
	typedef size_t BIT;
	class firebreakBool {
	private:
		vbool boolv;
	public:
		firebreakBool();
		void addBool(bool* booltoadd);
		size_t getBufferSize();
		void writeToBuffer(char* buffer, size_t maxsize);
		void readFromBuffer(char* buffer, size_t buffersize);
	};
}
