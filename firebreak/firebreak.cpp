#include "firebreak.h"

#define fb firebreak::firebreakBool

fb::firebreakBool() {}
void fb::addBool(bool* b) {
	boolv.push_back(b);
}
#define FORGEDBIT 8
size_t fb::getBufferSize() {
	size_t b{ boolv.size() },
		pcalc = b % FORGEDBIT;
	return (pcalc > 0 ? 1 : 0) + ((b - pcalc) / FORGEDBIT);
}

struct bbit {
	size_t pos = 0;
	firebreak::BIT bit = 0;
	void operator++() {
		bit++;
		if (bit >= 8) {
			bit = 0;
			pos++;
		}
	}
};

void writeBit(char* b, firebreak::BIT pos, bool high = true) {
	char bstr = (0x80 >> pos);
	if (high) *b |= bstr;
	else if (*b & bstr) *b ^= bstr;
}

#define readBit(b, pos) (b & (0x80 >> pos))

void bufferOp(bool read, firebreak::vbool* boolv, size_t maxsize, char* buffer) {
	bbit writingPos;
	for (size_t r{ 0 }; r < boolv->size(); r++) {
		if (writingPos.pos > maxsize) break;
		if (!read) writeBit(&(buffer[writingPos.pos]), writingPos.bit, *((*boolv)[r]));
		else *((*boolv)[r]) = readBit((buffer[writingPos.pos]), writingPos.bit);
		writingPos.operator++();
	}
}

void fb::writeToBuffer(char* buffer, size_t maxsize) {
	bufferOp(false, &boolv, maxsize, buffer);
}

void fb::readFromBuffer(char* buffer, size_t buffersize) {
	bufferOp(true, &boolv, buffersize, buffer);
}
